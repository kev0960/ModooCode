use crate::context::context::{Context, ProdContext};
use crate::error::errors::ServerError;
use axum::extract::{Json, State};
use axum_sessions::extractors::WritableSession;
use serde::{Deserialize, Serialize};
use std::sync::Arc;

#[derive(Deserialize, Debug)]
pub struct GoogLoginRequest {
    token: String,
}

#[derive(Serialize)]
pub struct GoogLoginResponse {
    result: bool,
}

#[axum_macros::debug_handler]
pub async fn goog_login_handler(
    State(context): State<Arc<ProdContext>>,
    session: WritableSession,
    Json(request): Json<GoogLoginRequest>,
) -> Result<Json<GoogLoginResponse>, ServerError> {
    let user_info = context
        .user_context()
        .authenticate_user(&request.token)
        .await?;

    user_info.write_user_info_to_session(session);

    Ok(Json(GoogLoginResponse { result: true }))
}
