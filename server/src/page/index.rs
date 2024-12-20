use std::collections::HashSet;
use std::sync::{Arc, Mutex};

use async_trait::async_trait;
use dojang::Dojang;

use super::page::PageRendererContext;
use super::renderer::{InputValue, PageRenderer, RequestScopedInputs, TopLevelPageInput};
use crate::context::article_context::ArticleContext;
use crate::context::comment_context::CommentContext;
use crate::context::site_stat_context::{get_days_string_starting_from_today, SiteStatContext};
use crate::error::errors::ServerError;

pub struct IndexPageRendererContext {
    index_page_renderer: PageRenderer,
}

impl IndexPageRendererContext {
    pub fn new(
        dojang: Arc<Mutex<Dojang>>,
        comment_context: Arc<dyn CommentContext>,
        article_context: Arc<dyn ArticleContext>,
        site_stat_context: Arc<dyn SiteStatContext>,
    ) -> Self {
        Self {
            index_page_renderer: PageRenderer::new(
                "index",
                vec![
                    Box::new(RecentComments::new(comment_context)),
                    Box::new(RecentArticles::new(article_context)),
                    Box::new(VisitorCounts::new(site_stat_context)),
                ],
                1,
                dojang,
            ),
        }
    }
}

#[async_trait]
impl PageRendererContext for IndexPageRendererContext {
    fn get_matching_pages(&self) -> std::collections::HashSet<String> {
        HashSet::from_iter(vec!["".to_owned()])
    }

    async fn render_page(
        &mut self,
        _article_url: &str,
        request_scoped_inputs: Arc<dyn RequestScopedInputs>,
    ) -> Result<String, ServerError> {
        Ok(self
            .index_page_renderer
            .render_page(request_scoped_inputs)
            .await?)
    }
}

struct RecentComments {
    comment_context: Arc<dyn CommentContext>,
}

impl RecentComments {
    pub fn new(comment_context: Arc<dyn CommentContext>) -> Self {
        RecentComments { comment_context }
    }
}

#[async_trait]
impl TopLevelPageInput for RecentComments {
    fn input_name(&self) -> &'static str {
        "comments"
    }

    async fn get_input_value(&self) -> Result<InputValue, ServerError> {
        let recent_comments = self.comment_context.get_recent_comments(10).await?;

        let etag = if !recent_comments.is_empty() {
            recent_comments[0]
                .comment_date
                .unwrap_or_default()
                .and_utc()
                .timestamp_millis()
        } else {
            0
        };

        // Add integer timestamp to the CommentData.
        let recent_comments: Vec<_> = recent_comments
            .into_iter()
            .map(|c| {
                let comment_date = c.comment_date.unwrap().and_utc().timestamp();
                let mut c = serde_json::to_value(c).unwrap();
                c.as_object_mut()
                    .unwrap()
                    .insert("comment_date_timestamp".to_owned(), comment_date.into());

                c
            })
            .collect();

        let recent_comments = serde_json::to_value(recent_comments).unwrap();
        Ok(InputValue::Cacheable(recent_comments, etag))
    }
}

struct RecentArticles {
    article_context: Arc<dyn ArticleContext>,
}

impl RecentArticles {
    pub fn new(article_context: Arc<dyn ArticleContext>) -> Self {
        Self { article_context }
    }
}

#[async_trait]
impl TopLevelPageInput for RecentArticles {
    fn input_name(&self) -> &'static str {
        "recent_articles"
    }

    async fn get_input_value(&self) -> Result<InputValue, ServerError> {
        let recent_articles = self.article_context.get_recent_articles(10).await?;
        let etag = if !recent_articles.is_empty() {
            recent_articles[0]
                .create_time
                .unwrap_or_default()
                .and_utc()
                .timestamp_millis()
        } else {
            0
        };

        let recent_article_urls = recent_articles
            .into_iter()
            .map(|a| a.article_url)
            .collect::<Vec<_>>();
        let recent_article_metadata = self
            .article_context
            .multi_get_article_metadata(recent_article_urls.as_slice())
            .into_iter()
            .filter_map(|m| m)
            .collect::<Vec<_>>();

        let recent_articles = serde_json::to_value(recent_article_metadata).unwrap();

        Ok(InputValue::Cacheable(recent_articles, etag))
    }
}

struct VisitorCounts {
    site_stat_context: Arc<dyn SiteStatContext>,
}

impl VisitorCounts {
    pub fn new(site_stat_context: Arc<dyn SiteStatContext>) -> Self {
        Self { site_stat_context }
    }
}

#[async_trait]
impl TopLevelPageInput for VisitorCounts {
    fn input_name(&self) -> &'static str {
        "visitor_counts"
    }

    async fn get_input_value(&self) -> Result<InputValue, ServerError> {
        let recent_visitor_counts = self.site_stat_context.get_num_visitors_per_day(8);

        let etag = recent_visitor_counts.last().map_or(0, |count| *count);
        let day_and_num_visits = recent_visitor_counts
            .into_iter()
            .zip(get_days_string_starting_from_today(8, /*dash_between_times=*/ false).into_iter())
            .map(|(count, day)| (day, count.to_string()))
            .collect::<Vec<(String, String)>>();

        Ok(InputValue::Cacheable(
            serde_json::to_value(day_and_num_visits).unwrap(),
            etag as i64,
        ))
    }
}
