use crate::entity::users as Users;
use axum_sessions::extractors::{ReadableSession, WritableSession};
use serde::Serialize;

#[derive(Serialize, Debug)]
pub struct UserInfo {
    pub user_id: i32,
    pub name: String,
    pub image: Option<String>,
    pub email: Option<String>,
}

impl From<Users::Model> for UserInfo {
    fn from(value: Users::Model) -> Self {
        Self {
            user_id: value.user_id,
            name: value.name,
            image: value.image,
            email: value.email,
        }
    }
}

impl UserInfo {
    pub fn get_user_info(session: ReadableSession) -> Option<Self> {
        if session.get::<i32>("user_id").is_none() || session.get::<String>("name").is_none() {
            return None;
        }

        Some(Self {
            user_id: session.get("user_id").unwrap_or_default(),
            name: session.get("name").unwrap_or_default(),
            image: session.get("image").unwrap_or_default(),
            email: session.get("email").unwrap_or_default(),
        })
    }

    pub fn write_user_info_to_session(self, mut session: WritableSession) {
        session.insert("user_id", self.user_id).unwrap();
        session.insert("name", self.name).unwrap();
        session.insert("image", self.image).unwrap();
        session.insert("email", self.email).unwrap();
    }
}
