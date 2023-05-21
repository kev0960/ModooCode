use std::collections::HashMap;
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

    fn multi_get_article_metadata(&self, article_urls: &[String]) -> Vec<Option<ArticleMetadata>>;

    // Get metadata of every article available.
    fn get_every_article_metadata(&self) -> Vec<ArticleMetadata>;

    fn get_category_listing_of_article(&self, article_url: &str) -> Option<String>;

    // 증가된 현재 page view count 를 return 한다.
    fn increment_page_view_count(&self, article_url: &str) -> u32;

    // Cache 된 page view count 를 db 에 저장.
    async fn save_page_view_count_to_db(&self) -> Result<(), ServerError>;
}

pub struct ProdArticleContext {
    database: Arc<dyn Database>,
    article_metadata: HashMap<String, ArticleMetadata>,

    // 페이지 별 조회수 담은 map.
    page_view_counts_map: std::sync::Mutex<HashMap<String, (u32, /*synced=*/ bool)>>,

    // Page 별 category listing.
    category_listing_map: HashMap<String, String>,
}

#[async_trait]
impl ArticleContext for ProdArticleContext {
    async fn get_recent_articles(
        &self,
        num_articles: u64,
    ) -> Result<Vec<ArticleData>, ServerError> {
        Ok(Article::Entity::find()
            .filter(Article::Column::IsDeleted.eq(false))
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

    fn get_category_listing_of_article(&self, article_url: &str) -> Option<String> {
        self.category_listing_map
            .get(article_url)
            .map(|category| category.to_owned())
    }
}

fn get_string_from_json_value(val: Option<&Value>) -> String {
    match val {
        Some(val) => val.as_str().unwrap_or_default().to_owned(),
        _ => "".to_owned(),
    }
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
                },
            );
        }

        let page_path_json = fs::read_to_string(page_path_json_path).await.unwrap();
        let page_path_json = serde_json::from_str::<Value>(&page_path_json).unwrap();

        let category_listing_map = build_category_listing_helper(
            &page_path_json,
            &article_metadata,
            "".to_owned(),
            1,
        );

        Ok(ProdArticleContext {
            article_metadata,
            page_view_counts_map: std::sync::Mutex::new(
                Self::get_article_visitor_counts(&*database).await?,
            ),
            database,
            category_listing_map
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

fn build_category_listing_helper(
    root: &Value,
    article_metdata_map: &HashMap<String, ArticleMetadata>,
    mut category_html: String,
    dir_depth: u64,
) -> HashMap<String, String> {
    let mut page_to_html = HashMap::<String, String>::new();

    if dir_depth != 1 {
        category_html.push_str(&format!("<div class='inner-menu{}'>", dir_depth - 1));
    }
    for (dir_name, folder) in root.as_object().unwrap() {
        if dir_name == "files" {
            // Case where file is taken.
            let files = folder.as_array().unwrap();
            for chosen_file in 0..files.len() {
                let mut html = category_html.clone();
                for i in 0..chosen_file {
                    let article_url = files[i].as_str().unwrap();
                    html.push_str(&format!(
                        "<a class='sidebar-nav-item file' href='/{}' \
                             name='{}'>{}</a>\n",
                        article_url,
                        article_url,
                        article_metdata_map
                            .get(article_url)
                            .map_or("".to_string(), |metadata| {
                                metadata.category_title.to_owned()
                            })
                    ));
                }

                let article_url = files[chosen_file].as_str().unwrap();
                html.push_str(&format!(
                    "<a class='sidebar-nav-item file' href='/{}' \
                         name='{}' style='background-color: rgba(255, 255, \
                         255, 0.33);'>{}</a>\n",
                    article_url,
                    article_url,
                    article_metdata_map
                        .get(article_url)
                        .map_or("".to_string(), |metadata| {
                            metadata.category_title.to_owned()
                        })
                ));

                for i in chosen_file + 1..files.len() {
                    let article_url = files[i].as_str().unwrap();
                    html.push_str(&format!(
                        "<a class='sidebar-nav-item file' href='/{}' \
                             name='{}'>{}</a>\n",
                        article_url,
                        article_url,
                        article_metdata_map
                            .get(article_url)
                            .map_or("".to_string(), |metadata| {
                                metadata.category_title.to_owned()
                            })
                    ));
                }

                page_to_html.insert(files[chosen_file].as_str().unwrap().to_string(), html);
            }
        } else {
            // The case where the dir is open.
            let mut when_dir_open = category_html.clone();
            when_dir_open.push_str(&format!(
                concat!(
                    "<a class='sidebar-nav-item dir open-cat' name='{}'>",
                    "<i class='xi-caret-down-min' \
                         style='font-size:0.75em;'></i>&nbsp;&nbsp;{}</a>\n"
                ),
                dir_name, dir_name
            ));

            let children_html = build_category_listing_helper(
                folder,
                article_metdata_map,
                when_dir_open,
                dir_depth + 1,
            );

            // The case where the dir is not open.
            let dir_html = format!(
                "<a class='sidebar-nav-item dir' name='{}'><i \
                     class='xi-plus-square' \
                     style='font-size:0.75em;'></i>&nbsp;&nbsp;{}</a>\n",
                dir_name, dir_name
            );
            category_html.push_str(&dir_html);

            for html in page_to_html.values_mut() {
                html.push_str(&dir_html);
            }

            page_to_html.extend(children_html);
        }
    }

    if dir_depth != 1 {
        for html in page_to_html.values_mut() {
            html.push_str("</div>");
        }
    }

    page_to_html
}
