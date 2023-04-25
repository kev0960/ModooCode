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
}
