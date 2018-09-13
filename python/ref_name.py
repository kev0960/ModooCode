import json

if __name__ == '__main__':
  with open('files.json') as f:
    data = json.load(f)
    for index in data:
      filename = './md/dump_' + str(index) + '.md'
      with open(filename, 'r+') as md:
        content = md.read()
        md.seek(0, 0)
        contents = content.split('\n')
        header_name = contents[1]
        if "C 언어 레퍼런스" in header_name:
          func = header_name.rfind("함수")
          if func != -1:
            ref_name = header_name[header_name.rfind('-') + 1:func - 1]
          else:
            hd = header_name.rfind("헤더파일")
            if hd != -1:
              ref_name = header_name[header_name.rfind('-') + 1:hd - 1]
          print(ref_name)
          contents.insert(2, "cat_title : " + ref_name)
          md.write('\n'.join(contents))
        elif "C++ 레퍼런스" in header_name:
          func = header_name.rfind('-')
          end = header_name.find(" 함수")
          if end != -1:
            ref_name = header_name[func + 1:end]
          else:
            ref_name = header_name[func + 1:]
          print(ref_name)
          contents.insert(2, "cat_title : " + ref_name)
          md.write('\n'.join(contents))
