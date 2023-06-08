use std::collections::{BTreeSet, HashMap};

use crate::context::comment_context::CommentData;
use chrono::{Datelike, Timelike};
use html_escape::encode_text;

pub fn get_root_comments(comments: &HashMap<i32, CommentData>) -> Vec<i32> {
    let mut comment_ids = BTreeSet::new();
    for id in comments.keys() {
        comment_ids.insert(id.clone());
    }

    let comment_ids_vec: Vec<i32> = comment_ids.iter().cloned().collect();
    for id in comment_ids_vec {
        if comment_ids.get(&id).is_none() {
            continue;
        }

        let comment = comments.get(&id).unwrap();
        let mut reply_ids = match &comment.reply_ids {
            Some(reply_ids) => reply_ids.clone(),
            None => vec![],
        };

        while !reply_ids.is_empty() {
            let reply = reply_ids.pop().unwrap();
            comment_ids.remove(&reply);

            // Add the reply id of the reply.
            reply_ids.extend(
                comments
                    .get(&reply)
                    .unwrap()
                    .reply_ids
                    .as_ref()
                    .map_or(vec![], |ids| ids.clone()),
            );
        }
    }

    comment_ids.iter().cloned().collect()
}

fn create_html_of_comment(comments: &HashMap<i32, CommentData>, id: &i32) -> String {
    let comment = comments.get(id).unwrap();
    if comment.is_deleted.unwrap()
        && comment
            .reply_ids
            .as_ref()
            .map_or(vec![], |ids| ids.clone())
            .is_empty()
    {
        return "".to_string();
    }

    let mut html = "".to_string();
    html.push_str("<li class='comment'>");
    html.push_str("<div class='comment-profile'>");

    if let Some(image_link) = comment.image_link.as_ref() {
        if !image_link.is_empty() {
            html.push_str(&format!(
                "<img src='{}' alt='프로필 사진 없음'>",
                image_link
            ));
        } else {
            html.push_str("<img src='./img/unknown_person.png' alt='프로필 사진 없음'>");
        }
    } else {
        html.push_str("<img src='./img/unknown_person.png' alt='프로필 사진 없음'>");
    }

    html.push_str("</div><div class='comment-info'>");

    let comment_date = comment.comment_date.unwrap_or_default();
    let comment_date = format!(
        "{} {}-{} {:02}:{:02}:{:02}",
        comment_date.year(),
        comment_date.month(),
        comment_date.day(),
        comment_date.hour(),
        comment_date.minute(),
        comment_date.second()
    );

    let author_name = match &comment.author_name {
        Some(name) => name.to_owned(),
        None => "".to_owned(),
    };

    // Comment header.
    html.push_str(&format!(
        "<div class='comment-header'><span \
         class='comment-author'>{}</span><span \
         class='comment-date'>{}</span></div>",
        encode_text(&author_name),
        comment_date
    ));

    // Comment content.
    html.push_str(&format!(
        "<div class='comment-content'>{}</div>",
        encode_text(&comment.content)
    ));

    // Comment action.
    html.push_str(&format!(
        "<div class='comment-action' id='comment-id-{}'><span \
         class='comment-upvote'>추천</span><span class='comment-reply'>답글 \
         달기</span><span class=comment-delete'>답글 삭제</span></div>",
        id
    ));

    html.push_str("</div>");
    html.push_str("</li>");

    let reply_ids = match &comment.reply_ids {
        Some(reply_ids) => reply_ids.clone(),
        None => vec![],
    };

    if !reply_ids.is_empty() {
        html.push_str("<ul class='comment-list'>");

        for reply_id in reply_ids {
            html.push_str(&create_html_of_comment(comments, &reply_id))
        }

        html.push_str("</ul>");
    }

    html
}

pub fn create_comment_list_html(
    comments: &HashMap<i32, CommentData>,
    from: usize,
    to: usize,
) -> String {
    let mut root_comment_ids = get_root_comments(comments);

    // We should show the newest comment first.
    root_comment_ids.reverse();

    let mut html = "".to_string();
    for index in from..std::cmp::min(root_comment_ids.len(), to) {
        let root_comment_id = root_comment_ids.get(index).unwrap();
        html.push_str(&create_html_of_comment(comments, root_comment_id));
    }

    html
}
