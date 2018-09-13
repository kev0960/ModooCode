with open("result") as f:
  content = f.readlines()
  aria_output = ""
  filenames = set()
  for line in content:
    start = line.find("http://")
    end = line.find(")", start + 1)
    url = line[start:end]

    filename_start = line.find("image%")
    filename_end = line.find(")", filename_start + 1)
    filename = line[filename_start + len("image%2F"):filename_end]
    if filename in filenames:
      continue
    else:
      filenames.add(filename)
    aria_output += (url + "\n")
    aria_output += ("  dir=./img\n")
    aria_output += ("  out=" + filename + "\n")

print(aria_output)
