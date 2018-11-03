#include "path.h"

#include <algorithm>
#include <fstream>

#include "util.h"

namespace md_parser {
namespace {

inline string ToJsonString(const std::string& s) { return "\"" + s + "\""; }

}  // namespace

PageStructure::PageStructure(bool is_root_page, const string& current_page_dir)
    : is_root_page_(is_root_page), current_page_dir_(current_page_dir) {
  if (is_root_page_ && !current_page_dir_.empty()) {
    std::cout << "Root page is not empty!" << std::endl;
  }
}

string PageStructure::GetDirName() const { return current_page_dir_; }

bool PageStructure::ParsePathAndAdd(const string& page_path) {
  if (page_path.size() == 0 || page_path[0] != '/') {
    return false;
  }
  // Erase the first '/'
  string current_path = page_path.substr(1);
  // Get the current directory name.
  auto path_name_end = current_path.find("/");
  if (path_name_end == string::npos) {
    // Then current path is a directory.
    pages_.insert(current_path);
    return true;
  } else if (path_name_end == current_path.size() - 1) {
    // Some times the path can end with the redundant /.
    // (e.g) /a/b/ ==> This is actually equivalent to /a/b
    pages_.insert(current_path.substr(0, current_path.size() - 1));
    return true;
  }
  // Check whether the current directory is equivalent to the current page dir.
  string page_dir = current_path.substr(0, path_name_end);
  for (const auto& child : child_dirs_) {
    if (child->GetDirName() == page_dir) {
      return child->ParsePathAndAdd(current_path.substr(path_name_end));
    }
  }
  // Otherwise add new page.
  child_dirs_.emplace_back(new PageStructure(false, page_dir));
  return child_dirs_.back()->ParsePathAndAdd(
      current_path.substr(path_name_end));
}

bool PageStructure::CheckFileExists(const string& file_name) const {
  if (pages_.find(file_name) != pages_.end()) return true;
  for (size_t i = 0; i < child_dirs_.size(); i++) {
    if (child_dirs_[i]->CheckFileExists(file_name)) {
      return true;
    }
  }
  return false;
}

std::vector<string> PageStructure::GetVectorFilePath(
    const string& file_id) const {
  if (pages_.find(file_id) != pages_.end()) {
    std::vector<string> path;
    path.push_back(current_page_dir_);
    return path;
  }

  for (size_t i = 0; i < child_dirs_.size(); i ++) {
    auto path = child_dirs_[i]->GetVectorFilePath(file_id);
    if (!path.empty()) {
      path.push_back(current_page_dir_);
      return path;
    }
  }

  return std::vector<string>{};
}

const PageStructure* PageStructure::GetDirectoryByName(
    const string& dir_name) const {
  for (size_t i = 0; i < child_dirs_.size(); i++) {
    if (child_dirs_[i]->GetDirName() == dir_name) {
      return child_dirs_[i].get();
    }
  }
  return nullptr;
}

string PageStructure::DumpJson() const {
  string json = "";

  json += StrCat(ToJsonString(GetDirName()), ": {\n");

  // Files key is "files".
  json += ToJsonString("files") + ": [";
  if (sorted_pages_.empty()) {
    for (const auto& s : pages_) {
      json += StrCat(ToJsonString(s), ",");
    }
  } else {
    for (const auto& s : sorted_pages_) {
      json += StrCat(ToJsonString(s), ",");
    }
  }

  if (json.back() == ',') {
    json.pop_back();
  }
  if (child_dirs_.empty()) {
    json += "]\n";
  } else {
    json += "],\n";
  }
  // Now Add the directories.
  for (size_t i = 0; i < child_dirs_.size(); i++) {
    string end_mark = "";
    if (i == child_dirs_.size() - 1) {
      end_mark = "\n";
    } else {
      end_mark = ",\n";
    }
    json += StrCat(child_dirs_[i]->DumpJson(), end_mark);
  }
  json += "}";
  return json;
}

std::vector<string> PageStructure::FlattenIntoVector() const {
  std::vector<string> flatten;
  flatten.reserve(pages_.size());
  if (sorted_pages_.empty()) {
    for (const auto& page : pages_) {
      flatten.push_back(page);
    }
  } else {
    flatten = sorted_pages_;
  }

  for (const auto& child : child_dirs_) {
    const auto& child_flat = child->FlattenIntoVector();
    flatten.reserve(flatten.size() + child_flat.size());
    flatten.insert(flatten.end(), child_flat.begin(), child_flat.end());
  }
  return flatten;
}

void PageStructure::SortCurrentFiles(
    const std::map<string, std::map<string, string>>& file_info) {
  // Anchors are the pages that does not have previous page.
  std::vector<std::vector<string>> anchors_and_expansions;
  for (const auto& page : pages_) {
    if (!Contains(file_info, page)) {
      continue;
    }
    const auto& page_info = file_info.at(page);
    if (!Contains(page_info, string("prev_page"))) {
      anchors_and_expansions.push_back(std::vector<string>{page});
    }
  }
  for (auto& anchor : anchors_and_expansions) {
    while (true) {
      const string& page = anchor.back();
      if (!Contains(file_info, page)) {
        break;
      }
      const auto& info = file_info.at(page);
      if (!Contains(info, string("next_page"))) {
        break;
      }
      anchor.push_back(info.at("next_page"));
    }
  }
  // Now append anchors and its expansion to the sorted pages.
  sorted_pages_.reserve(pages_.size());
  for (const auto& anchor_and_expansion : anchors_and_expansions) {
    for (const auto& page : anchor_and_expansion) {
      sorted_pages_.push_back(page);
    }
  }
  for (const auto& child : child_dirs_) {
    child->SortCurrentFiles(file_info);
  }
}

PagePath::PagePath() : root_page_(std::make_unique<PageStructure>(true, "")) {}

bool PagePath::AddPagePath(const string& page_path) {
  return root_page_->ParsePathAndAdd(page_path);
}

string PagePath::DumpPageStructureToJson() {
  return StrCat("{\n", root_page_->DumpJson(), "\n}");
}

void PagePath::SortPathFiles(
    const std::map<string, std::map<string, string>>& file_info) {
  root_page_->SortCurrentFiles(file_info);
}

string PagePath::GenerateSiteMap() {
  string sitemap;
  const string sitemap_header = R"(<?xml version="1.0" encoding="UTF-8"?>)";
  const string urlset_open =
      R"(<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">)";
  const string url_close = R"(</urlset>)";
  const string root_address = R"(https://www.modoocode.com/)";

  sitemap = StrCat(sitemap_header, "\n", urlset_open, "\n");
  // Iterate through the page structure.
  const auto pages = root_page_->FlattenIntoVector();
  for (const string& page : pages) {
    string url = root_address + page;
    sitemap += StrCat("<url>\n", "<loc>", url, "</loc>\n</url>\n");
  }
  sitemap += url_close;
  return sitemap;
}

bool PagePath::CheckFileInDirectory(const string& dir_name,
                                    const string& file_name) const {
  const PageStructure* pg = root_page_->GetDirectoryByName(dir_name);
  if (pg != nullptr) {
    return pg->CheckFileExists(file_name);
  }
  return false;
}

std::vector<string> PagePath::GetVectorFilePath(
    const string& file_id) const {
  return root_page_->GetVectorFilePath(file_id);
}

bool PathReader::IsThisFileReference(const string& file_id) const {
  return path_.CheckFileInDirectory("C++ Reference", file_id) ||
         path_.CheckFileInDirectory("C Reference", file_id);
}

std::vector<string> PathReader::GetVectorFilePath(const string& file_id) const {
  return path_.GetVectorFilePath(file_id);
}

PathReader::PathReader() {}
PathReader::PathReader(const std::unordered_map<string, string>& excluded_files)
    : excluded_files_(excluded_files) {}

bool PathReader::ReadAndBuildPagePath(const string& filename) {
  std::ifstream in(filename);
  if (!in.good()) {
    return false;
  }

  for (string line; std::getline(in, line);) {
    // Parse the line.
    auto path_name_end = line.find(",");
    if (path_name_end == string::npos) {
      break;
    }
    // Get the path name.
    string path_name = line.substr(0, path_name_end);

    // Now fetch all the file names.
    auto next = path_name_end;
    while (next != string::npos) {
      auto next_comma = line.find(",", next + 1);
      int page_info_len = 0;
      if (next_comma == string::npos) {
        page_info_len = line.size() - (next + 1);
      } else {
        page_info_len = next_comma - (next + 1);
      }

      string page_info = line.substr(next + 1, page_info_len);
      std::vector<string> page_ids;
      auto range_delimiter = page_info.find("-");
      if (range_delimiter == string::npos) {
        page_ids.push_back(page_info);
      } else {
        int start = std::stoi(page_info.substr(0, range_delimiter), nullptr);
        int end = std::stoi(page_info.substr(range_delimiter + 1), nullptr);
        for (int i = start; i <= end; i++) {
          page_ids.push_back(std::to_string(i));
        }
      }
      // Now exclude files that are already inserted.
      page_ids.erase(std::remove_if(page_ids.begin(), page_ids.end(),
                                    [&](const string& page_id) {
                                      // Remove if file is in the exclued set.
                                      return excluded_files_.find(page_id) !=
                                             excluded_files_.end();
                                    }),
                     page_ids.end());

      for (const auto& s : page_ids) {
        path_.AddPagePath(path_name + "/" + s);
      }
      next = next_comma;
    }
  }
  // Finally add all the files that were excluded.
  for (const auto& kv : excluded_files_) {
    path_.AddPagePath(kv.second + "/" + kv.first);
  }
  return true;
}

void PathReader::SortPathFiles(
    const std::map<string, std::map<string, string>>& file_info) {
  path_.SortPathFiles(file_info);
}

string PathReader::DumpPagePath() { return path_.DumpPageStructureToJson(); }
string PathReader::GenerateSiteMap() { return path_.GenerateSiteMap(); }
}  // namespace md_parser
