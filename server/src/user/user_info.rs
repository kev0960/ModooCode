use crate::entity::users as Users;
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
