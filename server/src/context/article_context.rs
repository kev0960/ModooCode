use std::sync::Arc;

use async_trait::async_trait;
use chrono::NaiveDateTime;
use sea_orm::{entity::*, query::*};
use serde::Serialize;

use crate::db::db::Database;
use crate::entity::article as Article;
use crate::error::errors::ServerError;

#[derive(Serialize)]
pub struct ArticleData {
    pub article_url: String,
    pub create_time: Option<NaiveDateTime>,
    pub update_time: Option<NaiveDateTime>,
    pub is_published: bool,
    pub is_deleted: bool,
    pub content: String,
    pub view_cnt: Option<i32>,
}

impl From<Article::Model> for ArticleData {
    fn from(value: Article::Model) -> Self {
        Self {
            article_url: value.article_url,
            create_time: value.create_time,
            update_time: value.update_time,
            is_published: value.is_published,
            is_deleted: value.is_deleted,
            content: value.content,
            view_cnt: value.view_cnt,
        }
    }
}

#[async_trait]
pub trait ArticleContext
where
    Self: Send + Sync,
{
    async fn get_recent_articles(&self, num_articles: u64)
        -> Result<Vec<ArticleData>, ServerError>;

    async fn get_article_by_url(
        &self,
        article_url: &str,
    ) -> Result<Option<ArticleData>, ServerError>;
}

pub struct ProdArticleContext {
    database: Arc<dyn Database>,
}

#[async_trait]
impl ArticleContext for ProdArticleContext {
    async fn get_recent_articles(
        &self,
        num_articles: u64,
    ) -> Result<Vec<ArticleData>, ServerError> {
        Ok(Article::Entity::find()
            .filter(Article::Column::IsDeleted.eq(false))
            .order_by_desc(Article::Column::CreateTime)
            .limit(num_articles)
            .all(self.database.connection())
            .await?
            .into_iter()
            .map(|a| a.into())
            .collect())
    }

    async fn get_article_by_url(
        &self,
        article_url: &str,
    ) -> Result<Option<ArticleData>, ServerError> {
        let article = Article::Entity::find_by_id(article_url)
            .one(self.database.connection())
            .await?;

        Ok(article.map(|a| a.into()))
    }
}

impl ProdArticleContext {
    pub fn new(database: Arc<dyn Database>) -> Self {
        ProdArticleContext { database }
    }
}
