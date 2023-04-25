//! `SeaORM` Entity. Generated by sea-orm-codegen 0.10.3

use sea_orm::entity::prelude::*;

#[derive(Clone, Debug, PartialEq, DeriveEntityModel, Eq)]
#[sea_orm(table_name = "comment")]
pub struct Model {
    #[sea_orm(primary_key)]
    pub comment_id: i32,
    pub article_url: String,
    pub reply_ids: Option<Vec<i32>>,
    pub comment_date: Option<DateTime>,
    pub modified_date: Option<DateTime>,
    pub author_name: Option<String>,
    pub author_email: Option<String>,
    pub image_link: Option<String>,
    #[sea_orm(column_type = "Text")]
    pub content: String,
    pub password: String,
    pub is_md: bool,
    pub is_deleted: Option<bool>,
    pub author_id: Option<i32>,
}

#[derive(Copy, Clone, Debug, EnumIter, DeriveRelation)]
pub enum Relation {
    #[sea_orm(
        belongs_to = "super::article::Entity",
        from = "Column::ArticleUrl",
        to = "super::article::Column::ArticleUrl",
        on_update = "NoAction",
        on_delete = "NoAction"
    )]
    Article,
}

impl Related<super::article::Entity> for Entity {
    fn to() -> RelationDef {
        Relation::Article.def()
    }
}

impl ActiveModelBehavior for ActiveModel {}
