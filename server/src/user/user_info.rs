use crate::entity::users as Users;
use axum_extra::extract::{cookie::Cookie, SignedCookieJar};
use serde::{Deserialize, Serialize};

#[derive(Serialize, Deserialize, Debug)]
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
    pub fn get_user_info(jar: SignedCookieJar) -> Option<Self> {
        if let Some(session_serialized) = jar.get("user_info") {
            serde_json::from_str::<Self>(&session_serialized.to_string()).ok()
        } else {
            None
        }
    }

    pub fn write_user_info_to_cookie_jar(self, jar: SignedCookieJar) -> SignedCookieJar {
        jar.add(Cookie::new(
            "user_info",
            serde_json::to_string(&self).unwrap(),
        ))
    }
}
