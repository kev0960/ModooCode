use crate::context::context::{AppState, Context};

pub fn start_periodic_jobs(prod_context: AppState) {
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

            // Check Google certs key expiration periodically and refresh 2 hours before
            // expiration.
            if prod_context.user_context().get_expire_time()
                < chrono::Utc::now() - chrono::Duration::hours(2)
            {
                let refresh_result = prod_context.user_context().refresh_google_certs().await;
                if refresh_result.is_err() {
                    println!("Error: {:?}", refresh_result.err());
                }
            }

            tokio::time::sleep(std::time::Duration::from_secs(60)).await;
        }
    });
}
