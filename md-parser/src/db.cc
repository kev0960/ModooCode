#include "db.h"

#include <algorithm>
#include <fstream>
#include <unordered_map>

#include "diff.h"
#include "hash.h"
#include "util.h"

namespace md_parser {
namespace {
std::unordered_map<string, string> GetEnvVariable() {
  std::ifstream read_file("../.env");
  string content;

  read_file.seekg(0, std::ios::end);
  content.reserve(read_file.tellg());
  read_file.seekg(0, std::ios::beg);

  content.assign((std::istreambuf_iterator<char>(read_file)),
                 std::istreambuf_iterator<char>());

  // Now parse the .env file.
  std::unordered_map<string, string> env_vars;
  std::vector<string> content_lines = Split(content, '\n');
  for (const string& line : content_lines) {
    std::vector<string> env = Split(line, '=');
    if (env.size() < 2) {
      break;
    }
    env_vars[env[0]] = env[1];
  }
  return env_vars;
}

bool CheckMatch(const Database::ArticleHeaderInfo& prev_article,
                const MDParser& parser) {
  const auto& current_header = parser.GetHeaderInfo();
  auto itr = current_header.find("is_published");
  if (itr == current_header.end()) {
    // Default for "is_published" is true.
    if (prev_article.is_published == string("false")) {
      return false;
    }
  } else {
    if (itr->second != prev_article.is_published) {
      return false;
    }
  }

  itr = current_header.find("is_deleted");
  if (itr == current_header.end()) {
    // Default for "is_deleted" is false.
    if (prev_article.is_deleted == string("true")) {
      return false;
    }
  } else {
    if (itr->second != prev_article.is_deleted) {
      return false;
    }
  }
  return true;
}

string PostgresBoolToString(const string& s) {
  if (s == "t") {
    return "true";
  } else if (s == "f") {
    return "false";
  }
  LOG << "Something is wrong " << s;
  return "false";
}

string FindOrReturnEmpty(const std::map<string, string>& m, const string& key) {
  const auto& itr = m.find(key);
  if (itr == m.end()) {
    return "";
  }
  return itr->second;
}

string DefaultDateWhenEmpty(const string& s) {
  if (s.empty()) {
    return "now()";
  } else {
    return s;
  }
}

string DefaultBooleanWhenEmpty(const string& s, bool default_bool) {
  if (s.empty()) {
    if (default_bool) {
      return "true";
    } else {
      return "false";
    }
  } else {
    return s;
  }
}

std::optional<int> UnescapePostgresString(const std::string_view& s,
                                          int start) {
  if (s[start] != '"') {
    return start;
  }
  bool even_dq = true;
  int len = s.length();
  for (int i = start; i < len; i++) {
    if (s[i] == '"') {
      even_dq = !even_dq;
    }
    if (even_dq) {
      if (i + 1 >= len || s[i + 1] == ',') {
        return i;
      }
    }
  }
  return std::nullopt;
}

// Assumes form of ".."
string RemoveDoubleQuoteAndBackslash(const std::string_view& s) {
  int len = s.length() - 1;
  string str;
  str.reserve(len);

  for (int i = 1; i < len; i++) {
    if (s[i] == '"' || s[i] == '\\') {
      if (i + 1 >= len || s[i + 1] != s[i]) {
        LOG << "Something is wrong : " << s;
      } else {
        str.push_back(s[i]);
        i += 1;
      }
    } else {
      str.push_back(s[i]);
    }
  }
  return str;
}

Database::ArticleContent ParsePostgresArticleContent(std::string_view s) {
  // Only " are escaped as "".
  // (" .... ", t/f)

  // Get the
  s.remove_prefix(1);
  s.remove_suffix(1);

  std::vector<string> parsed_strs;
  int start = 0;
  while (start < static_cast<int>(s.length())) {
    auto end_or_not = UnescapePostgresString(s, start);
    if (!end_or_not) {
      LOG << "Something is wrong!" << s;
      return {};
    }
    parsed_strs.emplace_back(s.substr(start, end_or_not.value() - start + 1));
    start = end_or_not.value() + 2;
  }
  bool is_diff = (parsed_strs[3] == "t");
  if (is_diff) {
    return {RemoveDoubleQuoteAndBackslash(parsed_strs[2]), is_diff};
  } else {
    return {RemoveDoubleQuoteAndBackslash(parsed_strs[1]), is_diff};
  }
}

string GeneratePrevArticle(std::vector<Database::ArticleContent> contents) {
  // Given the list of article_content, reconstruct the original article.
  std::vector<string> patch_strings;
  string full_content;
  for (auto itr = contents.rbegin(); itr != contents.rend(); itr++) {
    if (itr->is_diff) {
      patch_strings.push_back(itr->content_or_diff);
    } else {
      full_content = itr->content_or_diff;
      break;
    }
  }
  std::reverse(patch_strings.begin(), patch_strings.end());

  // Apply patch strings to the previsouly saved context.
  for (const auto& patch_str : patch_strings) {
    PatchFromDiff p(full_content, patch_str);
    full_content = p.GetPatchedString();
  }
  return full_content;
}

}  // namespace

Database::Database() {
  // Initiate the connection to the PSQL server.
  const auto env_vars = GetEnvVariable();
  const string pg_user = env_vars.at("PGUSER");
  const string pg_password = env_vars.at("PGPASSWORD");
  const string pg_database = env_vars.at("PGDATABASE");

  const string conn_str =
      StrCat("dbname=", pg_database, " user=", pg_user,
             " password=", pg_password, " hostaddr=127.0.0.1 port=5432");
  conn_ = std::make_unique<pqxx::connection>(conn_str);

  // Read all the hashes of current saved articles.
  pqxx::work read_recent_articles(*conn_);
  pqxx::result recent_articles = read_recent_articles.exec(
      "SELECT article_url, current_content_sha256, creation_date, "
      "is_published, is_deleted FROM Articles;");
  for (auto itr = recent_articles.begin(); itr != recent_articles.end();
       itr++) {
    recent_articles_[itr[0].as<string>()] = {
        itr[1].as<string>(), itr[2].as<string>(),
        PostgresBoolToString(itr[3].as<string>()),
        PostgresBoolToString(itr[4].as<string>())};
  }
}

// Returns true if the file is changed.
bool Database::TryUpdateFileToDatabase(const string& article_url,
                                       const string& content,
                                       const MDParser& parser) {
  // First request for the current status of the articles.
  string current_hash;
  // Now retrieve the hash of the current file.
  SHAHash sha256_hash;
  if (auto current_hash_or_not = sha256_hash.GenerateSha256Hash(content)) {
    current_hash = current_hash_or_not.value();
  }
  auto itr = recent_articles_.find(article_url);
  if (itr != recent_articles_.end()) {
    bool updated = false;
    string prev_hash = itr->second.current_content_sha256;
    if (prev_hash != current_hash) {
      // Calculate the diff.
      std::vector<Database::ArticleContent> prev_articles =
          RetrievePrevContents(article_url);
      bool should_add_full_content = false;
      if (prev_articles.size() >= 5 && !prev_articles[0].is_diff) {
        should_add_full_content = true;
      }

      // Now insert into the database.
      pqxx::work append_new_article_info(*conn_);
      string prev_article_content = GeneratePrevArticle(prev_articles);
      Diff diff(prev_article_content, content);
      string patch_str = diff.CreatePatch();

      if (should_add_full_content) {
        append_new_article_info.exec(
            StrCat("UPDATE articles SET contents = contents || "
                   "row(now(), '",
                   /* content */ append_new_article_info.esc(content), "', '",
                   /* diff */ append_new_article_info.esc(patch_str),
                   "', false)::article_content WHERE article_url = '",
                   append_new_article_info.esc(article_url), "';"));
      } else {
        // Otherwise we only add the diff.
        append_new_article_info.exec(
            StrCat("UPDATE articles SET contents = contents || "
                   "row(now(), '', '",
                   append_new_article_info.esc(patch_str),
                   "', true)::article_content WHERE article_url = '",
                   append_new_article_info.esc(article_url), "';"));
      }
      append_new_article_info.exec(
          StrCat("UPDATE articles SET current_content_sha256 = '", current_hash,
                 "' WHERE article_url = '",
                 append_new_article_info.esc(article_url), "';"));
      append_new_article_info.commit();
      updated = true;
    }
    if (!CheckMatch(itr->second, parser)) {
      pqxx::work modify_article_metadata(*conn_);
      const auto& article_header = parser.GetHeaderInfo();
      modify_article_metadata.exec(StrCat(
          "INSERT INTO articles(article_url, creation_date, is_published, "
          "is_deleted) VALUES ('",
          modify_article_metadata.esc(article_url), "', '",
          /* creation_date */
          DefaultDateWhenEmpty(
              FindOrReturnEmpty(article_header, "publish_date")),
          "', ",
          /* is_published */
          DefaultBooleanWhenEmpty(
              FindOrReturnEmpty(article_header, "is_published"), true),
          ", ",
          /* is_deleted */
          DefaultBooleanWhenEmpty(
              FindOrReturnEmpty(article_header, "is_deleted"), false),
          "');"));
      modify_article_metadata.commit();
      updated = true;
    }
    return updated;
  } else {
    // If the entry does not even exist, we should create one.
    pqxx::work create_new_article(*conn_);
    const auto& article_header = parser.GetHeaderInfo();
    create_new_article.exec(StrCat(
        "INSERT INTO articles(article_url, creation_date, is_published, "
        "is_deleted, current_content_sha256) VALUES ('",
        create_new_article.esc(article_url), "', '",
        /* creation_date */
        DefaultDateWhenEmpty(FindOrReturnEmpty(article_header, "publish_date")),
        "', ",
        /* is_published */
        DefaultBooleanWhenEmpty(
            FindOrReturnEmpty(article_header, "is_published"), true),
        ", ",
        /* is_deleted */
        DefaultBooleanWhenEmpty(FindOrReturnEmpty(article_header, "is_deleted"),
                                false),
        ", '",
        /* current_content_sha256 */ current_hash, "');"));
    create_new_article.exec(
        StrCat("UPDATE articles SET contents = contents || "
               "row(now(), '",
               create_new_article.esc(content),
               "', '', false)::article_content WHERE article_url = '",
               create_new_article.esc(article_url), "';"));
    create_new_article.commit();
  }

  return true;
}

std::vector<Database::ArticleContent> Database::RetrievePrevContents(
    const string& article_url) {
  pqxx::nontransaction read_recent_contents(*conn_);
  pqxx::result recent_articles = read_recent_contents.exec(
      StrCat("SELECT unnest(contents[array_length(contents, 1) - 4:"
             "array_length(contents, 1)]) FROM Articles WHERE article_url = '",
             read_recent_contents.esc(article_url), "';"));

  std::vector<Database::ArticleContent> recent_article_contents;
  for (auto itr = recent_articles.begin(); itr != recent_articles.end();
       itr++) {
    recent_article_contents.push_back(
        ParsePostgresArticleContent(itr[0].as<string>()));
  }
  return recent_article_contents;
}

}  // namespace md_parser
