var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __generator = (this && this.__generator) || function (thisArg, body) {
    var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g;
    return g = { next: verb(0), "throw": verb(1), "return": verb(2) }, typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
    function verb(n) { return function (v) { return step([n, v]); }; }
    function step(op) {
        if (f) throw new TypeError("Generator is already executing.");
        while (g && (g = 0, op[0] && (_ = 0)), _) try {
            if (f = 1, y && (t = op[0] & 2 ? y["return"] : op[0] ? y["throw"] || ((t = y["return"]) && t.call(y), 0) : y.next) && !(t = t.call(y, op[1])).done) return t;
            if (y = 0, t) op = [op[0] & 2, t.value];
            switch (op[0]) {
                case 0: case 1: t = op; break;
                case 4: _.label++; return { value: op[1], done: false };
                case 5: _.label++; y = op[1]; op = [0]; continue;
                case 7: op = _.ops.pop(); _.trys.pop(); continue;
                default:
                    if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                    if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                    if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                    if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                    if (t[2]) _.ops.pop();
                    _.trys.pop(); continue;
            }
            op = body.call(thisArg, _);
        } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
        if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
    }
};
var CommentManager = /** @class */ (function () {
    function CommentManager() {
        this.last_comment_index_ = 0;
        this.comments_ = new Map();
        this.root_comments_ = [];
        // @ts-ignore
        this.num_total_comments_ = getNumTotalComments();
    }
    CommentManager.prototype.LoadComments = function () {
        return __awaiter(this, void 0, void 0, function () {
            var url, article_url, response, get_comment_response, comments, _i, comments_1, comment;
            return __generator(this, function (_a) {
                switch (_a.label) {
                    case 0:
                        url = window.location.pathname;
                        article_url = url.substr(url.lastIndexOf("/") + 1);
                        return [4 /*yield*/, fetch("/get-comment", {
                                method: "POST",
                                mode: "cors",
                                cache: "no-cache",
                                headers: {
                                    Accept: "application/json",
                                    "Content-Type": "application/json",
                                },
                                body: JSON.stringify({
                                    article_url: article_url,
                                    index_start: this.last_comment_index_,
                                }),
                            })];
                    case 1:
                        response = _a.sent();
                        return [4 /*yield*/, response.json()];
                    case 2:
                        get_comment_response = _a.sent();
                        comments = get_comment_response.comments;
                        for (_i = 0, comments_1 = comments; _i < comments_1.length; _i++) {
                            comment = comments_1[_i];
                            this.comments_.set(comment.comment_id, comment);
                        }
                        this.last_comment_index_ += 50;
                        return [2 /*return*/];
                }
            });
        });
    };
    CommentManager.prototype.PostComment = function (content, password, name, parent_id) {
        return __awaiter(this, void 0, void 0, function () {
            var url, article_url;
            return __generator(this, function (_a) {
                url = window.location.href;
                article_url = url.substr(url.lastIndexOf("/") + 1);
                grecaptcha.ready(function () {
                    grecaptcha
                        .execute("6LeE_nYUAAAAAGm9qTa71IwvvayWV9Q7flqNkto2", {
                        action: "Comment",
                    })
                        .then(function (token) {
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
                        }).then(function (data) {
                            console.log(data);
                            document.getElementById("adding-comment").hidden = true;
                            location.reload();
                        });
                    });
                });
                return [2 /*return*/];
            });
        });
    };
    CommentManager.prototype.ComputeRootComments = function () {
        var comment_ids = Array.from(this.comments_.keys()).sort(function (a, b) { return a - b; });
        var visited_comments = new Set();
        this.root_comments_ = [];
        // Find the root comments.
        for (var _i = 0, comment_ids_1 = comment_ids; _i < comment_ids_1.length; _i++) {
            var comment_id = comment_ids_1[_i];
            if (visited_comments.has(comment_id)) {
                continue;
            }
            this.root_comments_.push(this.comments_.get(comment_id));
            this.VisitAllChildComments(comment_id, visited_comments);
        }
        this.root_comments_ = this.root_comments_.reverse();
    };
    CommentManager.prototype.VisitAllChildComments = function (comment_id, visited_comments) {
        var comment = this.comments_.get(comment_id);
        if (!comment) {
            return;
        }
        visited_comments.add(comment_id);
        for (var _i = 0, _a = comment.reply_ids || []; _i < _a.length; _i++) {
            var child_comment_id = _a[_i];
            this.VisitAllChildComments(child_comment_id, visited_comments);
        }
        return;
    };
    CommentManager.prototype.CreateCommentList = function () {
        var root_comment_list = document.createElement("ul");
        root_comment_list.classList.add("comment-list");
        root_comment_list.id = "root-comment-list";
        for (var _i = 0, _a = this.root_comments_; _i < _a.length; _i++) {
            var comment = _a[_i];
            for (var _b = 0, _c = this.CreateComment(comment.comment_id); _b < _c.length; _b++) {
                var comment_elem = _c[_b];
                root_comment_list.appendChild(comment_elem);
            }
        }
        return root_comment_list;
    };
    CommentManager.prototype.CreateComment = function (comment_id) {
        var _this = this;
        var comment = this.comments_.get(comment_id);
        if (!comment) {
            return [];
        }
        var comment_elem = document.createElement("li");
        comment_elem.classList.add("comment");
        var comment_profile = document.createElement("div");
        comment_profile.classList.add("comment-profile");
        var image_link = document.createElement("img");
        if (comment.image_link) {
            image_link.src = comment.image_link;
            image_link.alt = "프로필 사진";
        }
        else {
            image_link.src = "./img/unknown_person.png";
            image_link.alt = "프로필 사진 없음";
        }
        comment_profile.appendChild(image_link);
        comment_elem.appendChild(comment_profile);
        var comment_info = document.createElement("div");
        comment_info.classList.add("comment-info");
        // Comment header.
        var comment_header = document.createElement("div");
        comment_header.classList.add("comment-header");
        var createSimpleSpan = function (class_name, text) {
            var elem = document.createElement("span");
            elem.classList.add(class_name);
            elem.textContent = text;
            return elem;
        };
        comment_header.appendChild(createSimpleSpan("comment-author", comment.author_name || ""));
        comment_header.appendChild(createSimpleSpan("comment-date", comment.comment_date || ""));
        comment_info.appendChild(comment_header);
        // Comment content.
        var comment_content = document.createElement("div");
        comment_content.classList.add("comment-content");
        comment_content.textContent = comment.content;
        comment_info.appendChild(comment_content);
        var comment_action = document.createElement("div");
        comment_action.classList.add("comment-action");
        comment_action.id = "comment-id-" + comment_id;
        var commentReplyAction = createSimpleSpan("comment-reply", "답글 달기");
        commentReplyAction.onclick = function () {
            _this.CreateCommentReply(comment_id);
        };
        comment_action.appendChild(commentReplyAction);
        var commentDeleteAction = createSimpleSpan("comment-delete", "답글 삭제");
        comment_action.appendChild(commentDeleteAction);
        comment_info.appendChild(comment_action);
        comment_elem.appendChild(comment_info);
        if (!comment.reply_ids) {
            return [comment_elem];
        }
        if (!comment.reply_ids.length) {
            return [comment_elem];
        }
        var child_comments = document.createElement("ul");
        child_comments.classList.add("comment-list");
        for (var _i = 0, _a = comment.reply_ids; _i < _a.length; _i++) {
            var reply_id = _a[_i];
            var elems = this.CreateComment(reply_id);
            for (var _b = 0, elems_1 = elems; _b < elems_1.length; _b++) {
                var elem = elems_1[_b];
                child_comments.append(elem);
            }
        }
        return [comment_elem, child_comments];
    };
    CommentManager.prototype.GetNumTotalComments = function () {
        return this.num_total_comments_;
    };
    CommentManager.prototype.GetLastCommentIndex = function () {
        return this.last_comment_index_;
    };
    CommentManager.prototype.CreateCommentReply = function (comment_id) {
        var _this = this;
        if (this.current_reply_comment_box) {
            this.current_reply_comment_box.remove();
        }
        // Create a comment box for the comment reply.
        var reply_box = document
            .getElementById("comment-post-section")
            .cloneNode(true);
        reply_box.id = "reply-post-section";
        var comment_to_add_reply = document.getElementById("comment-id-" + comment_id).parentElement.parentElement;
        comment_to_add_reply.insertAdjacentElement("afterend", reply_box);
        reply_box.getElementsByClassName("comment-btn")[0].onclick = function () {
            var name = "", password = "";
            if (reply_box.getElementsByClassName("comment-box-name").length > 0) {
                name = reply_box.getElementsByClassName("comment-box-name")[0].value;
                password = reply_box.getElementsByClassName("comment-box-name")[0].value;
            }
            var content = reply_box.getElementsByClassName("comment-textarea")[0].value;
            _this.PostComment(content, password, name, /*parent_id=*/ comment_id).then(function (res) {
                console.log(res);
            });
        };
        this.current_reply_comment_box = reply_box;
    };
    return CommentManager;
}());
export function CreateCommentManager() {
    var comment = new CommentManager();
    return comment;
}
//# sourceMappingURL=comment.js.map