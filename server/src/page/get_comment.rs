use crate::context::comment_context::{CommentData, ARTICLE_COMMENT_PAGE_SIZE};
use crate::context::context::{Context, ProdContext};
use crate::error::errors::ServerError;
use axum::extract::{Json, State};
use serde::{Deserialize, Serialize};
use std::sync::Arc;

#[derive(Deserialize, Debug)]
pub struct GetCommentRequest {
    article_url: String,
    index_start: i32,
}

#[derive(Serialize)]
pub struct GetCommentResponse {
    comments: Vec<CommentData>,
}

pub async fn get_comment(
    State(context): State<Arc<ProdContext>>,
    Json(request): Json<GetCommentRequest>,
) -> Result<Json<GetCommentResponse>, ServerError> {
    let page_to_fetch = (request.index_start as u64) / ARTICLE_COMMENT_PAGE_SIZE;

    let comments = context
        .comment_context()
        .get_comments_on_article(&request.article_url, page_to_fetch)
        .await?;

    Ok(Json(GetCommentResponse { comments }))
}
