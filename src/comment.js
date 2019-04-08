module.exports = class CommentManager {
  constructor(client) {
    this.client = client;
  }

  async init() {
    // Get the initial number of comments.
    let result = await this.client.query(
        'select article_url, count(comment_id) from comment where is_deleted = FALSE group by article_url;');

    this.url_to_num_comment = {};
    for (let i = 0; i < result.rows.length; i++) {
      this.url_to_num_comment[result.rows[i].article_url] =
          result.rows[i].count;
    }
  }

  addCommentAt(url) {
    if (!this.url_to_num_comment[url]) {
      this.url_to_num_comment[url] = 1;
    } else {
      this.url_to_num_comment[url] += 1;
    }
  }

  getNumCommentAt(url) {
    if (!this.url_to_num_comment[url]) {
      this.url_to_num_comment[url] = 0;
    }
    return this.url_to_num_comment[url];
  }
}
