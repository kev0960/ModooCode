import os

def add_date_to_md(link, publish_date):
    if os.path.exists('./md/dump_' + str(link) + '.md'):
        with open('./md/dump_' + str(link) + '.md') as f:
            content = f.read()
            content = content.split('\n')
            for i in range(2, len(content)):
                if content[i].find('------------') == 0:
                    content.insert(i, "publish_date : " + publish_date)
                    break
            content = '\n'.join(content)
        with open('./md/dump_' + str(link) + '.md', "w") as fw:
            fw.write(content)

def parse_content(content):
    current = 0
    while True:
        link_start = '<strong class="tit_post tit_ellip"><a href="'
        current = content.find(link_start, current)
        if current == -1:
            return
        current = current + len(link_start)
        link_end = content.find('"', current + 1)

        link = content[current:link_end]
        link = int(link[link.rfind('/') + 1:])
        print("Link : ", link)

        current = link_end + 1

        publish_date_start = '<span class="txt_info">'
        current = content.find(publish_date_start, current)
        if current == -1:
            return
        current = current + len(publish_date_start)

        publish_date_end = content.find("</span>", current + 1)
        publish_date = content[current:publish_date_end]
        current = publish_date_end + 1

        publish_date = publish_date[:publish_date.find(' ')]
        print(publish_date)
        add_date_to_md(link, publish_date)

for file in os.listdir('./tistory'):
    if file.endswith('.htm'):
        with open(os.path.join('./tistory', file)) as f:
            content = f.read()
            parse_content(content)
