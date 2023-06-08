use std::sync::Arc;

use axum::{
    routing::{get, post},
    Router,
};
use axum_sessions::{async_session::MemoryStore, SessionLayer};
use page::{
    page::{index_page_handler, page_handler},
    write_comment::write_comment,
};
use rand::Rng;
use scheduler::scheduler::start_periodic_jobs;
use user::goog_login::goog_login_handler;

use crate::context::context::ProdContext;

mod context;
mod db;
mod entity;
mod error;
mod page;
mod scheduler;
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
            &dotenv::var("PAGE_PATH").unwrap(),
        )
        .await
        .unwrap(),
    );

    start_periodic_jobs(state.clone());

    let app = Router::new()
        .route("/", get(index_page_handler))
        .route("/:article_url", get(page_handler))
        .route("/auth/goog", post(goog_login_handler))
        .route("/write-comment", post(write_comment))
        .with_state(state)
        .layer(session_layer);

    axum::Server::bind(&"0.0.0.0:8080".parse().unwrap())
        .serve(app.into_make_service())
        .await
        .unwrap();
}
