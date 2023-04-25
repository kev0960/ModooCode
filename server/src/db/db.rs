use sea_orm::DatabaseConnection;

use crate::error::errors::ServerError;

pub trait Database
where
    Self: Send + Sync,
{
    fn connection(&self) -> &DatabaseConnection;
}

pub struct ProdDatabase {
    connection: DatabaseConnection,
}

impl ProdDatabase {
    pub async fn new(connection_string: &str) -> Result<Self, ServerError> {
        Ok(Self {
            connection: sea_orm::Database::connect(connection_string).await?,
        })
    }
}

impl Database for ProdDatabase {
    fn connection(&self) -> &DatabaseConnection {
        &self.connection
    }
}
