use std::sync::Arc;

use axum::{
    routing::{get, post},
    Router,
};
use axum_sessions::{async_session::MemoryStore, SessionLayer};
use page::page::{index_page_handler, page_handler};
use rand::Rng;

use crate::context::context::ProdContext;

mod context;
mod db;
mod entity;
mod error;
mod page;
mod user;

#[tokio::main]
async fn main() {
    dotenv::from_filename(".env").ok();

    let store = MemoryStore::new();
    let secret = rand::thread_rng().gen::<[u8; 128]>();
    let session_layer = SessionLayer::new(store, &secret).with_secure(false);

    let state = Arc::new(
        ProdContext::new(
            &dotenv::var("DATABASE_URL").unwrap(),
            &dotenv::var("SERVICE_ACCOUNT_KEY_PATH").unwrap(),
            &dotenv::var("FILE_HEADERS").unwrap(),
        )
        .await
        .unwrap(),
    );

    let app = Router::new()
        .route("/", get(index_page_handler))
        .route("/:article_url", get(page_handler))
        .with_state(state)
        .layer(session_layer);

    axum::Server::bind(&"0.0.0.0:3000".parse().unwrap())
        .serve(app.into_make_service())
        .await
        .unwrap();
}
