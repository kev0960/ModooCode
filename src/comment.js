module.exports = class CommentManager {
  constructor(client) {
    this.client = client;
    this.no_db_access = (process.env.IN_WINDOWS_FOR_DEBUG === 'true');
  }

  async init() {
    if (this.no_db_access) {
      return;
    }
    // Get the initial number of comments.
    let result = await this.client.query(
        'select article_url, count(comment_id) from comment where is_deleted = FALSE group by article_url;');

    this.url_to_num_comment = {};
    for (let i = 0; i < result.rows.length; i++) {
      this.url_to_num_comment[result.rows[i].article_url] =
          parseInt(result.rows[i].count);
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

  async addComment(parent_id, article_url, user, content, password) {
    if (this.no_db_access) {
      return;
    }
    
    let current_time = new Date();
    // (Note) Fixing comment_comment_id_seq sync error;
    // SELECT setval('comment_comment_id_seq', max(comment_id)) FROM comment;
    // (Note) Removing specific reply (5829 : reply comment)
    // update comment set reply_ids = array_remove(reply_ids, 5829) where
    // comment_id = 4108;
    let result = await this.client.query(
        'INSERT INTO comment(article_url, reply_ids, vote_up, vote_down,' +
            'comment_date, modified_date, author_name, author_email, image_link,' +
            'content, password, author_id, is_md) VALUES ($1, $2, $3, $4, $5, $6, $7,' +
            ' $8, $9, $10, $11, $12, $13) RETURNING *',
        [
          article_url, [], 0, 0, current_time, current_time, user.name,
          user.email, user.image, content, password, user.user_id, true
        ]);
    let new_comment = result.rows[0];
    let new_comment_id = new_comment.comment_id;

    if (parent_id !== -1) {
      await this.client.query(
          'UPDATE comment SET reply_ids = array_append(reply_ids, $1) WHERE' +
              ' comment_id = $2',
          [new_comment_id, parent_id]);
    }

    // Increase the comment count.
    this.addCommentAt(article_url);
  }

  async deleteComment(comment_id, user, password) {
    let comment = await this.client.query(
        'SELECT comment_id, author_id, password' +
            ' FROM comment WHERE comment_id = $1',
        [comment_id]);
    if (comment.rows.length == 0) {
      return {status: false, msg: 'Fatal error'};
    }
    comment = comment.rows[0];
    if (comment.author_id != user.user_id) {
      // Then check whether email and the password matches.
      const match = await bcrypt.compare(password, comment.password);
      if (!match) {
        return {status: false, msg: 'Password does not match'};
      }
    }

    await this.client.query(
        'UPDATE comment SET is_deleted = TRUE, ' +
            'content = \'삭제된 댓글입니다\' WHERE comment_id = $1',
        [comment_id]);
    return {status: true};
  }

  async getLatestComments(num_comment) {
    if (process.env.IN_WINDOWS_FOR_DEBUG === 'true') {
      return [];
    }

    let latest_comments = await this.client.query(
        'SELECT content, comment_date, article_url, author_name FROM ' +
            'comment WHERE is_deleted = FALSE ORDER BY comment_date DESC LIMIT $1',
        [num_comment]);

    for (let i = 0; i < latest_comments.rows.length; i++) {
      let d = new Date(latest_comments.rows[i].comment_date);
      let month = '' + (d.getMonth() + 1);
      let day = '' + d.getDate();
      if (month.length < 2) {
        month = '0' + month;
      }
      if (day.length < 2) {
        day = '0' + day;
      }
      latest_comments.rows[i].comment_date = month + '.' + day;
    }
    return latest_comments.rows;
  }
}
