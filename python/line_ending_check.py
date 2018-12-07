import os

for file in os.listdir("/home/jaebum/ModooCode/python/md"):
  with open(os.path.join("/home/jaebum/ModooCode/python/md", file)) as f:
    content = f.read()
    if '\r\n' in content:
      print("CRLF found in ", file)

for file in os.listdir("/home/jaebum/ModooCode/md"):
  with open(os.path.join("/home/jaebum/ModooCode/md", file)) as f:
    content = f.read()
    if '\r\n' in content:
      print("CRLF found in ", file)
