use std::collections::{HashMap, HashSet};
use std::sync::Arc;

use async_trait::async_trait;
use chrono::NaiveDateTime;
use sea_orm::{entity::*, query::*};
use serde::Serialize;
use serde_json::Value;
use tokio::fs;

use crate::db::db::Database;
use crate::entity::article as Article;
use crate::error::errors::ServerError;

#[derive(sea_orm::FromQueryResult)]
struct ArticlePageAndViewCount {
    article_url: String,
    view_count: Option<i32>,
}

#[derive(Serialize, Debug)]
pub struct ArticleData {
    pub article_url: String,
    pub create_time: Option<NaiveDateTime>,
    pub update_time: Option<NaiveDateTime>,
    pub is_published: bool,
    pub is_deleted: bool,
    pub content: String,
    pub view_cnt: Option<i32>,
}

#[derive(Default, Debug, Clone, Serialize)]
pub struct CategoryMetadata {
    // 카테고리 이름. e.g. "C++".
    pub category_name: String,
    // 카테고리 전체 경로. e.g. ["C Reference","stdio.h"].
    pub category_full_path: Vec<String>,
    pub files: Vec<String>,
    pub child_categories: Vec<String>,
    pub total_num_articles_in_category: i32,
}

impl From<Article::Model> for ArticleData {
    fn from(value: Article::Model) -> Self {
        Self {
            article_url: value.article_url,
            create_time: value.create_time,
            update_time: value.update_time,
            is_published: value.is_published,
            is_deleted: value.is_deleted,
            content: value.content,
            view_cnt: value.view_cnt,
        }
    }
}

#[derive(Serialize, Debug, Clone)]
pub struct ArticleMetadata {
    pub article_url: String,
    pub category_title: String,
    pub publish_date: String,
    pub title: String,
    pub prev_page: String,
    pub next_page: String,
    pub is_published: bool,
}

#[async_trait]
pub trait ArticleContext
where
    Self: Send + Sync,
{
    async fn get_recent_articles(&self, num_articles: u64)
        -> Result<Vec<ArticleData>, ServerError>;

    async fn get_article_by_url(
        &self,
        article_url: &str,
    ) -> Result<Option<ArticleData>, ServerError>;

    fn get_category_metadata(&self, category_name: &[String]) -> Option<&CategoryMetadata>;

    // Get the category metadata that the article belongs.
    fn get_category_that_article_belongs(&self, article_url: &str) -> Option<&CategoryMetadata>;

    fn multi_get_article_metadata(&self, article_urls: &[String]) -> Vec<Option<ArticleMetadata>>;

    // Get metadata of every article available.
    fn get_every_article_metadata(&self) -> Vec<ArticleMetadata>;

    // Get every category available.
    fn get_every_category_metadata(&self) -> Vec<CategoryMetadata>;

    // 증가된 현재 page view count 를 return 한다.
    fn increment_page_view_count(&self, article_url: &str) -> u32;

    // 페이지들의 view count 를 리턴한다.
    fn get_page_view_counts(&self, article_urls: &[String]) -> Vec<Option<u32>>;

    // Returns if the article_url is the instruction.
    fn is_instruction(&self, article_url: &str) -> bool;

    // Cache 된 page view count 를 db 에 저장.
    async fn save_page_view_count_to_db(&self) -> Result<(), ServerError>;
}

pub struct ProdArticleContext {
    database: Arc<dyn Database>,
    article_metadata: HashMap<String, ArticleMetadata>,

    // 페이지 별 조회수 담은 map.
    page_view_counts_map: std::sync::Mutex<HashMap<String, (u32, /*synced=*/ bool)>>,

    // 카테고리 별 정보들.
    category_path_to_metadata_map: HashMap<Vec<String>, CategoryMetadata>,

    // Article url to Category path.
    article_url_to_category_path: HashMap<String, Vec<String>>,

    // Reference 가능한 모든 명령어 모음.
    instruction_pages: HashSet<String>,
}

#[async_trait]
impl ArticleContext for ProdArticleContext {
    async fn get_recent_articles(
        &self,
        num_articles: u64,
    ) -> Result<Vec<ArticleData>, ServerError> {
        Ok(Article::Entity::find()
            .filter(
                Condition::all()
                    .add(Article::Column::IsDeleted.eq(false))
                    .add(Article::Column::IsPublished.eq(true)),
            )
            .order_by_desc(Article::Column::CreateTime)
            .limit(num_articles)
            .all(self.database.connection())
            .await?
            .into_iter()
            .map(|a| a.into())
            .collect())
    }

    async fn get_article_by_url(
        &self,
        article_url: &str,
    ) -> Result<Option<ArticleData>, ServerError> {
        let article = Article::Entity::find_by_id(article_url)
            .one(self.database.connection())
            .await?;

        Ok(article.map(|a| a.into()))
    }

    fn get_category_metadata(&self, category_name: &[String]) -> Option<&CategoryMetadata> {
        self.category_path_to_metadata_map.get(category_name)
    }

    fn get_category_that_article_belongs(&self, article_url: &str) -> Option<&CategoryMetadata> {
        if let Some(category_path) = self.article_url_to_category_path.get(article_url) {
            return self.get_category_metadata(category_path);
        }

        None
    }

    fn multi_get_article_metadata(&self, article_urls: &[String]) -> Vec<Option<ArticleMetadata>> {
        article_urls
            .into_iter()
            .map(|url| self.article_metadata.get(url).map(|m| m.to_owned()))
            .collect()
    }

    fn get_every_article_metadata(&self) -> Vec<ArticleMetadata> {
        self.article_metadata
            .values()
            .map(|a| a.to_owned())
            .collect()
    }

    fn get_every_category_metadata(&self) -> Vec<CategoryMetadata> {
        self.category_path_to_metadata_map
            .values()
            .map(|m| m.clone())
            .collect()
    }

    fn increment_page_view_count(&self, article_url: &str) -> u32 {
        let mut page_view_count_map = self.page_view_counts_map.lock().unwrap();
        if let Some((view_count, _)) = page_view_count_map.get_mut(article_url) {
            *view_count += 1;

            return *view_count;
        } else {
            page_view_count_map.insert(article_url.to_owned(), (1, true));

            return 1;
        }
    }

    fn get_page_view_counts(&self, article_urls: &[String]) -> Vec<Option<u32>> {
        let page_view_count_map = self.page_view_counts_map.lock().unwrap();
        article_urls
            .into_iter()
            .map(|url| page_view_count_map.get(url).map(|v| v.0))
            .collect()
    }

    async fn save_page_view_count_to_db(&self) -> Result<(), ServerError> {
        let mut pages_to_update_views = vec![];
        {
            let page_view_counts_map = self.page_view_counts_map.lock().unwrap();
            for (article_url, (view_count, is_synced)) in page_view_counts_map.iter() {
                if !is_synced {
                    pages_to_update_views.push((article_url.to_owned(), *view_count));
                }
            }
        }

        let mut view_count_updates = vec![];
        for (article_url, view_count) in pages_to_update_views {
            view_count_updates.push(
                Article::ActiveModel {
                    article_url: Set(article_url),
                    view_cnt: Set(Some(view_count as i32)),
                    ..Default::default()
                }
                .update(self.database.connection()),
            )
        }

        futures::future::join_all(view_count_updates).await;

        Ok(())
    }

    fn is_instruction(&self, article_url: &str) -> bool {
        self.instruction_pages.contains(article_url)
    }
}

fn get_string_from_json_value(val: Option<&Value>) -> String {
    match val {
        Some(val) => val.as_str().unwrap_or_default().to_owned(),
        _ => "".to_owned(),
    }
}

fn get_instruction_references_in_page_path_json(val: &Value) -> HashSet<String> {
    let mut inst_names = HashSet::new();

    let inst_references = val
        .get("")
        .unwrap()
        .as_object()
        .unwrap()
        .get("X86-64 명령어 레퍼런스")
        .unwrap()
        .as_object()
        .unwrap();
    for (_, inst_references) in inst_references {
        if let Some(files) = inst_references.get("files") {
            for title in files.as_array().unwrap() {
                inst_names.insert(title.as_str().unwrap().to_owned());
            }
        }
    }

    inst_names
}

impl ProdArticleContext {
    pub async fn new(
        database: Arc<dyn Database>,
        file_header_json_path: &str,
        page_path_json_path: &str,
    ) -> Result<Self, ServerError> {
        let mut article_metadata = HashMap::new();
        let file_header_json = fs::read_to_string(file_header_json_path).await.unwrap();
        for (article_url, page_data) in serde_json::from_str::<Value>(&file_header_json)
            .unwrap()
            .as_object()
            .unwrap()
        {
            let page_data = page_data.as_object().unwrap();
            article_metadata.insert(
                article_url.to_owned(),
                ArticleMetadata {
                    article_url: article_url.to_owned(),
                    title: get_string_from_json_value(page_data.get("title")),
                    category_title: get_string_from_json_value(page_data.get("cat_title")),
                    publish_date: get_string_from_json_value(page_data.get("publish_date")),
                    prev_page: get_string_from_json_value(page_data.get("prev_page")),
                    next_page: get_string_from_json_value(page_data.get("next_page")),
                    is_published: get_string_from_json_value(page_data.get("is_published"))
                        != "false",
                },
            );
        }

        let page_path_json = fs::read_to_string(page_path_json_path).await.unwrap();
        let page_path_json = serde_json::from_str::<Value>(&page_path_json).unwrap();

        let (category_path_to_metadata_map, article_url_to_category_path) =
            build_category_metadata_map(&page_path_json, &article_metadata);
        Ok(ProdArticleContext {
            article_metadata,
            page_view_counts_map: std::sync::Mutex::new(
                Self::get_article_visitor_counts(&*database).await?,
            ),
            database,
            category_path_to_metadata_map,
            article_url_to_category_path,
            instruction_pages: get_instruction_references_in_page_path_json(&page_path_json),
        })
    }

    async fn get_article_visitor_counts(
        db: &dyn Database,
    ) -> Result<HashMap<String, (u32, bool)>, ServerError> {
        Ok(Article::Entity::find()
            .select_only()
            .column_as(Article::Column::ArticleUrl, "article_url")
            .column_as(Article::Column::ViewCnt, "view_count")
            .into_model::<ArticlePageAndViewCount>()
            .all(db.connection())
            .await?
            .into_iter()
            .map(|page_and_view_count| {
                (
                    page_and_view_count.article_url,
                    (
                        page_and_view_count.view_count.unwrap_or_default() as u32,
                        true,
                    ),
                )
            })
            .collect())
    }
}

fn build_category_metadata_map(
    page_path_json: &Value,
    article_metadata: &HashMap<String, ArticleMetadata>,
) -> (
    HashMap<Vec<String>, CategoryMetadata>,
    HashMap<String, Vec<String>>,
) {
    let root_pages = page_path_json
        .as_object()
        .unwrap()
        .get("")
        .unwrap()
        .as_object()
        .unwrap();

    let mut root_child_categories = vec![];

    let mut category_path_to_metadata_map = HashMap::new();
    let mut article_url_to_category_path_map = HashMap::new();
    for (category_name, pages) in root_pages {
        if category_name == "files" {
            continue;
        }

        build_category_metadata_map_helper(
            category_name.trim(),
            &Vec::new(),
            pages,
            &mut category_path_to_metadata_map,
            &mut article_url_to_category_path_map,
            article_metadata,
        );

        root_child_categories.push(category_name.clone());
    }

    category_path_to_metadata_map.insert(
        vec![],
        CategoryMetadata {
            category_name: "전체 카테고리".to_owned(),
            category_full_path: vec![],
            files: vec![],
            child_categories: root_child_categories,
            // Equals to the total number of articles.
            total_num_articles_in_category: article_url_to_category_path_map.len() as i32,
        },
    );

    (
        category_path_to_metadata_map,
        article_url_to_category_path_map,
    )
}

fn build_category_metadata_map_helper(
    category_name: &str,
    parent_path: &Vec<String>,
    category_info: &Value,
    category_path_to_metadata_map: &mut HashMap<Vec<String>, CategoryMetadata>,
    article_url_to_category_path_map: &mut HashMap<String, Vec<String>>,
    article_metadata: &HashMap<String, ArticleMetadata>,
) -> CategoryMetadata {
    let category_info = category_info.as_object().unwrap();

    let mut category_metadata = CategoryMetadata::default();
    category_metadata.category_name = category_name.to_owned();

    let mut current_category_childs = Vec::new();
    let mut total_num_articles = 0;

    let mut current_path = parent_path.clone();
    current_path.push(category_name.to_owned());

    for (child_category_name, child_category) in category_info {
        if child_category_name == "files" {
            category_metadata.files = child_category
                .as_array()
                .unwrap()
                .iter()
                .map(|p| p.as_str().unwrap().to_owned())
                .filter_map(|url| {
                    let metadata = article_metadata.get(&url);
                    if let Some(metadata) = metadata {
                        if metadata.is_published {
                            return Some(url);
                        }
                    }
                    None
                })
                .collect();
            total_num_articles += child_category.as_array().unwrap().len() as i32;

            for article_url in &category_metadata.files {
                article_url_to_category_path_map.insert(article_url.clone(), current_path.clone());
            }
        } else {
            let child_metadata = build_category_metadata_map_helper(
                child_category_name.trim(),
                &current_path,
                child_category,
                category_path_to_metadata_map,
                article_url_to_category_path_map,
                article_metadata,
            );
            total_num_articles += child_metadata.total_num_articles_in_category;

            current_category_childs.push(child_category_name.trim().to_owned());
        }
    }

    category_metadata.child_categories = current_category_childs;
    category_metadata.category_full_path = current_path.clone();
    category_metadata.total_num_articles_in_category = total_num_articles;

    category_path_to_metadata_map.insert(current_path, category_metadata.clone());
    category_metadata
}
