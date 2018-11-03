#pragma once
#include <memory>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "token_types.h"

using std::string;

namespace md_parser {
// Forward declaration.
class Content;

class EnumListManager {
 public:
  EnumListManager();

  void AddNextList(const std::pair<int, int>& space_and_tab);
  std::pair<int, int> GetCurrentEnum() const;

 private:
  static const int spaces_per_indent = 2;
  std::stack<std::pair</* depth */ int, /* enum */ int>> state_;
};

struct ReferenceInfo {
  std::vector<string> paths;
  string url;
};

class ParserEnvironment {
 public:
  ParserEnvironment();

  std::pair<int, int> GetCurrentListInfo(const TokenTypes type) const;
  void AddNewList(const TokenTypes list_type,
                  const std::pair<int, int>& space_and_tab, const string& line);
  void AddNewContent(Content* content);
  bool AppendToLastContent(const string& content);
  void AppendOrCreateContent(Content* content, const string& line);
  void AddNextList(const TokenTypes type,
                   const std::pair<int, int>& space_and_tab);
  std::pair<int, int> GetCurrentEnum(const TokenTypes list_type) const;
  const std::vector<std::unique_ptr<Content>>& GetContentList() const;
  string ParseCurrentContent();
  bool AdvanceToNextContent();
  bool ShouldStartNewListTag();

  // Return How many end tags should it return.
  int ShouldEndListTag();
  int GetHeaderIndex() { return ++header_index_; }
  void SetRefToUrl(
      std::unordered_map<string, std::vector<ReferenceInfo>>* ref_to_url,
      const std::vector<string>& path_vector) {
    ref_to_url_ = ref_to_url;
    path_vector_ = path_vector;
  }

  string GetUrlOfReference(const string& ref_name);

 private:
  EnumListManager enum_list_manager_;
  EnumListManager unordered_list_manager_;

  // List of parsed contents of MD file.
  std::vector<std::unique_ptr<Content>> content_list_;

  size_t current_content_;
  int header_index_;
  std::unordered_map<string, std::vector<ReferenceInfo>>* ref_to_url_;
  std::vector<string> path_vector_;
};
}  // namespace md_parser
