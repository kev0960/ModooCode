#include "driver.h"

#include <fstream>
#include <unordered_map>

#include "json.h"
#include "path.h"
#include "util.h"

namespace md_parser {
namespace {

string GetOutputFile(const string& s) {
  string filename = s.substr(s.find_last_of("/") + 1);
  string filename_without_ext = filename.substr(0, filename.find_last_of("."));
  filename_without_ext.replace(0, 4, "blog");
  return StrCat("../views/old/", filename_without_ext, ".html");
}

string GetFileId(const string& filename) {
  // Old file. In dump_(file name).md form.
  if (filename.find("dump_") != string::npos) {
    return string(filename.begin() + filename.find_last_of("_") + 1,
                  filename.begin() + filename.find_last_of('.'));
  }
  // Otherwise, name of the file itself is the file index.
  return filename.substr(filename.find_last_of("/") + 1);
}

}  // namespace

bool Driver::ProcessFiles(const std::vector<string>& filenames) {
  for (const auto& filename : filenames) {
    // Read the file.
    std::ifstream read_file(filename);
    std::string content;
    read_file.seekg(0, std::ios::end);
    content.reserve(read_file.tellg());
    read_file.seekg(0, std::ios::beg);

    content.assign((std::istreambuf_iterator<char>(read_file)),
                   std::istreambuf_iterator<char>());

    parsers_.emplace_back(new MDParser(content));
    parsers_.back()->Parser();
  }

  if (!config_.no_output_parsed) {
    int parser_index = 0;
    for (const auto& filename : filenames) {
      std::cerr << "Output [" << parser_index + 1 << "/" << filenames.size()
                << "] " << GetOutputFile(filename) << std::endl;
      std::ofstream output_file(GetOutputFile(filename));
      string file_index(filename.begin() + filename.find_last_of("_") + 1,
                        filename.begin() + filename.find_last_of("."));
      // file_info[file_index] = parsers_[parser_index]->GetHeaderInfo();
      output_file << parsers_[parser_index]->ConvertToHtml();
      parser_index++;
    }
  }

  // Generate the page related info.
  std::map<string, std::map<string, string>> file_info;
  std::unordered_map<string, string> path_defined_files;
  for (size_t i = 0; i < filenames.size(); i++) {
    const auto& header_info = parsers_[i]->GetHeaderInfo();
    if (header_info.find("path") != header_info.end()) {
      path_defined_files[GetFileId(filenames[i])] = header_info.at("path");
    }
    file_info[GetFileId(filenames[i])] = header_info;
  }

  if (!config_.no_dump_file_info) {
    Json file_info_json("../file_headers.json");
    file_info_json.DumpJson(file_info_json.JsonSerialize(file_info));
  }

  if (!config_.no_dump_page_path) {
    PathReader reader(path_defined_files);
    bool page_path_json_or_not =
        reader.ReadAndBuildPagePath("./data/old_category.txt");
    if (page_path_json_or_not) {
      std::ofstream output_json("../page_path.json");
      output_json << reader.DumpPagePath();

      std::ofstream output_sitemap("../sitemap.xml");
      output_sitemap << reader.GenerateSiteMap();
    }
  }
}

}  // namespace md_parser
