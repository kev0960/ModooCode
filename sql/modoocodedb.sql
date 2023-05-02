CREATE TABLE article (
	article_url VARCHAR(256) NOT NULL PRIMARY KEY,

	-- Time that the article was created.
	create_time TIMESTAMP,

	-- Time that the article was updated.
	update_time TIMESTAMP,

	is_published BOOLEAN NOT NULL DEFAULT FALSE,
	is_deleted BOOLEAN NOT NULL DEFAULT FALSE,

	-- Content of the article.
	content TEXT NOT NULL,

	-- SHA256 string computed from the content of the article.
	current_content_sha256 CHAR(64) NOT NULL,

	view_cnt INTEGER DEFAULT 0
);

CREATE INDEX article_url_on_article_index ON article(article_url);

CREATE TABLE comment (
	comment_id SERIAL PRIMARY KEY,
	article_url VARCHAR(256) NOT NULL,
	reply_ids integer[],
	comment_date TIMESTAMP,
	modified_date TIMESTAMP,
	author_name VARCHAR(50),
	author_email VARCHAR(254),
	image_link VARCHAR(512),
	content TEXT NOT NULL,
	password VARCHAR(256) NOT NULL,
	is_md BOOLEAN NOT NULL DEFAULT FALSE,
	is_deleted BOOLEAN DEFAULT FALSE,
	author_id INTEGER,

	FOREIGN KEY (article_url) REFERENCES article(article_url)
);

CREATE INDEX article_url_index ON comment(article_url);

CREATE TABLE users (
	user_id SERIAL PRIMARY KEY,
	email VARCHAR(254),
	name VARCHAR(256) NOT NULL,
	password VARCHAR(256),
	image VARCHAR(512),
	auth_id VARCHAR(512),
	auth_type VARCHAR(16)
);

CREATE INDEX id_index ON users(auth_id);
