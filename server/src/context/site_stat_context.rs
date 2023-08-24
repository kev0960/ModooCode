use async_trait::async_trait;

use chrono::{FixedOffset, Utc};
use google_analytics_api_ga4::{
    types::{
        DateRange, Dimension, Filter, FilterExpression, FilterExpressionList, MatchType, Metric,
        StringFilter,
    },
    AnalyticsDataApi, RunReportRequest,
};
use std::collections::HashMap;
use yup_oauth2::AccessToken;

use crate::error::errors::ServerError;

#[async_trait]
pub trait SiteStatContext
where
    Self: Send + Sync,
{
    fn get_num_visitors_per_day(&self, num_days: i32) -> Vec<u32>;
    async fn fetch_site_stat(&self) -> Result<(), ServerError>;
}

pub struct ProdSiteStatContext {
    pub visitor_counts_per_day: std::sync::RwLock<HashMap<String, u32>>,
    pub service_account_key_path: String,
}

#[async_trait]
impl SiteStatContext for ProdSiteStatContext {
    fn get_num_visitors_per_day(&self, num_days: i32) -> Vec<u32> {
        get_days_string_starting_from_today(num_days, /*dash_between_times=*/ false)
            .into_iter()
            .map(|day| {
                self.visitor_counts_per_day
                    .read()
                    .unwrap()
                    .get(&day)
                    .map_or(0, |cnt| *cnt)
            })
            .collect()
    }

    async fn fetch_site_stat(&self) -> Result<(), ServerError> {
        self.parse_reports().await?;
        Ok(())
    }
}

impl ProdSiteStatContext {
    async fn token(&self) -> Result<AccessToken, ServerError> {
        let service_account_key =
            yup_oauth2::read_service_account_key(&self.service_account_key_path).await?;

        let authenticator = yup_oauth2::ServiceAccountAuthenticator::builder(service_account_key)
            .build()
            .await?;

        let scopes = &["https://www.googleapis.com/auth/analytics.readonly"];

        Ok(authenticator
            .token(scopes)
            .await
            .map_err(|e| ServerError::Internal(e.to_string()))?)
    }

    async fn parse_reports(&self) -> Result<(), ServerError> {
        let token = self.token().await?;
        let property_id = "250093251";
        let metric_values = vec!["sessions", "screenPageViews", "eventCount", "eventValue"];
        let dimension_values = vec!["fullPageUrl", "eventName"];

        let mut metrics = vec![];
        let mut dimensions = vec![];
        for value in metric_values {
            metrics.push(Metric::new(value));
        }
        for value in dimension_values {
            dimensions.push(google_analytics_api_ga4::types::Dimension::new(value));
        }

        let mut filter_expression = FilterExpression::default();
        let mut filter_list = FilterExpressionList::default();

        let mut filters = vec![];
        filters.push(FilterExpression {
            filter: Some(Filter {
                field_name: Some("fullPageUrl".to_string()),
                string_filter: Some(StringFilter {
                    match_type: Some(MatchType::BeginsWith),
                    value: Some("example.com".to_string()),
                    ..StringFilter::default()
                }),
                ..Filter::default()
            }),
            ..FilterExpression::default()
        });
        filter_list.expressions = Some(filters);

        filter_expression.and_group = Some(filter_list);

        let days = get_days_string_starting_from_today(8, /*dash_between_times=*/ true);

        let request = google_analytics_api_ga4::RunReportRequest {
            property: format!("properties/{}", property_id.to_string()),
            dimensions: vec![Dimension::new("date")],
            metrics: vec![Metric::new("active1DayUsers")],
            date_ranges: vec![DateRange::new("7days", &days[0], &days.last().unwrap())],
            ..RunReportRequest::default()
        };

        let run_report = AnalyticsDataApi::run_report(token.token().unwrap(), property_id, request)
            .await
            .map_err(|e| ServerError::Internal(e.to_string()))?;
        let rows = run_report.rows.unwrap_or_default();
        for row in rows {
            if let Some(dimension_values) = row.dimension_values {
                if let Some(metric_values) = row.metric_values {
                    if !dimension_values.is_empty() && !metric_values.is_empty() {
                        self.visitor_counts_per_day.write().unwrap().insert(
                            dimension_values
                                .get(0)
                                .unwrap()
                                .value
                                .as_ref()
                                .unwrap_or(&"".to_owned())
                                .to_owned(),
                            metric_values
                                .get(0)
                                .unwrap()
                                .value
                                .as_ref()
                                .unwrap_or(&"0".to_owned())
                                .parse::<u32>()
                                .unwrap(),
                        );
                    }
                }
            }
        }

        Ok(())
    }

    pub async fn new(service_account_key_path: &str) -> Result<Self, ServerError> {
        Ok(Self {
            service_account_key_path: service_account_key_path.to_owned(),
            visitor_counts_per_day: std::sync::RwLock::new(HashMap::new()),
        })
    }
}

pub fn get_days_string_starting_from_today(num_days: i32, dash_between_times: bool) -> Vec<String> {
    let mut utc_time = Utc::now().with_timezone(&FixedOffset::east_opt(9 * 3600).unwrap());

    let mut date_vec = vec![];
    for _ in 0..num_days {
        if dash_between_times {
            date_vec.push(utc_time.format("%Y-%m-%d").to_string());
        } else {
            date_vec.push(utc_time.format("%Y%m%d").to_string());
        }
        utc_time = utc_time - chrono::Duration::days(1);
    }

    date_vec.reverse();
    date_vec
}
