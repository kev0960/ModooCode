use std::collections::{HashMap, HashSet};
use std::sync::{Arc, Mutex};

use async_trait::async_trait;
use axum::extract::{Path, State};
use axum::response::{Html, IntoResponse, Redirect, Response};
use axum_sessions::extractors::ReadableSession;
use dojang::Dojang;

use super::article::ArticlePageRendererContext;
use super::category::CategoryPageRendererContext;
use super::index::IndexPageRendererContext;
use super::renderer::{InputValue, RequestScopedInputs};
use crate::context::article_context::ArticleContext;
use crate::context::comment_context::CommentContext;
use crate::context::context::{Context, ProdContext};
use crate::context::site_stat_context::SiteStatContext;
use crate::error::errors::ServerError;
use crate::user::user_info::UserInfo;

#[async_trait]
pub trait PageRendererContext
where
    Self: Sync + Send,
{
    // Return pages that should be handled by this context.
    fn get_matching_pages(&self) -> HashSet<String>;

    async fn render_page(
        &mut self,
        article_url: &str,
        request_scoped_inputs: Arc<dyn RequestScopedInputs>,
    ) -> Result<String, ServerError>;
}

#[async_trait]
pub trait PageContext
where
    Self: Send + Sync,
{
    async fn render_page(
        &self,
        article_url: &str,
        request_scoped_inputs: Arc<dyn RequestScopedInputs>,
    ) -> Result<String, ServerError>;
}

pub struct ProdPageContext {
    page_renderers: Vec<tokio::sync::Mutex<Box<dyn PageRendererContext>>>,
    page_url_to_renderer_index: HashMap<String, usize>,
}

#[async_trait]
impl PageContext for ProdPageContext {
    async fn render_page(
        &self,
        article_url: &str,
        request_scoped_inputs: Arc<dyn RequestScopedInputs>,
    ) -> Result<String, ServerError> {
        if let Some(renderer_index) = self.page_url_to_renderer_index.get(article_url) {
            Ok(self.page_renderers[*renderer_index]
                .lock()
                .await
                .render_page(article_url, request_scoped_inputs)
                .await?)
        } else {
            return Err(ServerError::BadRequest(format!(
                "Renderer not found for {}",
                article_url
            )));
        }
    }
}

impl ProdPageContext {
    pub fn new(
        comment_context: Arc<dyn CommentContext>,
        article_context: Arc<dyn ArticleContext>,
        site_stat_context: Arc<dyn SiteStatContext>,
        dojang: Arc<Mutex<Dojang>>,
        page_path_json_path: &str,
    ) -> Result<Self, ServerError> {
        let mut page_context = ProdPageContext {
            page_renderers: vec![],
            page_url_to_renderer_index: HashMap::new(),
        };

        page_context.register_renderer(Box::new(IndexPageRendererContext::new(
            dojang.clone(),
            comment_context.clone(),
            article_context.clone(),
            site_stat_context,
        )))?;

        page_context.register_renderer(Box::new(CategoryPageRendererContext::new(
            dojang.clone(),
            article_context.clone(),
            page_path_json_path,
        )))?;

        page_context.register_renderer(Box::new(ArticlePageRendererContext::new(
            dojang,
            comment_context,
            article_context,
            page_path_json_path,
        )))?;

        Ok(page_context)
    }

    fn register_renderer(
        &mut self,
        renderer: Box<dyn PageRendererContext>,
    ) -> Result<(), ServerError> {
        let covered_page_urls = renderer.get_matching_pages();
        self.page_renderers.push(tokio::sync::Mutex::new(renderer));

        for page_url in covered_page_urls {
            if self.page_url_to_renderer_index.contains_key(&page_url) {
                return Err(ServerError::Internal(format!(
                    "Multiple registered renderer found for the key {}",
                    page_url
                )));
            }

            self.page_url_to_renderer_index
                .insert(page_url, self.page_renderers.len() - 1);
        }

        Ok(())
    }
}

pub struct ArticlePageRequestScopedInputs {
    user_info: Option<UserInfo>,
}

impl RequestScopedInputs for ArticlePageRequestScopedInputs {
    fn get_input_valuess(&self) -> Result<Vec<(String, InputValue)>, ServerError> {
        let user_info = match &self.user_info {
            Some(user_info) => InputValue::NonCacheable(serde_json::to_value(user_info).unwrap()),
            _ => InputValue::Cacheable(serde_json::Value::Null, /*etag=*/ 0),
        };

        Ok(vec![
            ("user".to_owned(), user_info),
            (
                // TODO: This should be parsed from the user agent string.
                "is_mobile".to_owned(),
                InputValue::Cacheable(serde_json::to_value(false).unwrap(), /*etag=*/ 0),
            ),
        ])
    }
}

impl ArticlePageRequestScopedInputs {
    fn new(user_info: Option<UserInfo>) -> Self {
        Self { user_info }
    }
}

pub async fn page_handler(
    Path(page_url): Path<String>,
    State(context): State<Arc<ProdContext>>,
    session: ReadableSession,
) -> Response {
    if context.article_context().is_instruction(&page_url) {
        return Redirect::permanent(&format!("/en/inst/{}", page_url)).into_response();
    }

    let user_info = UserInfo::get_user_info(session);
    let page = context
        .page_context()
        .render_page(
            &page_url,
            Arc::new(ArticlePageRequestScopedInputs::new(user_info)),
        )
        .await;

    match page {
        Ok(page) => Html(page).into_response(),
        Err(e) => {
            println!("Err : {:?}", e);
            Redirect::temporary("/").into_response()
        }
    }
}

pub async fn category_page_handler(
    Path(category_name): Path<String>,
    State(context): State<Arc<ProdContext>>,
    session: ReadableSession,
) -> Response {
    println!("Category : {}", category_name);
    let user_info = UserInfo::get_user_info(session);
    let page = context
        .page_context()
        .render_page(
            &format!("/category/{}", category_name),
            Arc::new(ArticlePageRequestScopedInputs::new(user_info)),
        )
        .await;

    match page {
        Ok(page) => Html(page).into_response(),
        Err(e) => {
            println!("Err : {:?}", e);
            Redirect::temporary("/").into_response()
        }
    }
}

pub async fn inst_page_handler(
    Path(inst_name): Path<String>,
    State(context): State<Arc<ProdContext>>,
    session: ReadableSession,
) -> Response {
    let user_info = UserInfo::get_user_info(session);
    let page = context
        .page_context()
        .render_page(
            &inst_name,
            Arc::new(ArticlePageRequestScopedInputs::new(user_info)),
        )
        .await;

    match page {
        Ok(page) => Html(page).into_response(),
        Err(e) => {
            println!("Err : {:?}", e);
            Redirect::temporary("/").into_response()
        }
    }
}

pub async fn notice_page_handler(Path(notice_url): Path<String>) -> Response {
    if notice_url == "15" {
        return Redirect::permanent("/231").into_response();
    }

    Redirect::permanent("/").into_response()
}

pub struct IndexPageRequestScopedInputs {}

impl RequestScopedInputs for IndexPageRequestScopedInputs {
    fn get_input_valuess(&self) -> Result<Vec<(String, InputValue)>, ServerError> {
        Ok(vec![])
    }
}

pub async fn index_page_handler(State(context): State<Arc<ProdContext>>) -> Response {
    let page = context
        .page_context()
        .render_page(&"", Arc::new(IndexPageRequestScopedInputs {}))
        .await;
    match page {
        Ok(page) => Html(page).into_response(),
        Err(_) => Redirect::temporary("/").into_response(),
    }
}
