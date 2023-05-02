use std::collections::HashMap;
use std::sync::{Arc, Mutex, RwLock};

use async_trait::async_trait;
use dojang::Dojang;
use serde_json::Value;

use super::renderer::{InputValue, PageRenderer, TopLevelPageInput};
use crate::context::article_context::ArticleContext;
use crate::context::comment_context::CommentContext;
use crate::error::errors::ServerError;

pub struct ArticlePageRendererContext {
    article_page_renderer: HashMap<String, PageRenderer>,
}

impl ArticlePageRendererContext {
    pub async fn new(dojang: Arc<Mutex<Dojang>>, article_context: Arc<dyn ArticleContext>) -> Self {
        let article_metdatas = article_context.get_every_article_metadata();

        let mut article_page_renderer = HashMap::new();
        for metadata in article_metdatas {
            article_page_renderer.insert(
                metadata.article_url,
                PageRenderer::new("page", vec![], 1, dojang.clone()),
            );
        }

        Self {
            article_page_renderer,
        }
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
                        let (cached_etag, cached_comment) = cached_comment.as_ref().unwrap().to_owned();
                        if cached_etag == latest_timestamp {
                            return Ok(InputValue::Cacheable(cached_comment, cached_etag));
                        }
                    }
                }

                let comments = self
                    .comment_context
                    .get_comments_on_article(&self.article_url, 0)
                    .await?;

                let comments = serde_json::to_value(comments)?;
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
