use std::collections::{HashMap, HashSet};
use std::sync::{Arc, Mutex};

use async_trait::async_trait;
use axum::extract::{Path, State};
use axum::response::{Html, IntoResponse, Redirect, Response};
use axum_sessions::extractors::ReadableSession;
use dojang::Dojang;

use super::index::IndexPageRendererContext;
use super::renderer::{InputValue, RequestScopedInputs};
use crate::context::article_context::ArticleContext;
use crate::context::comment_context::CommentContext;
use crate::context::context::{Context, ProdContext};
use crate::context::site_stat_context::SiteStatContext;
use crate::error::errors::ServerError;

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
    ) -> Result<Self, ServerError> {
        let mut page_context = ProdPageContext {
            page_renderers: vec![],
            page_url_to_renderer_index: HashMap::new(),
        };

        page_context.register_renderer(Box::new(IndexPageRendererContext::new(
            dojang,
            comment_context,
            article_context,
            site_stat_context,
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

pub struct ArticlePageRequestScopedInputs {}

impl RequestScopedInputs for ArticlePageRequestScopedInputs {
    fn get_input_valuess(&self) -> Result<Vec<(String, InputValue)>, ServerError> {
        Ok(vec![])
    }
}

pub async fn page_handler(
    Path(page_url): Path<String>,
    State(context): State<Arc<ProdContext>>,
    session: ReadableSession,
) -> Response {
    let page = context
        .page_context()
        .render_page(&page_url, Arc::new(ArticlePageRequestScopedInputs {}))
        .await;
    match page {
        Ok(page) => Html(page).into_response(),
        Err(_) => Redirect::temporary("/").into_response(),
    }
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
