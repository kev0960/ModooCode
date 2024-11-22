use crate::context::context::{AppState, Context};
use crate::error::errors::ServerError;
use axum::extract::{Json, State};
use axum::response::IntoResponse;
use axum_extra::extract::cookie::SignedCookieJar;
use serde::{Deserialize, Serialize};

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
    State(context): State<AppState>,
    jar: SignedCookieJar,
    Json(request): Json<GoogLoginRequest>,
) -> Result<impl IntoResponse, ServerError> {
    let user_info = context
        .user_context()
        .authenticate_user(&request.token)
        .await?;

    let jar = user_info.write_user_info_to_cookie_jar(jar);
    println!("jar : {:?}", jar);

    Ok((jar, Json(GoogLoginResponse { result: true })))
}
