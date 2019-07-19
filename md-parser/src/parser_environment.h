#pragma once
#include <map>
#include <memory>
#include <set>
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

class ListManager {
 public:
  struct Box {
    size_t box_start;  // Index of the first bullet included in the box.
    size_t box_end;    // Index of the last bullet included in the box.

    Box(size_t box_start, size_t box_end)
        : box_start(box_start), box_end(box_end) {}
  };

  ListManager();

  // Returns the location of currently added depth info.
  // type : 0 (Enum), 1 (Unordered)
  size_t AddNextList(const std::pair<int, int>& space_and_tab, int type);

  void MarkEndOfList();
  void Compute();

  bool ShouldStartNewListTag(size_t index) const;

  // 0 : Enum ; 1 : Unordered
  std::vector<int> GetEndListTag(size_t index) const;

 private:
  static const int spaces_per_indent = 2;

  // Pair of depth, type
  std::vector<std::pair<int, int>> depths_;

  // Index to end tag string (</ul>, </ol>)
  std::map<size_t, std::vector<int>> end_tags_;
  std::set<size_t> start_tags_;

  // depth to list of boxes with same depth.
  std::map<int, std::vector<Box>> boxes_;
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
  size_t AddNextList(const TokenTypes type,
                     const std::pair<int, int>& space_and_tab);
  std::pair<int, int> GetCurrentEnum(const TokenTypes list_type) const;
  const std::vector<std::unique_ptr<Content>>& GetContentList() const;
  string ParseCurrentContent();
  string ParseCurrentContentToLatex();

  bool AdvanceToNextContent();
  void ResetContentPointer();
  bool ShouldStartNewListTag(size_t index);
  const Content& GetCurrentContent() const;
  std::vector<int> GetEndListTag(size_t index);

  int GetHeaderIndex() { return ++header_index_; }
  void SetRefToUrl(
      std::unordered_map<string, std::vector<ReferenceInfo>>* ref_to_url,
      const std::vector<string>& path_vector) {
    ref_to_url_ = ref_to_url;
    path_vector_ = path_vector;
  }
  void SetHeader(std::map<string, string>& header) { header_ = header; }
  void MarkEndOfList();
  void ParseDone();

  string GetUrlOfReference(string* ref_name);
  string GetPageTitle();

 private:
  ListManager list_manager_;

  // List of parsed contents of MD file.
  std::vector<std::unique_ptr<Content>> content_list_;

  size_t current_content_;
  int header_index_;
  std::unordered_map<string, std::vector<ReferenceInfo>>* ref_to_url_;
  std::vector<string> path_vector_;
  std::map<string, string> header_;
};
}  // namespace md_parser
