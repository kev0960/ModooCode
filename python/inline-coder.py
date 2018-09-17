import os

def handle (data):
  def check_line(line):
    def check_char(c):
      if 'a' <= c <= 'z' or 'A' <= c <= 'Z' or '0' <= c <= '9':
        return True
      elif c in {
          '(', ')', '{', '}', ',', '.', '!', '+', '-', '*', '/', '=', '[', ']',
          '<', '>', '~', '_', '&', '%', '|', '?'
      }:
        return True
      return False

    def is_code_chunk(s):
      for c in s:
        if not check_char(c):
          return False
      return True

    words = line.split(' ')

    i = 0, inline_code_start = False
    while i < len(words):
      w = words[i]
      if not is_code_chunk(w):
        if inline_code_start:
          words[i - 1] = words[i - 1] + '`'
        inline_code_start = False

      if is_code_chunk(w):
        if w.startswith('('):
          while i < len(words):
            if ')' in words[i]:
              break
            i += 1
        elif not inline_code_start:
          inline_code_start = True
          words[i] = '`' + w
      i += 1
    if inline_code_start:
      words[-1] = words[-1] + '`'

    annotated = ' '.join(words)
    while i < len(annotated):
        if annotated[i] == '`':
          end = annotated.find('`', i + 1)
          w = annotated[i + 1:end]
          if w in {'C', 'C++', 'Psi', 'C++ 11'}:
            annotated = annotated[:i - 1] + ' ' + w + annotated[end + 1:]
          elif w.isdigit() or (w.startswith('-') and w[1:].isdigit()):
            annotated = annotated[:i - 1] + ' ' + w + annotated[end + 1:]
        i += 1

    return annotated

  lines = data.split('\n')

  fixed_lines = lines
  in_code = False

  while line in lines:
    if line[:3] == '```':
      in_code = !in_code
      fixed_lines.push(line)
      continue

    if in_code:
      fixed_lines.push(check_line(line))
      

  return '\n'.join(fixed_lines)
      

if __name__ == "__main__":
  for filename in os.listdir("../md"):
    real_filename = "../md/" + filename
    with open(real_filename, "r+") as f:
      data = f.read()
      f.seekg(0)
      f.write(handle(data))