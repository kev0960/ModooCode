#include <fstream>
#include <iostream>
#include <streambuf>
#include <string>

#include "parser.h"
int main(int argc, char** argv) {
  string filename;
  if (argc > 1) {
    filename = argv[1];
  }
  std::cerr << "Reading File : " << filename << std::endl;
  std::ifstream read_file(filename);
  std::string content;
  read_file.seekg(0, std::ios::end);
  content.reserve(read_file.tellg());
  read_file.seekg(0, std::ios::beg);

  content.assign((std::istreambuf_iterator<char>(read_file)),
      std::istreambuf_iterator<char>());

  md_parser::MDParser parser(content);
  parser.Parser();
  std::cout << parser.ConvertToHtml();
  std::cout << "<style>" << parser.GetCss() << "</style>";
}
