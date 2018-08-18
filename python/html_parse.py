from bs4 import BeautifulSoup
with open("./blog/dump_5.html") as fp:
    soup = BeautifulSoup(fp, "lxml")
    print(soup.select('span'))