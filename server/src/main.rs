use std::sync::Arc;

use axum::{
    routing::{get, post},
    Router,
};
use page::page::{index_page_handler, page_handler};

use crate::context::context::ProdContext;

mod context;
mod db;
mod entity;
mod error;
mod page;

#[tokio::main]
async fn main() {
    dotenv::from_filename(".env").ok();

    let state = Arc::new(
        ProdContext::new(
            &dotenv::var("DATABASE_URL").unwrap(),
            &dotenv::var("SERVICE_ACCOUNT_KEY_PATH").unwrap(),
        )
        .await
        .unwrap(),
    );

    let app = Router::new()
        .route("/", get(index_page_handler))
        .route("/:article_url", get(page_handler))
        .with_state(state);

    axum::Server::bind(&"0.0.0.0:3000".parse().unwrap())
        .serve(app.into_make_service())
        .await
        .unwrap();
}
