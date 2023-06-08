use async_trait::async_trait;

use chrono::{FixedOffset, Utc};
use google_analyticsreporting4::api::{
    DateRange, Dimension, GetReportsRequest, GetReportsResponse, Metric, ReportRequest,
};
use google_analyticsreporting4::AnalyticsReporting;
use hyper::client::HttpConnector;
use hyper_rustls::HttpsConnector;
use std::collections::HashMap;

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
    pub analytics_hub: AnalyticsReporting<HttpsConnector<HttpConnector>>,
}

#[async_trait]
impl SiteStatContext for ProdSiteStatContext {
    fn get_num_visitors_per_day(&self, num_days: i32) -> Vec<u32> {
        get_days_string_starting_from_today(num_days)
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
        let result = self
            .analytics_hub
            .reports()
            .batch_get(create_analytics_user_count_request())
            .doit()
            .await;

        match result {
            Err(_) => Ok(()),
            Ok((_, reports_response)) => self.parse_reports_and_set_kv(&reports_response),
        }
    }
}

fn create_analytics_user_count_request() -> GetReportsRequest {
    GetReportsRequest {
        report_requests: Some(vec![ReportRequest {
            view_id: Some("ga:184092436".to_string()),
            dimensions: Some(vec![Dimension {
                name: Some("ga:date".to_string()),
                histogram_buckets: None,
            }]),
            date_ranges: Some(vec![DateRange {
                start_date: Some("7daysAgo".to_string()),
                end_date: Some("today".to_string()),
            }]),
            metrics: Some(vec![Metric {
                expression: Some("ga:1dayUsers".to_string()),
                ..Default::default()
            }]),
            ..Default::default()
        }]),
        ..Default::default()
    }
}

impl ProdSiteStatContext {
    pub async fn new(service_account_key_path: &str) -> Result<Self, ServerError> {
        let service_account_key =
            yup_oauth2::read_service_account_key(service_account_key_path).await?;

        let authenticator = yup_oauth2::ServiceAccountAuthenticator::builder(service_account_key)
            .build()
            .await?;

        let connector = hyper_rustls::HttpsConnectorBuilder::new()
            .with_native_roots()
            .https_or_http()
            .enable_http1()
            .enable_http2()
            .build();

        let hyper = hyper::Client::builder().build(connector);
        let hub = AnalyticsReporting::new(hyper, authenticator);

        Ok(Self {
            visitor_counts_per_day: std::sync::RwLock::new(HashMap::new()),
            analytics_hub: hub,
        })
    }

    fn parse_reports_and_set_kv(&self, response: &GetReportsResponse) -> Result<(), ServerError> {
        if response.reports.is_none() {
            return Err(ServerError::Internal(
                "Response does not have reports.".to_string(),
            ));
        }

        let reports = response.reports.as_ref().unwrap();
        if reports.is_empty() {
            return Err(ServerError::Internal(
                "Response does not have reports.".to_string(),
            ));
        }

        let report_data = (&reports[0]).data.as_ref().ok_or(ServerError::Internal(
            "Report does not have data.".to_string(),
        ))?;
        let report_rows = report_data.rows.as_ref().ok_or(ServerError::Internal(
            "Report does not have rows.".to_string(),
        ))?;

        for report_row in report_rows {
            let date = report_row
                .dimensions
                .as_ref()
                .ok_or(ServerError::Internal(
                    "Date is missing in the report row".to_string(),
                ))?
                .get(0)
                .ok_or(ServerError::Internal(
                    "Date is missing in the report row".to_string(),
                ))?;

            let num_visits = report_row
                .metrics
                .as_ref()
                .ok_or(ServerError::Internal(
                    "Metrics are missing in the report row".to_string(),
                ))?
                .get(0)
                .ok_or(ServerError::Internal(
                    "DateRangeValues are missing in the Metric".to_string(),
                ))?
                .values
                .as_ref()
                .ok_or(ServerError::Internal(
                    "Values are missing in the DateRangeValues".to_string(),
                ))?
                .get(0)
                .ok_or(ServerError::Internal("Value not found".to_string()))?
                .parse::<u32>()
                .unwrap();

            self.visitor_counts_per_day
                .write()
                .unwrap()
                .insert(date.clone(), num_visits);
        }

        Ok(())
    }
}
/*
pub fn start_analytics_api_worker(api_caller: Arc<GoogleAnalyticsApiCaller>) {
    tokio::spawn(async move {
        loop {
            println!("Read goog analytics");
            match api_caller.fetch().await {
                Err(e) => println!("Google Analytics Error : {}", e),
                Ok(_) => {}
            }

            // Read every 5 minutes.
            tokio::time::sleep(Duration::from_secs(300)).await;
        }
    });
}
    */

pub fn get_days_string_starting_from_today(num_days: i32) -> Vec<String> {
    let mut utc_time = Utc::now().with_timezone(&FixedOffset::east_opt(9 * 3600).unwrap());

    let mut date_vec = vec![];
    for _ in 0..num_days {
        date_vec.push(utc_time.format("%Y%m%d").to_string());
        utc_time = utc_time - chrono::Duration::days(1);
    }

    date_vec.reverse();
    date_vec
}
