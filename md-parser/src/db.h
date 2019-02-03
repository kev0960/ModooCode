// This database accessor tracks the change of MD files.
#pragma once
#include <memory>
#include <pqxx/pqxx>
#include <unordered_map>

#include "parser.h"

namespace md_parser {
class Database {
 public:
  Database();

  bool TryUpdateFileToDatabase(const std::string& article_url,
                               const std::string& content,
                               const MDParser& parser);
  struct ArticleHeaderInfo {
    std::string current_content_sha256;
    std::string creation_date;
    std::string is_published;
    std::string is_deleted;
  };

  struct ArticleContent {
    std::string content_or_diff;
    bool is_diff;
  };

 private:
  std::unique_ptr<pqxx::connection> conn_;

  // url to sha256 hash.
  std::unordered_map<std::string, ArticleHeaderInfo> recent_articles_;

  std::vector<ArticleContent> RetrievePrevContents(
      const string& article_url);
};
}  // namespace md_parser
