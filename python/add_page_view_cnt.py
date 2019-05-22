import psycopg2 as pg2
import csv
import os


def parse_page_name(page_name):
  page_name = page_name[1:]
  if page_name == 'notice/15':
    page_name = '231'
  elif page_name == 'entry/씹어먹는-C-언어-1-C-언어가-뭐야':
    page_name = '5'

  slash = page_name.find('/')
  if slash != -1:
    page_name = page_name[:slash]

  qmark = page_name.find('?')
  if qmark != -1:
    page_name = page_name[:qmark]

  try:
    int(page_name)
  except ValueError:
    return False

  return page_name


conn = pg2.connect(
    host="localhost",
    database="modoocodedb",
    user="postgres",
    password=os.environ['PGPASSWORD'])


def do_insert(page_name_to_cnt):
  for page_name in page_name_to_cnt:
    cnt = page_name_to_cnt[page_name]
    sql = "UPDATE Articles SET view_cnt = view_cnt + " + str(
        cnt) + " WHERE article_url = '" + page_name + "'"
    
    conn.cursor().execute(sql)
  conn.commit()


with open('new_page_cnt.csv') as csvfile:
  reader = csv.reader(csvfile)

  page_name_to_cnt = {}
  for row in reader:
    page_name = parse_page_name(row[0])
    if page_name and len(page_name) > 0:
      view_cnt = page_name_to_cnt.get(page_name, 0)
      page_name_to_cnt[page_name] = view_cnt + int(row[1].replace(',', ''))

  do_insert(page_name_to_cnt)