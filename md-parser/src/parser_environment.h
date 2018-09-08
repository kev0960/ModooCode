#pragma once
#include <memory>
#include <stack>
#include <string>
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

 private:
  EnumListManager enum_list_manager_;
  EnumListManager unordered_list_manager_;

  // List of parsed contents of MD file.
  std::vector<std::unique_ptr<Content>> content_list_;

  size_t current_content_;
};
}  // namespace md_parser
