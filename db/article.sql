CREATE TYPE article_content AS (
  content_date TIMESTAMP,
  /* Used when diff is too big or every 5 diffs */
  content TEXT,
  diff TEXT,
  /* Used in order to indicate this content is diff only */
  is_diff BOOLEAN
);

CREATE TABLE Articles (
  article_url varchar(256) NOT NULL,
  creation_date TIMESTAMP,
  is_published BOOLEAN NOT NULL DEFAULT FALSE,
  is_deleted BOOLEAN NOT NULL DEFAULT FALSE,
  contents article_content [],
  /* Hex of SHA 512 of current content */
  current_content_sha512 VARCHAR(128),
  /* Remembers the (next article url) -> count */
  related_articles hstore
);