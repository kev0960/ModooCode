from bs4 import BeautifulSoup
import os
from tqdm import tqdm
from html.parser import HTMLParser


class BlogDumpHtmlParser(HTMLParser):
    def __init__(self, filename):
        super().__init__()
        self.in_box = False
        self.in_list = False
        self.in_script = False
        self.in_title = False
        self.filename = filename
        self.div_cnt = 0
        self.current_div_cnt = 0

        output_file_name = filename.split('.')
        output_file_name[-1] = 'md'
        output_file_name = '.'.join(output_file_name)
        output_file_name = output_file_name.split('/')
        output_file_name[1] = 'md'
        output_file_name = '/'.join(output_file_name)

        self.output_file = open(output_file_name, 'w')

    def print_line(self, line):
        self.output_file.write(line)

    def print(self, line):
        self.output_file.write(line + '\n')

    def parse(self):
        with open(self.filename, 'r') as f:
            self.feed(f.read())

    def handle_starttag(self, tag, attrs):
        def check_attr(attrs, attr_name):
            for attr in attrs:
                if attr[0] == attr_name:
                    if attr_name == 'class':
                        return attr[1].split(' ')
                    return attr[1]
            return ""

        if tag == 'img':
            self.print("![{0}]({1})".format(BlogDumpParser.replace_bracket(check_attr(attrs, 'alt')),
                                            BlogDumpParser.srcset_to_src(
                                                BlogDumpParser.replace_bracket(check_attr(attrs, 'srcset')))))
        elif tag == 'ul':
            self.in_list = True
            self.print_line("* ")
        elif tag == 'ol':
            self.in_list = True
            self.print_line("1. ")
        elif tag == 'br':
            self.print("")  # New line.
        elif tag == 'script':
            self.in_script = True
        elif tag == 'p':
            self.print("")
        elif tag == 'span':
            text_color = BlogDumpParser.what_color_is_this(check_attr(attrs, 'style'))
            if text_color == 'light-blue':
                self.in_title = True
        elif tag == 'div' and 'txc-textbox' in check_attr(attrs, 'class'):
            box_color = BlogDumpParser.what_color_is_this(check_attr(attrs, 'style'))
            if box_color == 'blue':
                self.print("```cpp")
            elif box_color == 'red':
                self.print("```warning")
            else:
                self.print("```info")
            self.in_box = True
            self.current_div_cnt = self.div_cnt
        elif tag == 'div':
            self.div_cnt += 1

    def handle_endtag(self, tag):
        if tag == 'ul' or tag == 'ol':
            self.in_list = False
        elif tag == 'script':
            self.in_script = False
        elif tag == 'div' and self.div_cnt > self.current_div_cnt:
            self.div_cnt -= 1
        elif tag == 'div' and self.in_box and self.div_cnt == self.current_div_cnt:
            self.in_box = False
            self.print("\n```")

    def handle_data(self, data):
        if self.in_script:
            return

        if self.in_title:
            self.print_line("### ")
            self.in_title = False

        stripped = BlogDumpParser.remove_whitespace(data)
        if not BlogDumpParser.is_only_whitespace(stripped):
            self.print_line(data)

class BlogDumpParser:
    def __init__(self, filename):
        self.filename = filename
        self.in_box = False
        self.in_list = False
        self.in_title = False
        self.in_script = False
        self.current_box_parent = None
        self.current_list_parent = None
        self.in_what_env = None

        output_file_name = filename.split('.')
        output_file_name[-1] = 'md'
        output_file_name = '.'.join(output_file_name)
        output_file_name = output_file_name.split('/')
        output_file_name[1] = 'md'
        output_file_name = '/'.join(output_file_name)

        self.output_file = open(output_file_name, 'w')

    @staticmethod
    def remove_whitespace(line):
        line = line.translate({ord(i): None for i in '\n'})
        return line.rstrip()

    @staticmethod
    def replace_bracket(s):
        s = s.replace("]", "")
        s = s.replace(")", "")
        return s

    @staticmethod
    def is_only_whitespace(line):
        for i in range(len(line)):
            if line[i] != ' ' or line[i] == '\n':
                return False
        return True

    @staticmethod
    def srcset_to_src(srcset):
        src = srcset.split(' ')[0]
        src = src[2:]
        src = "http://" + src
        return src

    @staticmethod
    def what_color_is_this(style):
        if 'rgb(254, 222, 199)' in style:
            return 'red'
        elif 'rgb(219, 232, 251)' in style:
            return 'blue'
        elif 'rgb(243, 197, 52)' in style:
            return 'yellow'
        elif 'rgb(48, 88, 210)' in style:
            return 'light-blue'

    def check_box_ended(self, current):
        if self.in_box and self.current_box_parent in current.parent:
            self.in_box = False
            return True
        return False

    def check_list_ended(self, current):
        if self.in_list and self.current_list_parent in current.parent:
            self.in_list = False
            return True
        return False

    def print_line(self, line):
        self.output_file.write(line)

    def print(self, line):
        self.output_file.write(line + '\n')

    def parse(self):
        with open(self.filename) as file:
            soup = BeautifulSoup(file, "lxml")
            for current in soup.recursiveChildGenerator():
                try:
                    if self.check_box_ended(current):
                        self.print("\n```")
                    elif self.check_list_ended(current):
                        self.print("")

                    # Check for tags here.
                    tag = current.name
                    if tag == 'img':
                        self.print("![{0}]({1})".format(BlogDumpParser.replace_bracket(current.attrs['alt']),
                                                        BlogDumpParser.srcset_to_src(
                                                            BlogDumpParser.replace_bracket(current.attrs['srcset']))))
                    elif tag == 'ul' or tag == 'ol':
                        self.in_list = True
                        self.current_list_parent = current
                        self.in_what_env = tag
                    elif tag == 'li':
                        if self.in_what_env == 'ul':
                            self.print_line("\n* ")
                        elif self.in_what_env == 'ol':
                            self.print_line("\n1. ")
                    elif tag == 'br':
                        self.print("")  # New line.
                    elif tag == 'script':
                        self.in_script = True
                    elif tag == 'p':
                        self.print("")
                    elif tag == 'span':
                        text_color = BlogDumpParser.what_color_is_this(current.attrs['style'])
                        if text_color == 'light-blue':
                            self.in_title = True
                    elif 'txc-textbox' in current.attrs['class']:
                        box_color = BlogDumpParser.what_color_is_this(current.attrs['style'])
                        if box_color == 'blue':
                            self.print("```cpp")
                        elif box_color == 'red':
                            self.print("```warning")
                        else:
                            self.print("```info")
                        self.in_box = True
                        self.current_box_parent = current
                        self.in_what_env = box_color
                except KeyError:
                    continue
                except:
                    if self.in_script:
                        self.in_script = False
                        continue

                    stripped = BlogDumpParser.remove_whitespace(current)
                    if not BlogDumpParser.is_only_whitespace(stripped):
                        if self.in_title:
                            self.print_line('###')
                            self.in_title = False
                        self.print_line(stripped)
                    else:
                        self.in_title = False
        self.output_file.close()


if __name__ == "__main__":
    with tqdm(os.listdir('./blog')) as t:
        for filename in t:
            t.set_description("Dump : " + filename)
            if 'comment' in filename:
                continue
            blog_dump = BlogDumpHtmlParser(os.path.join('./blog', filename))
            blog_dump.parse()
    '''
    blog_dump = BlogDumpHtmlParser(os.path.join('./blog/dump_test.html'))
    blog_dump.parse()
    '''