#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <string>
#include "parser.h"
#include "util.h"

string GetOutputFile(const string& s) {
  string filename = s.substr(s.find_last_of("/") + 1);
  string filename_without_ext = filename.substr(0, filename.find_last_of("."));
  filename_without_ext.replace(0, 4, "blog");
  return md_parser::StrCat("../views/old/", filename_without_ext, ".html");
}

int main(int argc, char** argv) {
  std::vector<string> filenames;
  if (argc > 1) {
    filenames.push_back(argv[1]);
  } else {
    for (auto& p :
         std::experimental::filesystem::directory_iterator("../python/md")) {
      filenames.push_back(p.path());
    }
  }
  for (const auto& filename : filenames) {
    std::cerr << "Reading File : " << filename << std::endl;
    std::cerr << "Output File  : " << GetOutputFile(filename) << std::endl;
    std::ifstream read_file(filename);
    std::string content;
    read_file.seekg(0, std::ios::end);
    content.reserve(read_file.tellg());
    read_file.seekg(0, std::ios::beg);

    content.assign((std::istreambuf_iterator<char>(read_file)),
                   std::istreambuf_iterator<char>());

    md_parser::MDParser parser(content);
    parser.Parser();
    /*
    std::cout << parser.ConvertToHtml();
    */
    std::ofstream output_file(GetOutputFile(filename));
    output_file << parser.ConvertToHtml();
    output_file << "<style>" << parser.GetCss() << "</style>";
  }
}
