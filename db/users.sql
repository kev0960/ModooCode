CREATE TABLE Users (
  user_id serial PRIMARY KEY,
  email varchar(254),
  name varchar(256) NOT NULL,
  password varchar(256),
  image varchar(512),
  auth_id varchar(512),
  auth_type varchar(16)
);
CREATE INDEX id_index ON Users (auth_id);
CREATE INDEX auth_type_index ON Users (auth_type);
