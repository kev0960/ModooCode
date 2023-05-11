use crate::entity::users as Users;
use axum_sessions::extractors::ReadableSession;
use serde::Serialize;

#[derive(Serialize)]
pub struct UserInfo {
    pub name: String,
    pub image: Option<String>,
    pub email: Option<String>,
}

impl From<Users::Model> for UserInfo {
    fn from(value: Users::Model) -> Self {
        Self {
            name: value.name,
            image: value.image,
            email: value.email,
        }
    }
}

impl UserInfo {
    pub fn get_user_info(session: ReadableSession) -> Option<Self> {
        if session.get::<String>("name").is_none() {
            return None;
        }

        Some(Self {
            name: session.get("name").unwrap_or_default(),
            image: session.get("image").unwrap_or_default(),
            email: session.get("email").unwrap_or_default(),
        })
    }
}
