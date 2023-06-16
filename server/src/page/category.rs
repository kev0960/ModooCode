use std::collections::{HashMap, HashSet};
use std::sync::{Arc, Mutex};

use super::page::PageRendererContext;
use super::page_header_category::create_page_header_category_list;
use super::renderer::{
    InputValue, PageRenderer, RequestScopedInputs, StaticTopLevelPageInput, TopLevelPageInput,
};
use crate::context::article_context::{ArticleContext, ArticleMetadata, CategoryMetadata};
use crate::error::errors::ServerError;
use async_trait::async_trait;
use dojang::Dojang;
use serde_json::Value;

pub struct CategoryPageRendererContext {
    category_page_renderer: HashMap<String, PageRenderer>,
}

impl CategoryPageRendererContext {
    pub fn new(
        dojang: Arc<Mutex<Dojang>>,
        article_context: Arc<dyn ArticleContext>,
        page_path_json_path: &str,
    ) -> Self {
        let page_path_json = std::fs::read_to_string(page_path_json_path).unwrap();

        let mut category_page_renderer = HashMap::new();
        for metadata in article_context.get_every_category_metadata() {
            category_page_renderer.insert(
                format!("/category/{}", metadata.category_name),
                PageRenderer::new(
                    "new_page",
                    vec![
                        /* Static values */
                        Box::new(PageHeaderCategory::new(&page_path_json)),
                        Box::new(CategoryMetadataInput::new(&metadata)),
                        Box::new(CategoryArticleListing::new(
                            &metadata,
                            article_context.clone(),
                        )),
                    ],
                    1,
                    dojang.clone(),
                ),
            );
        }

        Self {
            category_page_renderer,
        }
    }
}

#[async_trait]
impl PageRendererContext for CategoryPageRendererContext {
    fn get_matching_pages(&self) -> std::collections::HashSet<String> {
        HashSet::from_iter(self.category_page_renderer.keys().map(|s| s.clone()))
    }

    async fn render_page(
        &mut self,
        category_name: &str,
        request_scoped_inputs: Arc<dyn RequestScopedInputs>,
    ) -> Result<String, ServerError> {
        if let Some(page_renderer) = self.category_page_renderer.get_mut(category_name) {
            Ok(page_renderer.render_page(request_scoped_inputs).await?)
        } else {
            Err(ServerError::BadRequest("Page is not found.".to_owned()))
        }
    }
}

struct PageHeaderCategory {
    page_header_category: Value,
}

impl StaticTopLevelPageInput for PageHeaderCategory {
    fn static_input_name(&self) -> &'static str {
        "page_header_category"
    }

    fn static_input(&self) -> Value {
        self.page_header_category.clone()
    }
}

impl PageHeaderCategory {
    fn new(page_infos_json: &str) -> Self {
        Self {
            page_header_category: serde_json::Value::String(create_page_header_category_list(
                page_infos_json,
            )),
        }
    }
}

struct CategoryMetadataInput {
    category_metadata: Value,
}

impl StaticTopLevelPageInput for CategoryMetadataInput {
    fn static_input_name(&self) -> &'static str {
        "category_metadata"
    }

    fn static_input(&self) -> Value {
        self.category_metadata.clone()
    }
}

impl CategoryMetadataInput {
    fn new(category_metadata: &CategoryMetadata) -> Self {
        Self {
            category_metadata: serde_json::to_value(category_metadata).unwrap(),
        }
    }
}

struct CategoryArticleListing {
    article_context: Arc<dyn ArticleContext>,
    articles: Vec<ArticleMetadata>,
}

#[async_trait]
impl TopLevelPageInput for CategoryArticleListing {
    fn input_name(&self) -> &'static str {
        "category_articles"
    }

    async fn get_input_value(&self) -> Result<InputValue, ServerError> {
        let view_counts = self.article_context.get_page_view_counts(
            &self
                .articles
                .iter()
                .map(|m| m.article_url.clone())
                .collect::<Vec<String>>(),
        );

        let mut html = String::new();
        for (article, view_count) in self.articles.iter().zip(view_counts) {
            html += &format!(
                r#"<div class="category-article-entry"><p class="category-article-info"><span class="publish-date">{}</span> <span class="view-cnt">조회수 : </span></p><a class="category-article-header" href="{}">{}</a></div>"#,
                view_count.unwrap_or_default(),
                article.article_url,
                article.title
            );
        }

        Ok(InputValue::NonCacheable(Value::String(html)))
    }
}

impl CategoryArticleListing {
    fn new(category_metadata: &CategoryMetadata, article_context: Arc<dyn ArticleContext>) -> Self {
        let articles = article_context
            .multi_get_article_metadata(&category_metadata.files)
            .into_iter()
            .filter_map(|a| a)
            .collect::<Vec<_>>();

        Self {
            articles,
            article_context,
        }
    }
}
