#include "parser_environment.h"

#include "content.h"
#include "content_list.h"
#include "util.h"

namespace md_parser {
namespace {

int IndentSize(std::pair<int, int> space_and_tab) {
  return space_and_tab.first + 2 * space_and_tab.second;
}
}  // namespace

ListManager::ListManager() { depths_.push_back(std::make_pair(-1, -1)); }

size_t ListManager::AddNextList(const std::pair<int, int>& space_and_tab,
                                int type) {
  int indent_size = IndentSize(space_and_tab);

  // 2 spaces ==> One indent.
  int depth = indent_size / spaces_per_indent;

  depths_.push_back(std::make_pair(depth, type));

  return depths_.size() - 1;
}

void ListManager::MarkEndOfList() {
  if (depths_.back().first != -1) {
    depths_.emplace_back(-1, -1);
  }
}

void ListManager::Compute() {
  // First we have to compute the size of the box for every lists.
  for (size_t index = 0; index < depths_.size(); index++) {
    if (depths_[index].second == -1) {
      continue;
    }

    int current_depth = depths_[index].first;
    int current_type = depths_[index].second;

    // Creates a new box when current bullet is not included in any
    // box with same depth yet.
    bool found_box = false;
    if (MapContains(boxes_, current_depth)) {
      auto& boxes_on_same_depth = boxes_[current_depth];
      for (const auto& box : boxes_on_same_depth) {
        if (box.box_start <= index && index <= box.box_end) {
          found_box = true;
          break;
        }
      }
    }

    if (!found_box) {
      // Find the end of the box. The box ends when
      //  1) Met higher level
      //  2) Same depth with different type.

      start_tags_.insert(index);
      for (size_t j = index + 1; j < depths_.size(); j++) {
        if (depths_[j].first < current_depth ||
            (depths_[j].second != current_type &&
             depths_[j].first == current_depth)) {
          boxes_[current_depth].emplace_back(index, j - 1);

          // Everytime we add a new box, we have to add the end tag.
          end_tags_[j - 1].insert(end_tags_[j - 1].begin(), current_type);
          break;
        }
      }
    }
  }
}

bool ListManager::ShouldStartNewListTag(size_t index) const {
  return SetContains(start_tags_, index);
}

std::vector<int> ListManager::GetEndListTag(size_t index) const {
  if (MapContains(end_tags_, index)) {
    return end_tags_.at(index);
  }
  return {};
}

ParserEnvironment::ParserEnvironment()
    : current_content_(0), header_index_(0), ref_to_url_(nullptr) {}

size_t ParserEnvironment::AddNextList(
    const TokenTypes type, const std::pair<int, int>& space_and_tab) {
  switch (type) {
    case LIST_ENUM:
      return list_manager_.AddNextList(space_and_tab, 0);
      break;
    case LIST_UNORDER:
      return list_manager_.AddNextList(space_and_tab, 1);
      break;
    default:
      break;
  }
  return -1;
}

void ParserEnvironment::AddNewContent(Content* content) {
  content_list_.emplace_back(content);
}

bool ParserEnvironment::AppendToLastContent(const string& content) {
  if (content_list_.empty()) return false;
  content_list_.back()->AddContent(content);
  return true;
}

// Add to the previous content if the content type matches. If so, then it
// destrorys the passed "content". Otherwise it creates a new content based on
// the passed argument.
void ParserEnvironment::AppendOrCreateContent(Content* content,
                                              const string& line) {
  if (!content_list_.empty() &&
      content_list_.back()->GetContentType() == content->GetContentType()) {
    content_list_.back()->AddContent(line);
    delete content;
  } else {
    content_list_.emplace_back(content);
  }
}

const std::vector<std::unique_ptr<Content>>& ParserEnvironment::GetContentList()
    const {
  return content_list_;
}

string ParserEnvironment::ParseCurrentContent() {
  if (current_content_ >= content_list_.size()) return "";

  std::unique_ptr<Content>& content = content_list_[current_content_];
  content->Preprocess(this);
  string html = content->OutputHtml(this);
  return html;
}

string ParserEnvironment::ParseCurrentContentToLatex() {
  if (current_content_ >= content_list_.size()) return "";

  std::unique_ptr<Content>& content = content_list_[current_content_];
  content->Preprocess(this);
  string latex = content->OutputLatex(this);
  return latex;
}

const Content& ParserEnvironment::GetCurrentContent() const {
  return *content_list_[current_content_];
}

bool ParserEnvironment::ShouldStartNewListTag(size_t index) {
  return list_manager_.ShouldStartNewListTag(index);
}

std::vector<int> ParserEnvironment::GetEndListTag(size_t index) {
  return list_manager_.GetEndListTag(index);
}

// Return the url string if the ref_name is a entry of the reference.
// Otherwise, return an empty string.
string ParserEnvironment::GetUrlOfReference(string* ref_name) {
  if (ref_to_url_ == nullptr) {
    return "";
  }
  auto delim = ref_name->find("$");

  string specifier;
  if (delim != string::npos) {
    specifier.assign(ref_name->begin() + delim + 1, ref_name->end());
    ref_name->erase(ref_name->begin() + delim, ref_name->end());
  }

  auto result = ref_to_url_->find(*ref_name);
  if (result == ref_to_url_->end()) {
    return "";
  }

  // Now have to find the best fit.
  const auto& reference_infos = result->second;
  if (specifier.empty()) {
    for (const string& current_path : path_vector_) {
      for (const ReferenceInfo& info : reference_infos) {
        const auto& paths = info.paths;
        for (const string& path : paths) {
          if (current_path == path) {
            return info.url;
          }
        }
      }
    }
  } else {
    for (const ReferenceInfo& info : reference_infos) {
      const auto& paths = info.paths;
      for (const string& path : paths) {
        if (specifier == path) {
          return info.url;
        }
      }
    }
    return "";
  }

  // This part will not likely to be reached due to the root directory.
  // But just in case something happens.
  LOG << "ERROR :: Root directory not found? " << ref_name << " " << specifier
      << path_vector_.size();
  for (const string& current_path : path_vector_) {
    LOG << "Path vector : " << current_path;
  }
  for (const ReferenceInfo& info : reference_infos) {
    const auto& paths = info.paths;
    for (const string& path : paths) {
      LOG << "Ref path : " << path;
    }
  }
  return reference_infos[0].url;
}

string ParserEnvironment::GetPageTitle() {
  if (header_.find("cat_title") != header_.end()) {
    return header_["cat_title"];
  } else if (header_.find("title") != header_.end()) {
    return header_["title"];
  }
  return "";
}

bool ParserEnvironment::AdvanceToNextContent() {
  current_content_++;
  return current_content_ < content_list_.size();
}

void ParserEnvironment::ResetContentPointer() { current_content_ = 0; }

void ParserEnvironment::MarkEndOfList() { list_manager_.MarkEndOfList(); }

void ParserEnvironment::ParseDone() {
  list_manager_.MarkEndOfList();
  list_manager_.Compute();
}

}  // namespace md_parser
