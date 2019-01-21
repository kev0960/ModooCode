CREATE TYPE article_content (
  content_date TIMESTAMP,
  /* Used when diff is too big or every 5 diffs */
  content TEXT,
  diff TEXT,
  /* Used in order to indicate this content is diff only */
  is_diff BOOLEAN NOT NULL DEFAULT FALSE
);

CREATE TABLE Articles (
  article_url varchar(256) NOT NULL,
  creation_date TIMESTAMP,
  is_published BOOLEAN NOT NULL DEFAULT FALSE,
  is_deleted BOOLEAN NOT NULL DEFAULT FALSE,
  contents article_content [],
  /* Remembers the (next article url) -> count */
  related_articles hstore
);