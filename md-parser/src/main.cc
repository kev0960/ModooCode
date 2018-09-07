#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <set>
#include <streambuf>
#include <string>

#include "driver.h"

bool Contains(std::set<string>& st, const string& s) {
  return st.find(s) != st.end();
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

  std::set<string> args;
  for (int i = 1; i < argc; i++) {
    args.insert(string(argv[i]));
  }
  md_parser::DriverConfig config;
  if (Contains(args, "no_output_parsed")) {
    config.no_output_parsed = false;
  }
  if (Contains(args, "no_dump_file_info")) {
    config.no_dump_file_info = false;
  }
  if (Contains(args, "no_dump_page_path")) {
    config.no_dump_page_path = false;
  }

  md_parser::Driver driver(config);
  driver.ProcessFiles(filenames);
}
