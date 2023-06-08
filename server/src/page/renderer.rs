use std::sync::{Arc, Mutex};

use async_trait::async_trait;
use dojang::Dojang;
use serde_json::Value;

use crate::error::errors::ServerError;

type Etag = i64;

#[derive(Debug, Clone)]
pub enum InputValue {
    NonCacheable(Value),
    Cacheable(Value, Etag),
}

#[async_trait]
pub trait TopLevelPageInput
where
    Self: Send + Sync,
{
    // Top level field 이름.
    fn input_name(&self) -> &'static str;

    // 현재 Value 를 얻는다.
    async fn get_input_value(&self) -> Result<InputValue, ServerError>;
}

pub trait RequestScopedInputs
where
    Self: Send + Sync,
{
    // Top level field 이름들과 현재 value 들을 얻는다.
    fn get_input_valuess(&self) -> Result<Vec<(String, InputValue)>, ServerError>;
}

// 만약에 TopLevelInput 이 그냥 static 데이터를 리턴하는 경우 간단히 사용할 수 있는 trait.
pub trait StaticTopLevelPageInput {
    fn static_input_name(&self) -> &'static str;

    fn static_input(&self) -> Value;
}

#[async_trait]
impl<T> TopLevelPageInput for T
where
    T: StaticTopLevelPageInput + Send + Sync,
{
    // Top level field 이름.
    fn input_name(&self) -> &'static str {
        self.static_input_name()
    }

    // 현재 Value 를 얻는다.
    async fn get_input_value(&self) -> Result<InputValue, ServerError> {
        Ok(InputValue::Cacheable(self.static_input(), /*etag=*/ 0))
    }
}

pub struct PageRenderer {
    template_file_name: String,
    top_level_inputs: Vec<Box<dyn TopLevelPageInput>>,
    rendered_page_cache: lru::LruCache<Vec<Etag>, String>,
    dojang: Arc<Mutex<Dojang>>,
}

impl PageRenderer {
    pub fn new(
        template_file_name: &str,
        top_level_inputs: Vec<Box<dyn TopLevelPageInput>>,
        cache_size: usize,
        dojang: Arc<Mutex<Dojang>>,
    ) -> Self {
        PageRenderer {
            template_file_name: template_file_name.to_owned(),
            top_level_inputs,
            rendered_page_cache: lru::LruCache::new(
                std::num::NonZeroUsize::new(cache_size).unwrap(),
            ),
            dojang,
        }
    }

    pub async fn render_page(
        &mut self,
        request_scoped_inputs: Arc<dyn RequestScopedInputs>,
    ) -> Result<String, ServerError> {
        let mut caches = self.fetch_caches().await?;

        let request_scoped_inputs = request_scoped_inputs.get_input_valuess()?;
        caches.append(
            &mut request_scoped_inputs
                .iter()
                .map(|(_, input)| input.to_owned())
                .collect::<Vec<_>>(),
        );

        // If all values are cacheable, then check the page cache.
        let is_all_cacheable = caches.iter().all(|cache| {
            if let InputValue::Cacheable(_, _) = cache {
                true
            } else {
                false
            }
        });

        let etags = caches
            .iter()
            .map(|cache| match cache {
                InputValue::Cacheable(_, etag) => *etag,
                _ => 0,
            })
            .collect::<Vec<i64>>();

        if is_all_cacheable {
            if let Some(cached_page) = self.rendered_page_cache.get(&etags) {
                return Ok(cached_page.clone());
            }
        }

        let mut template_context = serde_json::Map::new();
        for (index, cache) in caches.into_iter().enumerate() {
            let value = match cache {
                InputValue::NonCacheable(v) => v,
                InputValue::Cacheable(v, _) => v,
            };

            if index < self.top_level_inputs.len() {
                template_context
                    .insert(self.top_level_inputs[index].input_name().to_owned(), value);
            } else {
                template_context.insert(
                    request_scoped_inputs
                        .get(index - self.top_level_inputs.len())
                        .unwrap()
                        .0
                        .to_owned(),
                    value,
                );
            }
        }

        let rendered_page = self
            .dojang
            .lock()
            .unwrap()
            .render(
                &self.template_file_name,
                serde_json::to_value(template_context)?,
            )
            .map_err(|err| ServerError::Internal(err))?;

        if is_all_cacheable {
            self.rendered_page_cache.put(etags, rendered_page.clone());
        }

        Ok(rendered_page)
    }

    async fn fetch_caches(&self) -> Result<Vec<InputValue>, ServerError> {
        let caches = self
            .top_level_inputs
            .iter()
            .map(|input| input.get_input_value());

        let caches = futures::future::join_all(caches).await;

        let mut input_values = Vec::new();
        input_values.reserve(caches.len());

        for cache in caches {
            if !cache.is_ok() {
                return Err(cache.err().unwrap());
            }

            input_values.push(cache.unwrap())
        }

        Ok(input_values)
    }
}
