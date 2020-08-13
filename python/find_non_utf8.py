def find_non_utf(file_name):
  with open(file_name, encoding='utf-8', errors='hi') as f:
    content = f.read()
    print(content)

if __name__ == "__main__":
  find_non_utf("/home/jaebum/ModooCode/md/inst/haddps.md")