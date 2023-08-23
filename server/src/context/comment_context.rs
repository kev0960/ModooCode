use std::collections::HashMap;
use std::sync::Arc;

use async_trait::async_trait;
use chrono::NaiveDateTime;
use sea_orm::{entity::*, query::*};
use serde::Serialize;

use crate::db::db::Database;
use crate::entity::comment as Comment;
use crate::error::errors::ServerError;

pub const ARTICLE_COMMENT_PAGE_SIZE: u64 = 50;

#[derive(Serialize, Debug)]
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

    async fn create_comment(
        &self,
        article_url: &str,
        parent_id: Option<i32>,
        content: &str,
        author_name: &str,
        password: &str,
        author_id: Option<i32>,
        author_email: Option<&str>,
        image_link: Option<&str>,
    ) -> Result<(), ServerError>;

    async fn get_latest_comment_timestamp_on_article(
        &self,
        article_url: &str,
    ) -> Result<Option<i64>, ServerError>;

    async fn get_comments_on_article(
        &self,
        article_url: &str,
        page: u64,
    ) -> Result<Vec<CommentData>, ServerError>;

    async fn get_num_total_comments(&self, article_url: &str) -> Result<i32, ServerError>;
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

    async fn create_comment(
        &self,
        article_url: &str,
        parent_id: Option<i32>,
        content: &str,
        author_name: &str,
        password: &str,
        author_id: Option<i32>,
        author_email: Option<&str>,
        image_link: Option<&str>,
    ) -> Result<(), ServerError> {
        let parent_comment = if let Some(parent_id) = parent_id {
            if parent_id == -1 {
                None
            } else {
                let parent_comment = Comment::Entity::find_by_id(parent_id)
                    .one(self.database.connection())
                    .await?;
                if parent_comment.is_none() {
                    return Err(ServerError::BadRequest(format!(
                        "parent id : {} does not exist",
                        parent_id
                    )));
                }
                Some(CommentData::from(parent_comment.unwrap()))
            }
        } else {
            None
        };

        let txn = self.database.connection().begin().await?;

        // First create a comment.
        let created_comment = Comment::ActiveModel {
            article_url: Set(article_url.to_owned()),
            comment_date: Set(Some(chrono::Utc::now().naive_utc())),
            modified_date: Set(Some(chrono::Utc::now().naive_utc())),
            author_name: Set(Some(author_name.to_owned())),
            author_email: Set(author_email.map(|email| email.to_owned())),
            image_link: Set(image_link.map(|link| link.to_owned())),
            content: Set(content.to_owned()),
            password: Set(password.to_owned()),
            is_md: Set(false),
            author_id: Set(author_id),
            ..Default::default()
        }
        .insert(&txn)
        .await?;

        if let Some(parent_comment) = parent_comment {
            let mut parent_reply_ids = parent_comment.reply_ids.unwrap_or_default();
            parent_reply_ids.push(created_comment.comment_id);

            Comment::ActiveModel {
                comment_id: Set(parent_comment.comment_id),
                reply_ids: Set(Some(parent_reply_ids)),
                ..Default::default()
            }
            .update(&txn)
            .await?;
        }

        txn.commit().await?;

        self.lastest_comment_timestamp_of_articles
            .write()
            .unwrap()
            .insert(
                article_url.to_string(),
                Some(
                    created_comment
                        .comment_date
                        .unwrap_or_default()
                        .timestamp_millis(),
                ),
            );

        Ok(())
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

    async fn get_num_total_comments(&self, article_url: &str) -> Result<i32, ServerError> {
        Ok(Comment::Entity::find()
            .filter(
                sea_orm::Condition::all()
                    .add(Comment::Column::IsDeleted.eq(false))
                    .add(Comment::Column::ArticleUrl.eq(article_url)),
            )
            .count(self.database.connection())
            .await? as i32)
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
