use crate::context::context::{AppState, Context};
use crate::error::errors::ServerError;
use crate::user::user_info::UserInfo;
use axum::extract::{Json, State};
use axum_extra::extract::SignedCookieJar;
use serde::{Deserialize, Serialize};

const GOOG_CAPTCHA_TOKEN_VERIFY_URL: &str = "https://www.google.com/recaptcha/api/siteverify";

#[derive(Deserialize, Debug)]
pub struct WriteCommentRequest {
    article_url: String,
    content: String,

    parent_id: Option<i32>,
    password: String,
    author_name: Option<String>,
    captcha_token: String,
}

#[derive(Serialize)]
pub struct WriteCommentResponse {
    result: bool,
}

#[derive(Serialize, Deserialize, Debug)]
pub struct CaptchaResponse {
    success: bool,
}

pub async fn write_comment(
    State(context): State<AppState>,
    jar: SignedCookieJar,
    Json(request): Json<WriteCommentRequest>,
) -> Result<Json<WriteCommentResponse>, ServerError> {
    if request.content.is_empty() {
        return Err(ServerError::BadRequest("Comment is empty.".to_owned()));
    }

    let response = reqwest::Client::new()
        .post(GOOG_CAPTCHA_TOKEN_VERIFY_URL)
        .form(&[
            ("secret", "6LeE_nYUAAAAABelPPovV9f9DOAJSzqpTQTA4bt7"),
            ("response", &request.captcha_token),
        ])
        .send()
        .await?
        .json::<CaptchaResponse>()
        .await?;

    if !response.success {
        // TODO: Return error if not success for PROD env.
    }

    let user_info = UserInfo::get_user_info(jar);

    let author_name;
    let author_id;
    let author_email;
    let image_link;

    if let Some(user_info) = user_info {
        author_name = user_info.name;
        author_id = Some(user_info.user_id);
        author_email = user_info.email;
        image_link = user_info.image;
    } else if request.author_name.is_none() || request.author_name.as_ref().unwrap().is_empty() {
        return Err(ServerError::BadRequest(
            "Author name is imssing.".to_owned(),
        ));
    } else {
        author_name = request.author_name.unwrap();
        author_id = None;
        author_email = None;
        image_link = None;
    }

    context
        .comment_context()
        .create_comment(
            &request.article_url,
            request.parent_id,
            &request.content,
            &author_name,
            &request.password,
            author_id,
            author_email.as_deref(),
            image_link.as_deref(),
        )
        .await?;

    Ok(Json(WriteCommentResponse { result: true }))
}
