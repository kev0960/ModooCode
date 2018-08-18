#pragma once
#include <memory>
#include <stack>
#include <utility>
#include "content.h"

namespace md_parser {
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
  void AddNextList(const TokenTypes type,
                   const std::pair<int, int>& space_and_tab);
  void AddNewContent(Content&& content);
  void AppendToLastContent(const string& content);

 private:
  EnumListManager enum_list_manager_;
  EnumListManager unordered_list_manager_;

  // List of parsed contents of MD file.
  std::vector<std::unique_ptr<Content>> content_list_;
};
}
