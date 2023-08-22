use std::cmp::min;
use std::collections::{HashMap, HashSet};
use std::sync::{Arc, Mutex, RwLock};

use async_trait::async_trait;
use dojang::Dojang;
use serde_json::{to_value, Value};

use super::page::PageRendererContext;
use super::page_header_category::create_page_header_category_list;
use super::renderer::{
    InputValue, PageRenderer, RequestScopedInputs, StaticTopLevelPageInput, TopLevelPageInput,
};
use crate::context::article_context::{ArticleContext, ArticleMetadata, CategoryMetadata};
use crate::context::comment_context::{CommentContext, CommentData};
use crate::error::errors::ServerError;
use crate::page::comment_html::create_comment_list_html;

pub struct ArticlePageRendererContext {
    article_page_renderer: HashMap<String, PageRenderer>,
}

impl ArticlePageRendererContext {
    pub fn new(
        dojang: Arc<Mutex<Dojang>>,
        comment_context: Arc<dyn CommentContext>,
        article_context: Arc<dyn ArticleContext>,
        page_path_json_path: &str,
    ) -> Self {
        let article_metdatas = article_context.get_every_article_metadata();

        let page_path_json = std::fs::read_to_string(page_path_json_path).unwrap();

        let mut article_page_renderer = HashMap::new();
        for metadata in &article_metdatas {
            article_page_renderer.insert(
                metadata.article_url.clone(),
                PageRenderer::new(
                    "new_page",
                    vec![
                        Box::new(NumCommentsInArticle::new(
                            comment_context.clone(),
                            &metadata.article_url,
                        )),
                        Box::new(ArticleViewCount::new(
                            article_context.clone(),
                            &metadata.article_url,
                        )),
                        /* Static values */
                        Box::new(ArticleFileInfo::new(metadata.clone())),
                        Box::new(ArticlesInCategoryContext::new(
                            article_context.clone(),
                            &metadata.article_url,
                        )),
                        Box::new(AllArticleMetadata::new(&article_metdatas)),
                        Box::new(ArticleContentUrl::new(&metadata.article_url)),
                        Box::new(PageInfos::new(&page_path_json)),
                        Box::new(PageHeaderCategory::new(&page_path_json)),
                    ],
                    1,
                    dojang.clone(),
                ),
            );
        }

        Self {
            article_page_renderer,
        }
    }
}

#[async_trait]
impl PageRendererContext for ArticlePageRendererContext {
    fn get_matching_pages(&self) -> std::collections::HashSet<String> {
        HashSet::from_iter(self.article_page_renderer.keys().map(|s| s.clone()))
    }

    async fn render_page(
        &mut self,
        article_url: &str,
        request_scoped_inputs: Arc<dyn RequestScopedInputs>,
    ) -> Result<String, ServerError> {
        if let Some(page_renderer) = self.article_page_renderer.get_mut(article_url) {
            Ok(page_renderer.render_page(request_scoped_inputs).await?)
        } else {
            Err(ServerError::BadRequest("Page is not found.".to_owned()))
        }
    }
}

struct ArticleViewCount {
    article_context: Arc<dyn ArticleContext>,
    article_url: String,
}

impl ArticleViewCount {
    pub fn new(article_context: Arc<dyn ArticleContext>, article_url: &str) -> Self {
        Self {
            article_context,
            article_url: article_url.to_owned(),
        }
    }
}

#[async_trait]
impl TopLevelPageInput for ArticleViewCount {
    fn input_name(&self) -> &'static str {
        "view_cnt"
    }

    async fn get_input_value(&self) -> Result<InputValue, ServerError> {
        Ok(InputValue::NonCacheable(Value::from(
            self.article_context
                .increment_page_view_count(&self.article_url),
        )))
    }
}

struct ArticlesInCategoryContext {
    article_metadatas: Vec<ArticleMetadata>,
    category_metadata: CategoryMetadata,
    current_article_url: String,

    has_more_article_above: bool,
    has_more_article_below: bool,
}

impl ArticlesInCategoryContext {
    pub fn new(article_context: Arc<dyn ArticleContext>, article_url: &str) -> Self {
        let category_containing_article = article_context
            .get_category_that_article_belongs(article_url)
            .unwrap();
        let category_metadata = article_context
            .get_category_metadata(&category_containing_article.category_full_path)
            .unwrap();

        let index_of_current_article = category_metadata
            .files
            .iter()
            .position(|id| article_url == id)
            .unwrap() as i32;

        let mut article_urls_to_fetch = Vec::new();
        for i in (std::cmp::max(0, index_of_current_article - 3))..index_of_current_article {
            article_urls_to_fetch.push(category_metadata.files[i as usize].to_owned());
        }
        article_urls_to_fetch.push(article_url.to_owned());

        let mut current_index = index_of_current_article + 1;
        while article_urls_to_fetch.len() < 7
            && current_index < category_metadata.files.len() as i32
        {
            article_urls_to_fetch.push(category_metadata.files[current_index as usize].to_owned());
            current_index += 1;
        }

        let article_metadatas = article_context
            .multi_get_article_metadata(&article_urls_to_fetch)
            .into_iter()
            .filter_map(|e| e)
            .collect::<Vec<_>>();

        Self {
            article_metadatas,
            category_metadata: category_metadata.clone(),
            current_article_url: article_url.to_owned(),
            has_more_article_above: index_of_current_article > 3,
            has_more_article_below: index_of_current_article + 3
                < category_metadata.files.len() as i32,
        }
    }
}

#[async_trait]
impl TopLevelPageInput for ArticlesInCategoryContext {
    fn input_name(&self) -> &'static str {
        "articles_in_category"
    }

    async fn get_input_value(&self) -> Result<InputValue, ServerError> {
        let mut article_list_html = String::new();

        for article in &self.article_metadatas {
            let current_article_marker = if article.article_url == self.current_article_url {
                "current-article-sidebar-elem"
            } else {
                ""
            };

            if article.category_title.is_empty() {
                article_list_html += &format!(
                    "<li class='sidebar-category-elem {}'><a href='{}'>{}</a></li>",
                    current_article_marker, article.article_url, article.title
                );
            } else {
                article_list_html += &format!(
                    "<li class='sidebar-category-elem {}'><a href='{}'>{}</a></li>",
                    current_article_marker, article.article_url, article.category_title
                );
            }
        }

        let category_path = format!(
            "/category/{}",
            self.category_metadata
                .category_full_path
                .join("/")
                .to_string()
        );

        let mut html = format!(
            r#"<div class="sidebar-category-header sidebar-box-header">§ 카테고리 - <a href="{}">{}</a></div>"#,
            category_path, self.category_metadata.category_name,
        );

        if self.has_more_article_above {
            html += &format!(
                r#"
            <div class='sidebar-show-more show-more-above'><a href='{}'><p>⋮</p><p>(더보기)</p></a></div>"#,
                category_path
            );
        }
        html += &format!(
            r#"
          <ul class="sidebar-category-list">
              {}
          </ul>"#,
            article_list_html
        );
        if self.has_more_article_below {
            html += &format!(
                r#"
            <div class='sidebar-show-more show-more-above'><a href='{}'><p>(더보기)</p><p>⋮</p></a></div>"#,
                category_path
            );
        }

        Ok(InputValue::Cacheable(Value::from(html), 0))
    }
}

struct NumCommentsInArticle {
    comment_context: Arc<dyn CommentContext>,
    article_url: String,

    cached_num_comment: RwLock<Option<(/*timestamp=*/ i64, Value)>>,
}

impl NumCommentsInArticle {
    pub fn new(comment_context: Arc<dyn CommentContext>, article_url: &str) -> Self {
        Self {
            comment_context,
            article_url: article_url.to_owned(),
            cached_num_comment: RwLock::new(None),
        }
    }
}

#[async_trait]
impl TopLevelPageInput for NumCommentsInArticle {
    fn input_name(&self) -> &'static str {
        "num_comment"
    }

    async fn get_input_value(&self) -> Result<InputValue, ServerError> {
        let latest_timestamp = self
            .comment_context
            .get_latest_comment_timestamp_on_article(&self.article_url)
            .await?;

        match latest_timestamp {
            Some(latest_timestamp) => {
                {
                    let cached_num_comment = self.cached_num_comment.read().unwrap();
                    if cached_num_comment.is_some() {
                        let (cached_etag, cached_comment) =
                            cached_num_comment.as_ref().unwrap().to_owned();
                        if cached_etag == latest_timestamp {
                            return Ok(InputValue::Cacheable(cached_comment, cached_etag));
                        }
                    }
                }

                let num_comments = self
                    .comment_context
                    .get_num_total_comments(&self.article_url)
                    .await?;

                let num_comments = to_value(num_comments)?;
                *self.cached_num_comment.write().unwrap() =
                    Some((latest_timestamp, num_comments.clone()));
                return Ok(InputValue::Cacheable(num_comments, latest_timestamp));
            }
            None => {
                // This article has no comment.
                Ok(InputValue::Cacheable(serde_json::to_value(0).unwrap(), 0))
            }
        }
    }
}

struct ArticleFileInfo {
    article_data: Value,
}

impl StaticTopLevelPageInput for ArticleFileInfo {
    fn static_input_name(&self) -> &'static str {
        "file_info"
    }

    fn static_input(&self) -> Value {
        self.article_data.clone()
    }
}

impl ArticleFileInfo {
    fn new(metadata: ArticleMetadata) -> Self {
        Self {
            article_data: to_value(metadata).unwrap(),
        }
    }
}

struct AllArticleMetadata {
    article_data: Value,
}

impl StaticTopLevelPageInput for AllArticleMetadata {
    fn static_input_name(&self) -> &'static str {
        "file_infos"
    }

    fn static_input(&self) -> Value {
        self.article_data.clone()
    }
}

impl AllArticleMetadata {
    fn new(metadatas: &Vec<ArticleMetadata>) -> Self {
        let metadata_map = metadatas
            .into_iter()
            .map(|metadata| (metadata.article_url.to_owned(), metadata.clone()))
            .collect::<HashMap<_, _>>();
        Self {
            article_data: to_value(metadata_map).unwrap(),
        }
    }
}

struct ArticleContentUrl {
    content_url: Value,
}

impl StaticTopLevelPageInput for ArticleContentUrl {
    fn static_input_name(&self) -> &'static str {
        "content_url"
    }

    fn static_input(&self) -> Value {
        self.content_url.clone()
    }
}

impl ArticleContentUrl {
    fn new(article_url: &str) -> Self {
        Self {
            content_url: to_value(format!(
                "/home/jaebum/ModooCode/views/new/{}.html",
                article_url
            ))
            .unwrap(),
        }
    }
}

struct PageInfos {
    page_infos: Value,
}

impl StaticTopLevelPageInput for PageInfos {
    fn static_input_name(&self) -> &'static str {
        "page_infos"
    }

    fn static_input(&self) -> Value {
        self.page_infos.clone()
    }
}

impl PageInfos {
    fn new(page_infos: &str) -> Self {
        Self {
            page_infos: serde_json::from_str(page_infos).unwrap(),
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
