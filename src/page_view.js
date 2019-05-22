module.exports = class PageViewManager {
  constructor(client) {
    this.client = client;
  }

  async init() {
    // Get the initial number of comments.
    let result =
        await this.client.query('select article_url, view_cnt from Articles;');

    this.page_to_view_cnt = {};
    for (let i = 0; i < result.rows.length; i++) {
      this.page_to_view_cnt[result.rows[i].article_url] =
          result.rows[i].view_cnt;
    }

    this.changed_pages = new Set();
  }

  addPageViewCnt(url) {
    url = '' + url;

    if (!this.page_to_view_cnt[url]) {
      this.page_to_view_cnt[url] = 1;
    } else {
      this.page_to_view_cnt[url] += 1;
    }

    this.changed_pages.add(url);
  }

  getPageViewCnt(url) {
    url = '' + url;

    if (!this.page_to_view_cnt[url]) {
      this.page_to_view_cnt[url] = 0;
    }
    return this.page_to_view_cnt[url];
  }

  flushPageViewCnt() {
    this.changed_pages.forEach(function(url) {
      this.client
          .query(
              'UPDATE Articles SET view_cnt = $1::int WHERE article_url = $2::text',
              [this.page_to_view_cnt[url], url])
          .catch(e => console.log(e.stack));
    }.bind(this));

    this.changed_pages = new Set();
  }
}
