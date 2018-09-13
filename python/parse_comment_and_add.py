import psycopg2 as pg2
import os
from tqdm import tqdm
from html.parser import HTMLParser
import time
import json
from datetime import datetime


def main():
  '''
        cur.execute('SELECT * FROM Comment')
        records = cur.fetchall()
        print(records)
    '''
  pass


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


def remove_whitespace(line):
  line = line.translate({ord(i): None for i in '\n'})
  return line.strip()


class BlogCommentParser(HTMLParser):

  def __init__(self, filename):
    super().__init__()

    self.filename = filename
    self.li_depth = 0
    self.current_div = []
    self.current_span = ""
    self.current_img = False
    self.current_link = False
    self.content = ""
    self.record_content = False
    self.date = False
    self.comment_list = []

    self.comment_name = ""
    self.comment_date = 0
    self.comment_content = ""

  def parse(self):
    with open(self.filename, 'r') as f:
      self.feed(f.read())

  def handle_starttag(self, tag, attrs):

    def check_attr(attrs, attr_name):
      for attr in attrs:
        if attr[0] == attr_name:
          if attr_name == 'class':
            return attr[1].split(' ')
          return attr[1]
      return ""

    if tag == 'li':
      self.li_depth += 1
    elif tag == 'div':
      if 'name' in check_attr(attrs, "class"):
        self.current_div.append('name')
      if 'wrapper' in check_attr(attrs, "class"):
        self.content = ""
        self.current_div.append('content')

    elif tag == 'img':
      self.current_img = True
    elif tag == 'a':
      self.current_link = True
    elif tag == 'p' and self.current_div[0] == 'content':
      self.record_content = True
    elif tag == 'br' and self.record_content:
      self.content += '\n'
    elif tag == 'span':
      if 'date' in check_attr(attrs, 'class'):
        self.date = True

  def handle_endtag(self, tag):
    if tag == 'li':
      self.li_depth -= 1
    elif tag == 'div' and len(self.current_div) > 0:
      if self.current_div[0] == 'content':
        self.content = self.content.replace("                    ", "")
        self.content = self.content.replace("       ", "")
        self.comment_content = self.content
        # print("Recorded : ", self.content)
        self.comment_list.append([
            self.li_depth, self.comment_name, self.comment_date,
            self.comment_content
        ])
      self.current_div = self.current_div[1:]
    elif tag == 'a':
      self.current_link = False
    elif tag == 'p':
      self.record_content = False

  def handle_data(self, data):
    if self.current_img:
      self.current_img = False
    elif self.date:
      self.date = False
      date = remove_whitespace(data)
      # print("Date ", date)
      self.comment_date = time.mktime(
          datetime.strptime(date, "%Y.%m.%d %H:%M").timetuple())
      self.comment_date = datetime.fromtimestamp(self.comment_date)
    elif len(self.current_div) >= 1 and self.current_div[0] == 'name':
      data = remove_whitespace(data)
      if len(data) > 0:
        if not self.current_img:
          self.comment_name = data
          # print("Name : ", self.li_depth, data)
        elif self.current_link:
          self.comment_name = data
          # print("Name : ", self.li_depth, data)
    elif self.record_content:
      data = remove_whitespace(data)
      self.content += data


if __name__ == '__main__':
  com_db = InsertCommentToDb()

  with tqdm(os.listdir('./blog')) as t:
    for filename in t:
      t.set_description("Dump : " + filename)
      if 'comment' not in filename:
        continue
      # if '_222.' not in filename:
      #   continue
      comment_parser = BlogCommentParser(os.path.join('./blog', filename))
      url = filename[filename.rfind('_') + 1:filename.rfind('.')]
      comment_parser.parse()
      com_db.insert_comment_to_db(url, comment_parser.comment_list)
      # com_db.print()
      # print(comment_parser.comment_list)
  com_db.do_insert()
