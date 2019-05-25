#include "parser_environment.h"

#include "content.h"
#include "content_list.h"
#include "util.h"

namespace md_parser {
namespace {

int IndentSize(std::pair<int, int> space_and_tab) {
  return space_and_tab.first + 2 * space_and_tab.second;
}

bool IsList(TokenTypes list_type) {
  switch (list_type) {
    case LIST_ENUM:
    case LIST_UNORDER:
      return true;
    default:
      return false;
  }
  return false;
}
}  // namespace

EnumListManager::EnumListManager() {}

void EnumListManager::AddNextList(const std::pair<int, int>& space_and_tab) {
  int indent_size = IndentSize(space_and_tab);

  // 2 spaces ==> One indent.
  int depth = indent_size / spaces_per_indent;

  while (!state_.empty()) {
    auto& depth_and_enum = state_.top();
    if (depth_and_enum.first == depth) {
      depth_and_enum.second += 1;
      return;
    } else if (depth_and_enum.first > depth) {
      state_.push(std::make_pair(depth, 0));
      break;
    }

    state_.pop();
  }
  state_.push(std::make_pair(depth, 0));
}

std::pair<int, int> EnumListManager::GetCurrentEnum() const {
  return state_.top();
}

ParserEnvironment::ParserEnvironment()
    : current_content_(0), header_index_(0), ref_to_url_(nullptr) {}

std::pair<int, int> ParserEnvironment::GetCurrentListInfo(
    const TokenTypes type) const {
  switch (type) {
    case LIST_ENUM:
      return enum_list_manager_.GetCurrentEnum();
    case LIST_UNORDER:
      return unordered_list_manager_.GetCurrentEnum();
    default:
      break;
  }
  return std::make_pair(0, 0);
}

std::pair<int, int> ParserEnvironment::GetCurrentEnum(
    const TokenTypes list_type) const {
  if (list_type == LIST_ENUM) return enum_list_manager_.GetCurrentEnum();
  return unordered_list_manager_.GetCurrentEnum();
}

void ParserEnvironment::AddNextList(const TokenTypes type,
                                    const std::pair<int, int>& space_and_tab) {
  switch (type) {
    case LIST_ENUM:
      enum_list_manager_.AddNextList(space_and_tab);
      break;
    case LIST_UNORDER:
      unordered_list_manager_.AddNextList(space_and_tab);
      break;
    default:
      break;
  }
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

bool ParserEnvironment::ShouldStartNewListTag() {
  if (current_content_ == 0) return true;
  auto* current_content = content_list_[current_content_].get();
  int current_depth = dynamic_cast<ListContent*>(current_content)->GetDepth();
  int current = current_content_ - 1;
  while (true) {
    auto* previous_content = content_list_[current].get();
    if (IsList(previous_content->GetContentType())) {
      if (previous_content->GetContentType() ==
          current_content->GetContentType()) {
        // If they are in same list type, then check whether the indentation is
        // identical. If they are identical, then there is no reason to start a
        // new list tag.
        auto* prev_list = dynamic_cast<ListContent*>(previous_content);
        if (prev_list->GetDepth() < current_depth) {
          return true;
        } else if (prev_list->GetDepth() == current_depth) {
          return false;
        }
        if (current == 0) return true;
        current--;
        continue;
      } else {
        return true;
      }
    }
    return true;
  }

  return false;
}

int ParserEnvironment::ShouldEndListTag() {
  auto* current_content = content_list_[current_content_].get();
  int next_depth = 0;
  int current_depth = dynamic_cast<ListContent*>(current_content)->GetDepth();
  // First need to check there is need to close the tag.
  if (current_content_ < content_list_.size() - 1) {
    auto* next_content = content_list_[current_content_ + 1].get();
    if (IsList(next_content->GetContentType())) {
      if (next_content->GetContentType() == current_content->GetContentType()) {
        auto* next_list = dynamic_cast<ListContent*>(next_content);
        if (current_depth <= next_list->GetDepth()) {
          return 0;
        }
        next_depth = next_list->GetDepth();
      }
    }
  }
  // This means that we are just closing the first tag.
  if (current_content_ == 0) {
    return 1;
  }
  // Now we have to trace back from where we should close the tag.
  size_t current = current_content_ - 1;
  int closing_tag_count = 1;
  int current_least_depth = current_depth;
  while (true) {
    auto* prev_content = content_list_[current].get();
    if (IsList(prev_content->GetContentType())) {
      if (prev_content->GetContentType() == current_content->GetContentType()) {
        auto* prev_list = dynamic_cast<ListContent*>(prev_content);
        // Found the first parent list.
        if (prev_list->GetDepth() > next_depth) {
          if (prev_list->GetDepth() < current_least_depth) {
            current_least_depth = prev_list->GetDepth();
            closing_tag_count++;
          }
          if (current == 0) break;
          current--;
          continue;
        }
      }
    }
    break;
  }
  return closing_tag_count;
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
}  // namespace md_parser
