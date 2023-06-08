use std::sync::Arc;

use crate::context::context::{Context, ProdContext};

pub fn start_periodic_jobs(prod_context: Arc<ProdContext>) {
    tokio::spawn(async move {
        loop {
            let stat_result = prod_context.site_stat_context().fetch_site_stat().await;
            if stat_result.is_err() {
                println!("Error: {:?}", stat_result.err());
            }

            let save_result = prod_context
                .article_context()
                .save_page_view_count_to_db()
                .await;
            if save_result.is_err() {
                println!("Error: {:?}", save_result.err());
            }

            tokio::time::sleep(std::time::Duration::from_secs(300)).await;
        }
    });
}
