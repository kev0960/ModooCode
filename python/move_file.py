from os import listdir
from os.path import isfile, join
import os
from pathlib import Path

def move_files():
  p = "/home/jaebum/ModooCode/md"
  for f in listdir(p):
    file_path = join(p, f)
    if isfile(file_path):
      print(file_path)
      with open(file_path) as file:
        data = file.readlines()
        paths = '/'.join(get_file_path(data))

        if paths == '':
          continue

        full_path = join("/home/jaebum/ModooCode/md/", paths)

        if not os.path.exists(full_path):
          Path(full_path).mkdir(parents=True, exist_ok=False)

        if f.find('dump_') == 0:
          f = f[5:]

        with open(join(full_path, f), "w") as writer:
          print(join(full_path, f))
          writer.write(''.join(data))

def get_file_path(data):
  if data[0].find("-----") == -1:
    print("Something wrong with ", data[0])
    return

  for line in data[1:]:
    if line.find("-------") != -1:
      break

    sp = line.split(':')
    field_name = sp[0].strip()
    if field_name == 'path':
      print("path : ", sp[1].strip().split('/')[1:])
      return sp[1].strip().split('/')[1:]

  return []

if __name__ == "__main__":
  move_files()