declare const grecaptcha: any;

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

    // @ts-ignore
    this.num_total_comments_ = getNumTotalComments();
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

    this.last_comment_index_ += 50;
  }

  public async PostComment(
    content: string,
    password: string,
    name: string,
    parent_id?: number
  ) {
    const url = window.location.href;
    let article_url = url.substr(url.lastIndexOf("/") + 1);

    grecaptcha.ready(function () {
      grecaptcha
        .execute("6LeE_nYUAAAAAGm9qTa71IwvvayWV9Q7flqNkto2", {
          action: "Comment",
        })
        .then(function (token: string) {
          fetch("/write-comment", {
            method: "POST",
            mode: "cors",
            cache: "no-cache",
            headers: {
              "Content-Type": "application/json",
            },
            body: JSON.stringify({
              parent_id: parent_id,
              content: content,
              password: password || "",
              author_name: name,
              article_url: article_url,
              captcha_token: token,
            }),
          }).then((data) => {
            console.log(data);
            document.getElementById("adding-comment").hidden = true;
            location.reload();
          });
        });
    });
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
    let root_comment_list = document.createElement("ul");
    root_comment_list.classList.add("comment-list");
    root_comment_list.id = "root-comment-list";

    for (const comment of this.root_comments_) {
      for (const comment_elem of this.CreateComment(comment.comment_id)) {
        root_comment_list.appendChild(comment_elem);
      }
    }

    return root_comment_list;
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

    const commentReplyAction = createSimpleSpan("comment-reply", "답글 달기");
    commentReplyAction.onclick = () => {
      this.CreateCommentReply(comment_id);
    };
    comment_action.appendChild(commentReplyAction);

    const commentDeleteAction = createSimpleSpan("comment-delete", "답글 삭제");
    comment_action.appendChild(commentDeleteAction);
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

  GetNumTotalComments() {
    return this.num_total_comments_;
  }

  GetLastCommentIndex() {
    return this.last_comment_index_;
  }

  CreateCommentReply(comment_id: number) {
    if (this.current_reply_comment_box) {
      this.current_reply_comment_box.remove();
    }

    // Create a comment box for the comment reply.
    let reply_box = document
      .getElementById("comment-post-section")
      .cloneNode(true) as HTMLElement;
    reply_box.id = "reply-post-section";

    let comment_to_add_reply = document.getElementById(
      "comment-id-" + comment_id
    ).parentElement.parentElement;

    comment_to_add_reply.insertAdjacentElement("afterend", reply_box);

    (
      reply_box.getElementsByClassName("comment-btn")[0] as HTMLButtonElement
    ).onclick = () => {
      console.log("clicked");
      let name = (
        reply_box.getElementsByClassName(
          "comment-box-name"
        )[0] as HTMLInputElement
      ).value;

      let password = (
        reply_box.getElementsByClassName(
          "comment-box-name"
        )[0] as HTMLInputElement
      ).value;

      let content = (
        reply_box.getElementsByClassName(
          "comment-textarea"
        )[0] as HTMLInputElement
      ).value;

      this.PostComment(content, password, name, /*parent_id=*/ comment_id).then(
        (res) => {
          console.log(res);
        }
      );
    };
    this.current_reply_comment_box = reply_box;
  }

  private last_comment_index_: number;
  private comments_: Map<number, Comment>;
  private root_comments_: Comment[];
  private num_total_comments_: number;

  // Reply comment box that exists.
  private current_reply_comment_box?: HTMLElement;
}

export function CreateCommentManager(): CommentManager {
  let comment = new CommentManager();
  return comment;
}
