use std::collections::HashMap;
use std::sync::Arc;

use async_trait::async_trait;
use chrono::NaiveDateTime;
use sea_orm::{entity::*, query::*};
use serde::Serialize;

use crate::db::db::Database;
use crate::entity::comment as Comment;
use crate::error::errors::ServerError;

const ARTICLE_COMMENT_PAGE_SIZE: u64 = 50;

#[derive(Serialize)]
pub struct CommentData {
    pub comment_id: i32,
    pub article_url: String,
    pub reply_ids: Option<Vec<i32>>,
    pub comment_date: Option<NaiveDateTime>,
    pub modified_date: Option<NaiveDateTime>,
    pub author_name: Option<String>,
    pub author_email: Option<String>,
    pub image_link: Option<String>,
    pub content: String,
    pub password: String,
    pub is_md: bool,
    pub is_deleted: Option<bool>,
    pub author_id: Option<i32>,
}

impl From<Comment::Model> for CommentData {
    fn from(value: Comment::Model) -> Self {
        Self {
            comment_id: value.comment_id,
            article_url: value.article_url,
            reply_ids: value.reply_ids,
            comment_date: value.comment_date,
            modified_date: value.modified_date,
            author_name: value.author_name,
            author_email: value.author_email,
            image_link: value.image_link,
            content: value.content,
            password: value.password,
            is_md: value.is_md,
            is_deleted: value.is_deleted,
            author_id: value.author_id,
        }
    }
}

#[async_trait]
pub trait CommentContext
where
    Self: Send + Sync,
{
    async fn get_recent_comments(&self, num_comments: u64)
        -> Result<Vec<CommentData>, ServerError>;

    async fn get_latest_comment_timestamp_on_article(
        &self,
        article_url: &str,
    ) -> Result<Option<i64>, ServerError>;

    async fn get_comments_on_article(
        &self,
        article_url: &str,
        page: u64,
    ) -> Result<Vec<CommentData>, ServerError>;
}

pub struct ProdCommentContext {
    database: Arc<dyn Database>,
    lastest_comment_timestamp_of_articles: std::sync::RwLock<HashMap<String, Option<i64>>>,
}

#[async_trait]
impl CommentContext for ProdCommentContext {
    async fn get_recent_comments(
        &self,
        num_comments: u64,
    ) -> Result<Vec<CommentData>, ServerError> {
        Ok(Comment::Entity::find()
            .filter(Comment::Column::IsDeleted.eq(false))
            .order_by_desc(Comment::Column::CommentDate)
            .limit(num_comments)
            .all(self.database.connection())
            .await?
            .into_iter()
            .map(|comment| CommentData::from(comment))
            .collect())
    }

    async fn get_latest_comment_timestamp_on_article(
        &self,
        article_url: &str,
    ) -> Result<Option<i64>, ServerError> {
        if let Some(timestamp) = self
            .lastest_comment_timestamp_of_articles
            .read()
            .unwrap()
            .get(article_url)
        {
            return Ok(*timestamp);
        }

        // If the entry is missing, then we should fetch from the server.
        let oldest_comment = Comment::Entity::find()
            .filter(Comment::Column::ArticleUrl.eq(article_url))
            .order_by_desc(Comment::Column::CommentDate)
            .one(self.database.connection())
            .await?;

        let timestamp = match oldest_comment {
            Some(comment) => Some(comment.comment_date.unwrap_or_default().timestamp_millis()),
            None => None,
        };

        self.lastest_comment_timestamp_of_articles
            .write()
            .unwrap()
            .insert(article_url.to_owned(), timestamp);

        Ok(timestamp)
    }

    async fn get_comments_on_article(
        &self,
        article_url: &str,
        page: u64,
    ) -> Result<Vec<CommentData>, ServerError> {
        Ok(Comment::Entity::find()
            .filter(
                sea_orm::Condition::all()
                    .add(Comment::Column::IsDeleted.eq(false))
                    .add(Comment::Column::ArticleUrl.eq(article_url)),
            )
            .order_by_desc(Comment::Column::CommentDate)
            .paginate(self.database.connection(), ARTICLE_COMMENT_PAGE_SIZE)
            .fetch_page(page)
            .await?
            .into_iter()
            .map(|comment| CommentData::from(comment))
            .collect())
    }
}

impl ProdCommentContext {
    pub fn new(database: Arc<dyn Database>) -> Self {
        ProdCommentContext {
            database,
            lastest_comment_timestamp_of_articles: std::sync::RwLock::new(HashMap::new()),
        }
    }
}
