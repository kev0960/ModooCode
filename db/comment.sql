CREATE TABLE Comment (
  comment_id serial PRIMARY KEY,
  article_url varchar(256) NOT NULL,
  reply_ids integer ARRAY,
  vote_up integer CHECK (vote_up >= 0),
  vote_down integer CHECK (vote_down >= 0),
  comment_date timestamp,
  modified_date timestamp,
  author_name varchar(50),
  author_email varchar(254),
  image_link varchar(256),
  content text NOT NULL,
  password varchar(256) NOT NULL
);
