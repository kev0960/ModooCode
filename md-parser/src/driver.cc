#include "driver.h"

#include <algorithm>
#include <experimental/filesystem>
#include <fstream>
#include <unordered_map>

#include "json.h"
#include "path.h"
#include "util.h"

namespace md_parser {
namespace {

string GetOutputFile(const string& s) {
  bool is_old_file = false;
  if (s.find("python") != string::npos) {
    is_old_file = true;
  }

  string filename = s.substr(s.find_last_of("/") + 1);
  string filename_without_ext = filename.substr(0, filename.find_last_of("."));

  string output_dir_name;
  if (is_old_file) {
    filename_without_ext.replace(0, 4, "blog");
    output_dir_name = "../views/old/";
  } else {
    output_dir_name = "../views/new/";
  }
  return StrCat(output_dir_name, filename_without_ext, ".html");
}

string GetFileId(const string& filename) {
  // Old file. In dump_(file name).md form.
  if (filename.find("dump_") != string::npos) {
    return string(filename.begin() + filename.find_last_of("_") + 1,
                  filename.begin() + filename.find_last_of('.'));
  }
  // Otherwise, name of the file itself is the file index.
  return string(filename.begin() + filename.find_last_of("/") + 1,
                filename.begin() + filename.find_last_of("."));
}

void ReadFileInfo(
    std::unordered_map<string, struct timespec>* file_id_to_stat_map) {
  std::ifstream in("../file_info_db");
  string line;
  while (std::getline(in, line)) {
    auto delimiter = line.find(":");
    string file_id = line.substr(0, delimiter);
    string timespec_part = line.substr(delimiter + 1);

    time_t tv_sec = std::stoi(timespec_part.substr(0, timespec_part.find(",")));
    time_t tv_nsec =
        std::stoi(timespec_part.substr(timespec_part.find(",") + 1));
    struct timespec spec {
      tv_sec, tv_nsec
    };
    (*file_id_to_stat_map)[file_id] = spec;
  }
}

bool TimeSpecEquals(const timespec& a, const timespec b) {
  if (a.tv_nsec != b.tv_nsec || a.tv_sec != b.tv_sec) {
    return false;
  }
  return true;
}

// Remove unmodified files.
std::set<string> GetUnModifiedFiles(
    const std::vector<string>& filenames,
    std::unordered_map<string, struct timespec>* file_id_to_stat_map) {
  struct stat file_info;
  std::set<string> unmodified_files;

  for (const auto& filename : filenames) {
    // Error has happened!
    if (stat(filename.c_str(), &file_info) == -1) {
      LOG << "Something wrong with file : " << filename;
      continue;
    }
    const string file_id = GetFileId(filename);
    if (Contains(*file_id_to_stat_map, file_id) &&
        TimeSpecEquals(file_id_to_stat_map->at(file_id), file_info.st_mtim)) {
      unmodified_files.insert(file_id);
    } else {
      std::cerr << "Diff : " << filename << std::endl;
      (*file_id_to_stat_map)[file_id] = file_info.st_mtim;
    }
  }
  return unmodified_files;
}

void WriteFileToStatMap(
    const std::unordered_map<string, struct timespec>& file_id_to_stat_map) {
  std::ofstream out("../file_info_db");
  for (const auto& kv : file_id_to_stat_map) {
    out << kv.first << ":" << kv.second.tv_sec << "," << kv.second.tv_nsec
        << std::endl;
  }
}

void ReferenceToUrls(
    const std::map<string, std::map<string, string>>& file_info,
    std::unordered_map<string, std::vector<ReferenceInfo>>* ref_to_url,
    std::unordered_map<string, std::vector<string>>* file_id_to_path_vec,
    const PathReader& path_reader) {
  for (const auto& kv : file_info) {
    const auto cat_title = kv.second.find("cat_title");
    const auto path_vector = path_reader.GetVectorFilePath(kv.first);
    (*file_id_to_path_vec)[kv.first] = path_vector;

    if (cat_title != kv.second.end()) {
      if (path_reader.IsThisFileReference(kv.first)) {
        std::cout << kv.first << " --> " << cat_title->second << std::endl;
        (*ref_to_url)[cat_title->second].push_back({path_vector, kv.first});
      }
    }
    const auto ref_title = kv.second.find("ref_title");
    if (ref_title != kv.second.end()) {
      const auto ref_titles = Split(ref_title->second, ',');
      for (auto ref : ref_titles) {
        Trim(&ref);
        (*ref_to_url)[ref].push_back({path_vector, kv.first});
      }
    }
  }
}
}  // namespace

Driver::Driver(const DriverConfig& config) : config_(config) {
  ReadFileInfo(&file_id_to_stat_map_);
}

bool Driver::ProcessFiles(const std::vector<string>& filenames) {
  std::set<string> files_not_to_process;
  if (!config_.force_parse_all) {
    files_not_to_process = GetUnModifiedFiles(filenames, &file_id_to_stat_map_);
  }

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
    if (Contains(files_not_to_process, GetFileId(filename))) {
      parsers_.back()->Parser(ParserConfig{true /* Only parse header */});
    } else {
      parsers_.back()->Parser(ParserConfig{});
    }
  }

  // Generate the page related info.
  std::map<string, std::map<string, string>> file_info;
  std::map<string, string> next_page_map;
  std::unordered_map<string, string> path_defined_files;
  for (size_t i = 0; i < filenames.size(); i++) {
    const auto& header_info = parsers_[i]->GetHeaderInfo();
    if (Contains(header_info, string("path"))) {
      path_defined_files[GetFileId(filenames[i])] = header_info.at("path");
    }
    if (Contains(header_info, string("next_page"))) {
      next_page_map[GetFileId(filenames[i])] = header_info.at("next_page");
    }
    file_info[GetFileId(filenames[i])] = header_info;
  }

  // Add prev_page from the next_page info.
  for (const auto& kv : next_page_map) {
    file_info[kv.second]["prev_page"] = kv.first;
  }

  if (!config_.no_dump_file_info) {
    Json file_info_json("../file_headers.json");
    file_info_json.DumpJson(file_info_json.JsonSerialize(file_info));
  }

  PathReader reader(path_defined_files);
  bool page_path_json_or_not =
      reader.ReadAndBuildPagePath("./data/old_category.txt");
  reader.SortPathFiles(file_info);
  if (page_path_json_or_not) {
    std::ofstream output_json("../page_path.json");
    output_json << reader.DumpPagePath();

    std::ofstream output_sitemap("../views/sitemap.xml");
    output_sitemap << reader.GenerateSiteMap();
  }

  // Build a reference to url table.
  std::unordered_map<string, std::vector<ReferenceInfo>> ref_to_url;
  std::unordered_map<string, std::vector<string>> file_id_to_path_vec;

  ReferenceToUrls(file_info, &ref_to_url, &file_id_to_path_vec, reader);
  if (!config_.no_output_parsed) {
    int parser_index = 0;
    // Create an output directory (if not exist)
    string output_dir_name = "";
    std::experimental::filesystem::create_directories("../views/old");
    std::experimental::filesystem::create_directories("../views/new");

    for (const auto& filename : filenames) {
      if (Contains(files_not_to_process, GetFileId(filename))) {
        parser_index++;
        continue;
      }
      std::cerr << "Output [" << parser_index + 1 << "/" << filenames.size()
                << "] " << GetOutputFile(filename) << std::endl;
      std::ofstream output_file(GetOutputFile(filename));
      /*
      string file_index(filename.begin() + filename.find_last_of("_") + 1,
                        filename.begin() + filename.find_last_of("."));*/
      // file_info[file_index] = parsers_[parser_index]->GetHeaderInfo();
      output_file << parsers_[parser_index]->ConvertToHtml(
          &ref_to_url, file_id_to_path_vec[GetFileId(filename)]);
      parser_index++;
    }
  }

  WriteFileToStatMap(file_id_to_stat_map_);
  return true;
}

}  // namespace md_parser
