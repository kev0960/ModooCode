#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <set>
#include <streambuf>
#include <string>

#include "chroma.h"
#include "driver.h"
#include "fast_syntax_highlighter.h"

bool Contains(std::set<string>& st, const string& s) {
  return st.find(s) != st.end();
}

int main(int argc, char** argv) {
  std::set<string> args;
  for (int i = 1; i < argc; i++) {
    args.insert(string(argv[i]));
  }
  md_parser::DriverConfig config;
  if (Contains(args, "-print-chroma-css")) {
    std::cout << GetChromaCss(argv[2]);
    return 0;
  }
  if (Contains(args, "-no_output_parsed")) {
    config.no_output_parsed = false;
  }
  if (Contains(args, "-no_dump_file_info")) {
    config.no_dump_file_info = false;
  }
  if (Contains(args, "-no_dump_page_path")) {
    config.no_dump_page_path = false;
  }

  std::vector<string> filenames;
  std::vector<string> md_paths = {"../python/md"};

  if (Contains(args, "-md")) {
    md_paths.push_back("../md");
  }

  for (const auto& arg : args) {
    if (arg[0] != '-') {
      filenames.push_back(arg);
    }
  }
  if (filenames.empty()) {
    for (const auto& md_path : md_paths) {
      for (auto& p :
           std::experimental::filesystem::directory_iterator(md_path)) {
        filenames.push_back(p.path());
      }
    }
  }
  md_parser::FastSyntaxHighlighter synh("");
  synh.OutputColorCss("../views/css/vs-fast.css");

  md_parser::Driver driver(config);
  driver.ProcessFiles(filenames);
}
