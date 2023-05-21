use std::collections::{HashMap, HashSet};
use std::sync::{Arc, Mutex, RwLock};

use async_trait::async_trait;
use dojang::Dojang;
use serde_json::{to_value, Value};

use super::page::PageRendererContext;
use super::renderer::{
    InputValue, PageRenderer, RequestScopedInputs, StaticTopLevelPageInput, TopLevelPageInput,
};
use crate::context::article_context::{ArticleContext, ArticleMetadata};
use crate::context::comment_context::CommentContext;
use crate::error::errors::ServerError;

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
                    "page",
                    vec![
                        Box::new(CommentsInArticle::new(
                            comment_context.clone(),
                            &metadata.article_url,
                        )),
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
                        Box::new(AllArticleMetadata::new(&article_metdatas)),
                        Box::new(ArticleContentUrl::new(&metadata.article_url)),
                        Box::new(CategoryHtml::new(
                            &article_context
                                .get_category_listing_of_article(&metadata.article_url)
                                .unwrap_or_default(),
                        )),
                        Box::new(PageInfos::new(&page_path_json)),
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

struct CommentsInArticle {
    comment_context: Arc<dyn CommentContext>,
    article_url: String,

    cached_comment: RwLock<Option<(/*timestamp=*/ i64, Value)>>,
}

impl CommentsInArticle {
    pub fn new(comment_context: Arc<dyn CommentContext>, article_url: &str) -> Self {
        Self {
            comment_context,
            article_url: article_url.to_owned(),
            cached_comment: RwLock::new(None),
        }
    }
}

#[async_trait]
impl TopLevelPageInput for CommentsInArticle {
    fn input_name(&self) -> &'static str {
        "comments"
    }

    async fn get_input_value(&self) -> Result<InputValue, ServerError> {
        let latest_timestamp = self
            .comment_context
            .get_latest_comment_timestamp_on_article(&self.article_url)
            .await?;

        match latest_timestamp {
            Some(latest_timestamp) => {
                {
                    let cached_comment = self.cached_comment.read().unwrap();
                    if cached_comment.is_some() {
                        let (cached_etag, cached_comment) =
                            cached_comment.as_ref().unwrap().to_owned();
                        if cached_etag == latest_timestamp {
                            return Ok(InputValue::Cacheable(cached_comment, cached_etag));
                        }
                    }
                }

                let comments = self
                    .comment_context
                    .get_comments_on_article(&self.article_url, 0)
                    .await?;

                let comments = to_value(comments)?;
                *self.cached_comment.write().unwrap() = Some((latest_timestamp, comments.clone()));
                return Ok(InputValue::Cacheable(comments, latest_timestamp));
            }
            None => {
                // This article has no comment.
                Ok(InputValue::Cacheable(serde_json::Value::Null, 0))
            }
        }
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
                    .get_comments_on_article(&self.article_url, 0)
                    .await?
                    .len();

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
        Self {
            article_data: to_value(metadatas).unwrap(),
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

struct CategoryHtml {
    category_html: Value,
}

impl StaticTopLevelPageInput for CategoryHtml {
    fn static_input_name(&self) -> &'static str {
        "category_html"
    }

    fn static_input(&self) -> Value {
        self.category_html.clone()
    }
}

impl CategoryHtml {
    fn new(category_html: &str) -> Self {
        Self {
            category_html: to_value(category_html).unwrap(),
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
            page_infos: to_value(page_infos).unwrap(),
        }
    }
}
