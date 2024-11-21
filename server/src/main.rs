use axum::{
    routing::{get, post},
    Router,
};
use axum_extra::extract::cookie::Key;
use context::context::AppState;
use page::{
    get_comment::get_comment,
    page::{
        category_page_handler, index_page_handler, inst_page_handler, notice_page_handler,
        page_handler,
    },
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

    let secret = rand::thread_rng().gen::<[u8; 128]>();

    let state = AppState::new(
        ProdContext::new(
            &dotenv::var("DATABASE_URL").unwrap(),
            &dotenv::var("SERVICE_ACCOUNT_KEY_PATH").unwrap(),
            &dotenv::var("FILE_HEADERS").unwrap(),
            &dotenv::var("PAGE_PATH").unwrap(),
            &dotenv::var("VIEW_DIRECTORY_PATH").unwrap(),
            Key::from(&secret),
        )
        .await
        .unwrap(),
    );

    start_periodic_jobs(state.clone());

    let app = Router::new()
        .route("/", get(index_page_handler))
        // For article pages.
        .route("/:article_url", get(page_handler))
        .route("/category/*category_name", get(category_page_handler))
        .route("/en/inst/:article_url", get(inst_page_handler))
        .route("/notice/:notice_url", get(notice_page_handler))
        // For authentication.
        .route("/auth/goog", post(goog_login_handler))
        // Comment related.
        .route("/write-comment", post(write_comment))
        .route("/get-comment", post(get_comment))
        .with_state(state);

    let listener = tokio::net::TcpListener::bind("0.0.0.0:8080").await.unwrap();
    axum::serve(listener, app).await.unwrap();
}
