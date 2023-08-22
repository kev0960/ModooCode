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
            let child_categories = metadata
                .child_categories
                .iter()
                .map(|child_category_name| {
                    let mut full_path = metadata.category_full_path.clone();
                    full_path.push(child_category_name.to_owned());
                    full_path
                })
                .filter_map(|child_category_full_path| {
                    article_context.get_category_metadata(&child_category_full_path)
                })
                .collect::<Vec<_>>();

            category_page_renderer.insert(
                format!(
                    "/category/{}",
                    metadata
                        .category_full_path
                        .iter()
                        .map(|s| s.trim())
                        .collect::<Vec<_>>()
                        .join("/")
                ),
                PageRenderer::new(
                    "category",
                    vec![
                        /* Static values */
                        Box::new(PageHeaderCategory::new(&page_path_json)),
                        Box::new(SubcategoryListingInput::new(
                            &child_categories,
                            &article_context,
                        )),
                        Box::new(CategoryMetadataInput::new(&metadata)),
                        Box::new(CategoryPathInput::new(&metadata)),
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

struct CategoryPathInput {
    category_path: Value,
}

impl StaticTopLevelPageInput for CategoryPathInput {
    fn static_input_name(&self) -> &'static str {
        "category_path"
    }

    fn static_input(&self) -> Value {
        self.category_path.clone()
    }
}

impl CategoryPathInput {
    fn new(category_metadata: &CategoryMetadata) -> Self {
        Self {
            category_path: serde_json::Value::String(
                category_metadata.category_full_path.join(" &gt "),
            ),
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
                r#"
<div class="category-article-entry">
    <p class="category-article-info">
        <span class="publish-date">{}</span> <span class="view-cnt">조회수 : {}</span>
    </p>
    <a class="category-article-header" href="/{}">{}</a>
</div>"#,
                article.publish_date,
                view_count.unwrap_or_default(),
                article.article_url,
                html_escape::encode_safe(&article.title)
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

struct SubcategoryListingInput {
    sub_categories: Value,
}

impl StaticTopLevelPageInput for SubcategoryListingInput {
    fn static_input_name(&self) -> &'static str {
        "sub_categories"
    }

    fn static_input(&self) -> Value {
        self.sub_categories.clone()
    }
}

impl SubcategoryListingInput {
    fn child_category_article_listing(
        child_category: &CategoryMetadata,
        article_context: &Arc<dyn ArticleContext>,
    ) -> String {
        let mut html = String::new();
        for file in child_category.files.iter().take(3) {
            let mut article = article_context.multi_get_article_metadata(&[file.to_owned()]);
            let article = article.pop().unwrap().unwrap();

            html += &format!(
                r#"
            <p><a class="category-article-header" href="/{}">{}</a></p>
            "#,
                article.article_url, article.title
            );
        }

        if child_category.files.len() > 3 {
            html += &format!(
                r#"<p>... 외 <a href="/category/{}">{} 개의 글</a>들이 있습니다.</p>"#,
                child_category.category_full_path.join("/"),
                child_category.files.len() - 3
            );
        }

        html
    }

    fn new(
        sub_categories: &[&CategoryMetadata],
        article_context: &Arc<dyn ArticleContext>,
    ) -> Self {
        let mut html = String::new();
        for category in sub_categories {
            html += &format!(
                r#"<div>
                    <h3 class="child-category-header">
                        §  <a href="/category/{}">{}</a>
                    </h3>
                    <div class="child-category-article-listing">
                        {}
                    </div>
                   </div>"#,
                category.category_full_path.join("/"),
                html_escape::encode_safe(&category.category_name),
                Self::child_category_article_listing(category, article_context)
            );
        }

        Self {
            sub_categories: serde_json::Value::String(html),
        }
    }
}
