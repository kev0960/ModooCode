import json

if __name__ == '__main__':
  with open('files.json') as f:
    data = json.load(f)
    for index in data:
      filename = './md/dump_' + str(index) + '.md'
      with open(filename, 'r+') as md:
        content = md.read()
        md.seek(0, 0)
        header = '----------------\n'
        header += ('title : ' + data[index])
        header += '\n--------------\n'
        content = header + content
        md.write(content)
