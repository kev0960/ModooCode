use std::sync::{Arc, Mutex};

use async_trait::async_trait;
use dojang::Dojang;
use serde_json::Value;

use crate::error::errors::ServerError;

type Etag = i64;

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

    pub async fn render_page(&mut self) -> Result<String, ServerError> {
        let caches = self.fetch_caches().await?;

        // If all values are cacheable, then check the page cache.
        let is_all_cacheable = caches.iter().any(|cache| {
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

            template_context.insert(self.top_level_inputs[index].input_name().to_owned(), value);
        }

        println!("Template context : {:?}", template_context);
        println!("Template context val : {:?}", serde_json::to_value(template_context.clone()));
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
            self.rendered_page_cache.put(etags, rendered_page);
        }

        Ok("".to_owned())
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
