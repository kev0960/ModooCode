interface Comment {
  comment_id: number;
  article_url: string;
  reply_ids: number[];
  comment_date: string;
  author_name?: string;
  image_link: string;
  content: string;
  is_md: boolean;
}

interface GetCommentResponse {
  comments: Comment[];
}

class CommentManager {
  constructor() {
    this.last_comment_index_ = 0;
    this.comments_ = new Map();
    this.root_comments_ = [];
  }

  public async LoadComments() {
    let url = window.location.pathname;
    let article_url = url.substr(url.lastIndexOf("/") + 1);

    let response = await fetch("/get-comment", {
      method: "POST",
      mode: "cors",
      cache: "no-cache",
      headers: {
        Accept: "application/json",
        "Content-Type": "application/json",
      },
      body: JSON.stringify({
        article_url,
        index_start: this.last_comment_index_,
      }),
    });

    let get_comment_response: GetCommentResponse = await response.json();
    let comments = get_comment_response.comments;
    for (let comment of comments) {
      this.comments_.set(comment.comment_id, comment);
    }
  }

  ComputeRootComments() {
    let comment_ids = Array.from(this.comments_.keys()).sort((a, b) => a - b);
    let visited_comments = new Set<number>();

    this.root_comments_ = [];

    // Find the root comments.
    for (let comment_id of comment_ids) {
      if (visited_comments.has(comment_id)) {
        continue;
      }

      this.root_comments_.push(this.comments_.get(comment_id)!);
      this.VisitAllChildComments(comment_id, visited_comments);
    }

    this.root_comments_ = this.root_comments_.reverse();
  }

  VisitAllChildComments(comment_id: number, visited_comments: Set<number>) {
    let comment = this.comments_.get(comment_id);
    if (!comment) {
      return;
    }

    visited_comments.add(comment_id);
    for (let child_comment_id of comment.reply_ids || []) {
      this.VisitAllChildComments(child_comment_id, visited_comments);
    }

    return;
  }

  CreateCommentList() {
    let comments = [];
    for (const comment of this.root_comments_) {
      comments.push(this.CreateComment(comment.comment_id));
    }

    return comments.flat();
  }

  CreateComment(comment_id: number) {
    let comment = this.comments_.get(comment_id);
    if (!comment) {
      return;
    }

    let comment_elem = document.createElement("li");
    comment_elem.classList.add("comment");

    let comment_profile = document.createElement("div");
    comment_profile.classList.add("comment-profile");

    let image_link = document.createElement("img");
    if (comment.image_link) {
      image_link.src = comment.image_link;
      image_link.alt = "프로필 사진";
    } else {
      image_link.src = "./img/unknown_person.png";
      image_link.alt = "프로필 사진 없음";
    }

    comment_profile.appendChild(image_link);
    comment_elem.appendChild(comment_profile);

    let comment_info = document.createElement("div");
    comment_info.classList.add("comment-info");

    // Comment header.
    let comment_header = document.createElement("div");
    comment_header.classList.add("comment-header");

    let createSimpleSpan = (class_name: string, text: string) => {
      let elem = document.createElement("span");
      elem.classList.add(class_name);
      elem.textContent = text;
      return elem;
    };

    comment_header.appendChild(
      createSimpleSpan("comment-author", comment.author_name || "")
    );
    comment_header.appendChild(
      createSimpleSpan("comment-date", comment.comment_date || "")
    );

    comment_info.appendChild(comment_header);

    // Comment content.
    let comment_content = document.createElement("div");
    comment_content.classList.add("comment-content");
    comment_content.textContent = comment.content;
    comment_info.appendChild(comment_content);

    let comment_action = document.createElement("div");
    comment_action.classList.add("comment-action");
    comment_action.id = "comment-id-" + comment_id;

    comment_action.appendChild(createSimpleSpan("comment-upvote", "추천"));
    comment_action.appendChild(createSimpleSpan("comment-reply", "답글"));
    comment_action.appendChild(createSimpleSpan("comment-delete", "답글 삭제"));
    comment_info.appendChild(comment_action);

    comment_elem.appendChild(comment_info);

    if (!comment.reply_ids?.length) {
      return [comment_elem];
    }

    let child_comments = document.createElement("ul");
    child_comments.classList.add("comment-list");

    for (const reply_id of comment.reply_ids) {
      let elems = this.CreateComment(reply_id);
      for (const elem of elems) {
        child_comments.append(elem);
      }
    }

    return [comment_elem, child_comments];
  }

  private last_comment_index_: number;
  private comments_: Map<number, Comment>;
  private root_comments_: Comment[];
}

export function CreateCommentManager(): CommentManager {
  let comment = new CommentManager();
  return comment;
}
