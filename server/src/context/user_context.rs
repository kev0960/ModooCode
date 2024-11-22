use std::collections::HashMap;
use std::sync::{Arc, Mutex};

use async_trait::async_trait;
use jsonwebtoken::{decode, decode_header, Algorithm, DecodingKey, Validation};
use sea_orm::{entity::*, query::*};
use serde::Deserialize;

use crate::db::db::Database;
use crate::entity::users as Users;
use crate::error::errors::ServerError;
use crate::user::user_info::UserInfo;

const GOOGLE_CERT_URL: &str = "https://www.googleapis.com/oauth2/v3/certs";

// Dead codes are allowed since these fields are part of the Google Certs but not really used.
#[allow(dead_code)]
#[derive(Deserialize)]
pub struct GoogleJwtClaims {
    pub sub: String, // Auth id.
    pub email: String,
    pub name: String,
    pub picture: Option<String>,
    iss: String,
    aud: String,
    azp: String,
    exp: i64,
    email_verified: bool,
    given_name: Option<String>,
    family_name: Option<String>,
}

#[async_trait]
pub trait UserContext
where
    Self: Send + Sync,
{
    async fn authenticate_user(&self, token: &str) -> Result<UserInfo, ServerError>;
    async fn refresh_google_certs(&self) -> Result<(), ServerError>;
    fn get_expire_time(&self) -> chrono::DateTime<chrono::Utc>;
}

pub struct ProdUserContext {
    database: Arc<dyn Database>,
    // Map between kid to Google cert.
    goog_cert: Mutex<HashMap<String, GoogleCertificate>>,

    // Time that current goog cert expires.
    // After this time, certs must be fetched again from the server.
    expire_time: Mutex<chrono::DateTime<chrono::Utc>>,
}

#[derive(Debug, Deserialize)]
struct GoogleCertificate {
    kid: String,
    n: String,
    e: String,
}

#[derive(Debug, Deserialize)]
struct GoogleCertsResponse {
    keys: Vec<GoogleCertificate>,
}

impl ProdUserContext {
    pub async fn new(database: Arc<dyn Database>) -> Self {
        let init_context = Self {
            database,
            goog_cert: Mutex::new(HashMap::new()),
            expire_time: Mutex::new(chrono::Utc::now()),
        };

        init_context.refresh_google_certs().await.unwrap();

        init_context
    }

    fn validate_google_login_token(
        &self,
        token: &str,
    ) -> Result<Option<GoogleJwtClaims>, ServerError> {
        let header = decode_header(token)?;
        let kid = &header.kid;
        if kid.is_none() {
            return Err(ServerError::BadRequest(format!(
                "kid in jwt is missing: header {:?}",
                header
            )));
        }

        let cert_n;
        let cert_e;

        {
            let cert_map = self.goog_cert.lock().unwrap();
            let cert = cert_map.get(kid.as_ref().unwrap());
            if cert.is_none() {
                return Ok(None);
            }

            cert_n = cert.as_ref().unwrap().n.clone();
            cert_e = cert.as_ref().unwrap().e.clone();
        }

        let decoding_key = DecodingKey::from_rsa_components(&cert_n, &cert_e)?;

        let mut validation = Validation::new(Algorithm::RS256);
        validation.validate_aud = false;

        let result = decode::<GoogleJwtClaims>(token, &decoding_key, &validation)?;
        Ok(Some(result.claims))
    }

    async fn get_user_from_auth_id(&self, auth_id: &str) -> Result<Option<UserInfo>, ServerError> {
        Ok(Users::Entity::find()
            .filter(Users::Column::AuthId.eq(Some(auth_id)))
            .one(self.database.connection())
            .await?
            .map(|user_info| user_info.into()))
    }

    async fn create_user(&self, goog_jwt: GoogleJwtClaims) -> Result<UserInfo, ServerError> {
        Ok(Users::ActiveModel {
            email: Set(Some(goog_jwt.email)),
            name: Set(goog_jwt.name),
            image: Set(goog_jwt.picture),
            auth_id: Set(Some(goog_jwt.sub)),
            auth_type: Set(Some("goog".to_owned())),
            ..Default::default()
        }
        .insert(self.database.connection())
        .await?
        .into())
    }
}

#[async_trait]
impl UserContext for ProdUserContext {
    async fn authenticate_user(&self, token: &str) -> Result<UserInfo, ServerError> {
        let jwt_claim = self.validate_google_login_token(token)?;

        if jwt_claim.is_none() {
            return Err(ServerError::BadRequest(
                "Google authentication failed.".to_owned(),
            ));
        }

        let jwt_claim = jwt_claim.unwrap();
        let auth_id = &jwt_claim.sub;

        let user_info = self.get_user_from_auth_id(&auth_id).await?;
        if user_info.is_some() {
            return Ok(user_info.unwrap());
        }

        // The user does not exist yet, so we need to create one.
        Ok(self.create_user(jwt_claim).await?)
    }

    async fn refresh_google_certs(&self) -> Result<(), ServerError> {
        let response = reqwest::get(GOOGLE_CERT_URL).await?;
        let expires = response.headers().get(reqwest::header::EXPIRES);

        if expires.is_none() {
            return Err(ServerError::Internal(
                "'expires' is missing from the response.".to_owned(),
            ));
        }

        let expires = expires.unwrap();
        *self.expire_time.lock().unwrap() =
            chrono::DateTime::parse_from_rfc2822(expires.to_str().unwrap())
                .unwrap()
                .with_timezone(&chrono::Utc);

        let certs_response = response.json::<GoogleCertsResponse>().await?;
        let mut certs = self.goog_cert.lock().unwrap();
        certs.clear();

        for cert in certs_response.keys {
            certs.insert(cert.kid.clone(), cert);
        }

        Ok(())
    }

    fn get_expire_time(&self) -> chrono::DateTime<chrono::Utc> {
        *self.expire_time.lock().unwrap()
    }
}
