import psycopg2 as pg2
import json
from datetime import datetime
import os


class Comment():

  def __init__(self, uniq, author, timestamp, content, url):
    self.uniq = uniq
    self.author = author
    self.timestamp = timestamp
    self.content = content
    self.article_url = url
    self.reply = []

  def add_repl(self, r):
    self.reply.append(r)

  def __str__(self):
    return "({0}-{1}) ({2}) at ({3}) : ({4}), repls : ({5})".format(
        self.uniq, self.article_url, self.author, self.timestamp, self.content,
        self.reply)

  def to_obj(self):
    return {
        'uniq': self.uniq,
        'author': self.author,
        'timestamp': self.timestamp,
        'content': self.content,
        'article': self.article_url,
        'reply': self.reply
    }


class InsertCommentToDb():

  def __init__(self):
    self.conn = pg2.connect(
        host="localhost",
        database="modoocodedb",
        user="postgres",
        password=os.environ['PGPASSWORD'])
    self.cur = self.conn.cursor()
    self.current_unique = 1
    self.last_parent = None
    self.comment_list = []

  def insert_comment_to_db(self, article_url, comment_list):
    for c in comment_list:
      depth = c[0]
      author = c[1]
      timestamp = c[2]
      content = c[3]
      comm = Comment(self.current_unique, author, timestamp, content,
                     article_url)

      if depth == 1:
        self.last_parent = comm
      elif depth == 2:
        self.last_parent.add_repl(self.current_unique)

      self.comment_list.append(comm)
      self.current_unique += 1

  def insert_comment_to_db_from_json(self, comment_list):
    for c in comment_list:
      print(c)
      author = c['author']
      article = c['article']
      timestamp = datetime.fromtimestamp(c['timestamp'])
      uniq = c['uniq']
      content = c['content']
      comm = Comment(uniq, author, timestamp, content, article)
      comm.reply = c['reply']
      self.comment_list.append(comm)

  def print(self):
    for c in self.comment_list:
      print(c)

  def json_dump(self):
    js = [c.to_obj() for c in self.comment_list]
    return json.dumps(js, sort_keys=True, indent=4)

  def do_insert(self):
    sql = """INSERT INTO comment(comment_id, article_url, reply_ids, vote_up, vote_down, comment_date, modified_date,
                                     author_name, author_email, image_link, content, password)
                 VALUES(%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s)
              """
    for c in self.comment_list:
      self.cur.execute(sql, (c.uniq, c.article_url, c.reply, 0, 0, c.timestamp,
                             c.timestamp, c.author, "", "", c.content, ""))
    self.conn.commit()


if __name__ == "__main__":
  with open("comments.json") as js:
    comm = json.loads(js.read())
    insertManager = InsertCommentToDb()
    insertManager.insert_comment_to_db_from_json(comm)
    insertManager.do_insert()
