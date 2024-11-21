use axum::response::IntoResponse;
use hyper::StatusCode;
use thiserror::Error;

#[derive(Error, Debug)]
pub enum ServerError {
    #[error("Invalid request error: {0}")]
    BadRequest(String),

    #[error("Internal error: {0}")]
    Internal(String),

    #[error("Database error: {0}")]
    DatabaseError(#[from] sea_orm::DbErr),

    #[error("serde Json error: {0}")]
    JsonError(#[from] serde_json::Error),

    #[error("bad jwt: {0}")]
    BadJWT(#[from] jsonwebtoken::errors::Error),

    #[error("reqwest error: {0}")]
    BadReqwest(#[from] reqwest::Error),

    #[error("io error: {0}")]
    IoError(#[from] std::io::Error),
}

impl IntoResponse for ServerError {
    fn into_response(self) -> axum::response::Response {
        println!("Error : {:?}", self);
        match self {
            ServerError::BadRequest(e) => (StatusCode::BAD_REQUEST, e.to_string()).into_response(),
            ServerError::Internal(e) => {
                (StatusCode::INTERNAL_SERVER_ERROR, e.to_string()).into_response()
            }
            ServerError::DatabaseError(e) => {
                (StatusCode::INTERNAL_SERVER_ERROR, e.to_string()).into_response()
            }
            ServerError::JsonError(e) => {
                (StatusCode::INTERNAL_SERVER_ERROR, e.to_string()).into_response()
            }
            ServerError::BadJWT(e) => {
                (StatusCode::INTERNAL_SERVER_ERROR, e.to_string()).into_response()
            }
            ServerError::BadReqwest(e) => {
                (StatusCode::INTERNAL_SERVER_ERROR, e.to_string()).into_response()
            }
            ServerError::IoError(e) => {
                (StatusCode::INTERNAL_SERVER_ERROR, e.to_string()).into_response()
            }
        }
    }
}
