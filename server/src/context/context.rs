use std::sync::{Arc, Mutex};

use chrono::TimeZone;
use dojang::Dojang;

use super::article_context::{ArticleContext, ProdArticleContext};
use super::comment_context::{CommentContext, ProdCommentContext};
use super::site_stat_context::{ProdSiteStatContext, SiteStatContext};
use super::user_context::{ProdUserContext, UserContext};
use crate::db::db::{Database, ProdDatabase};
use crate::error::errors::ServerError;
use crate::page::page::{PageContext, ProdPageContext};

pub trait Context {
    fn database(&self) -> Arc<dyn Database>;
    fn comment_context(&self) -> Arc<dyn CommentContext>;
    fn article_context(&self) -> Arc<dyn ArticleContext>;
    fn page_context(&self) -> Arc<dyn PageContext>;
    fn site_stat_context(&self) -> Arc<dyn SiteStatContext>;
    fn user_context(&self) -> Arc<dyn UserContext>;
    fn dojang(&self) -> Arc<Mutex<Dojang>>;
}

pub struct ProdContext {
    database: Arc<ProdDatabase>,
    comment_context: Arc<ProdCommentContext>,
    article_context: Arc<ProdArticleContext>,
    page_context: Arc<ProdPageContext>,
    site_stat_context: Arc<ProdSiteStatContext>,
    user_context: Arc<ProdUserContext>,
    dojang: Arc<Mutex<Dojang>>,
}

fn timestamp_to_kor_time(timestamp: i64, format: String) -> String {
    let naive = chrono::NaiveDateTime::from_timestamp_opt(timestamp, 0).unwrap();

    // KST: UTC+9:00
    let kor_time = chrono::FixedOffset::west_opt(9 * 3600).unwrap();
    let datetime = kor_time.from_local_datetime(&naive).unwrap();

    datetime.format(&format).to_string()
}

impl ProdContext {
    pub async fn new(
        connection_string: &str,
        service_account_key: &str,
        file_header_path: &str,
        page_path: &str,
    ) -> Result<Self, ServerError> {
        let database = Arc::new(ProdDatabase::new(connection_string).await?);
        let comment_context = Arc::new(ProdCommentContext::new(database.clone()));
        let article_context =
            Arc::new(ProdArticleContext::new(database.clone(), file_header_path, page_path).await?);
        let site_state_context = Arc::new(
            ProdSiteStatContext::new(service_account_key)
                .await
                .map_err(|err| ServerError::Internal(err.to_string()))?,
        );
        let user_context = Arc::new(ProdUserContext::new(database.clone()).await);

        let mut dojang = Dojang::new();
        dojang
            .add_function_2("timestamp_to_kor_time".to_string(), timestamp_to_kor_time)
            .unwrap();

        dojang
            .add(
                "page".to_string(),
                std::fs::read_to_string("templates/page.html").unwrap(),
            )
            .map_err(|e| ServerError::Internal(e))?;
        dojang
            .add(
                "header-common".to_string(),
                std::fs::read_to_string("templates/header-common.html").unwrap(),
            )
            .map_err(|e| ServerError::Internal(e))?;
        dojang
            .add(
                "sidebar".to_string(),
                std::fs::read_to_string("templates/sidebar.html").unwrap(),
            )
            .map_err(|e| ServerError::Internal(e))?;
        dojang
            .add(
                "index".to_string(),
                std::fs::read_to_string("templates/index.html").unwrap(),
            )
            .map_err(|e| ServerError::Internal(e))?;

        let dojang = Arc::new(Mutex::new(dojang));
        Ok(ProdContext {
            database: database.clone(),
            comment_context: comment_context.clone(),
            article_context: article_context.clone(),
            page_context: Arc::new(ProdPageContext::new(
                comment_context.clone(),
                article_context.clone(),
                site_state_context.clone(),
                dojang.clone(),
                page_path,
            )?),
            site_stat_context: site_state_context.clone(),
            user_context: user_context.clone(),
            dojang: dojang.clone(),
        })
    }
}

impl Context for ProdContext {
    fn database(&self) -> Arc<dyn Database> {
        self.database.clone()
    }

    fn comment_context(&self) -> Arc<dyn CommentContext> {
        self.comment_context.clone()
    }

    fn article_context(&self) -> Arc<dyn ArticleContext> {
        self.article_context.clone()
    }

    fn page_context(&self) -> Arc<dyn PageContext> {
        self.page_context.clone()
    }

    fn site_stat_context(&self) -> Arc<dyn SiteStatContext> {
        self.site_stat_context.clone()
    }

    fn user_context(&self) -> Arc<dyn UserContext> {
        self.user_context.clone()
    }

    fn dojang(&self) -> Arc<Mutex<Dojang>> {
        self.dojang.clone()
    }
}
