use crate::context::comment_context::ARTICLE_COMMENT_PAGE_SIZE;
use crate::context::context::{AppState, Context, ProdContext};
use crate::error::errors::ServerError;
use axum::extract::{Json, State};
use serde::{Deserialize, Serialize};

#[derive(Deserialize, Debug)]
pub struct GetCommentRequest {
    article_url: String,
    index_start: i32,
}

#[derive(Serialize)]
pub struct RenderableCommentData {
    pub comment_id: i32,
    pub article_url: String,
    pub reply_ids: Option<Vec<i32>>,
    pub comment_date: Option<String>,
    pub author_name: Option<String>,
    pub image_link: Option<String>,
    pub content: String,
    pub is_md: bool,
}

#[derive(Serialize)]
pub struct GetCommentResponse {
    comments: Vec<RenderableCommentData>,
}

pub async fn get_comment(
    State(context): State<AppState>,
    Json(request): Json<GetCommentRequest>,
) -> Result<Json<GetCommentResponse>, ServerError> {
    let page_to_fetch = (request.index_start as u64) / ARTICLE_COMMENT_PAGE_SIZE;

    let comments = context
        .comment_context()
        .get_comments_on_article(&request.article_url, page_to_fetch)
        .await?
        .into_iter()
        .map(|c| RenderableCommentData {
            comment_id: c.comment_id,
            article_url: c.article_url,
            reply_ids: c.reply_ids,
            comment_date: c.comment_date.map_or(None, |d| Some(format!("{}", d))),
            author_name: c.author_name,
            content: c.content,
            image_link: c.image_link,
            is_md: c.is_md,
        })
        .collect();

    Ok(Json(GetCommentResponse { comments }))
}
