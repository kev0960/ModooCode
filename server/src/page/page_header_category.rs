use serde_json::Value;

fn get_category_link(category_name: &str) -> String {
    format!("/category/{}", category_name)
}

fn get_category_name_sanitized(category_name: &str) -> &str {
    match category_name {
        "C" => "C 언어",
        "C Reference" => "C 레퍼런스",
        "C++ Reference" => "C++ 레퍼런스",
        _ => category_name,
    }
}

pub fn create_page_header_category_list(page_infos_json: &str) -> String {
    let page_infos: Value = serde_json::from_str(page_infos_json).unwrap();
    let root_pages = page_infos
        .as_object()
        .unwrap()
        .get("")
        .unwrap()
        .as_object()
        .unwrap();

    let mut html = "<ul class='header-category-list'>\n".to_owned();
    for (category_name, pages) in root_pages {
        if category_name == "files" {
            continue;
        }

        html += &format!(
            r#"<li class="category-item"><a class="category-item-link" href="{}">{}</a>"#,
            get_category_link(category_name),
            get_category_name_sanitized(category_name)
        );

        let num_files_in_pages = pages
            .as_object()
            .unwrap()
            .get("files")
            .map_or(0, |files| files.as_array().unwrap().len());

        let directories = pages
            .as_object()
            .unwrap()
            .iter()
            .filter_map(|(dir_name, article_pages)| match dir_name.as_str() {
                "files" => None,
                _ => Some((dir_name, article_pages)),
            })
            .collect::<Vec<_>>();

        if num_files_in_pages == 0 && directories.len() > 0 {
            html += r#"<ul class="header-category-dropdown">"#;
            for (dir_name, _) in directories {
                html += &format!(
                    r#"<li class="header-category-dropdown-item"><a class="category-item-link" href="/category/{}/{}">{}</a></li>"#,
                    category_name, dir_name, dir_name
                );
            }
            html += "</ul>";
        }
        html += "</li>\n";
    }
    html += "</ul>";

    html
}
