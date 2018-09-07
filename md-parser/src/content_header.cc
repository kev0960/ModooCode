#include "content_header.h"

#include <limits>
#include <vector>
#include <unordered_set>

#include "util.h"

#define CONTINUE_IF_NOT_FOUND(s) \
    if (s == string::npos) { \
      continue; \
    }

namespace md_parser {
namespace {
  void StripTags(string* html) {
    std::unordered_set<string> disallowed_tags = {"code", "p", "span"};
    string stripped_string = "";
    for (size_t i = 0; i < html->size(); i ++) {
      if (html->at(i) == '<') {
        auto tag_name_end = html->find_first_of(" >", i + 1);
        CONTINUE_IF_NOT_FOUND(tag_name_end);

        auto opening_tag_close_bracket = html->find(">", tag_name_end);
        CONTINUE_IF_NOT_FOUND(opening_tag_close_bracket);
        const string tag_name = html->substr(i + 1, tag_name_end - (i + 1));
        // If found tag is not allowed, then only take the inner html text.
        if (disallowed_tags.find(tag_name) != disallowed_tags.end()) {
          // Find the ending tag.
          const string end_tag = StrCat("</", tag_name, ">");
          auto closing_tag_start = html->find(end_tag, tag_name_end);
          CONTINUE_IF_NOT_FOUND(closing_tag_start);
          // We have to remove i ~ opening_tag_close_bracket
          // and end_tag ~ end_tag + end_tag.length(). Note that we have to
          // remove the end tag first (to preserve the index).
          html->erase(closing_tag_start, end_tag.length());
          html->erase(i, opening_tag_close_bracket - i + 1);
          if (i != 0) {
            i--;
          }
        }
      }
    }
  }
}

HeaderContent::HeaderContent(const string& content, TokenTypes token_type)
    : Content(content) {
  // Header type to the actual number of #s
  header_cnt_ = 6;
  switch (token_type) {
    case TokenTypes::HEADER1:
      header_cnt_ = 1;
      break;
    case TokenTypes::HEADER2:
      header_cnt_ = 2;
      break;
    case TokenTypes::HEADER3:
      header_cnt_ = 3;
      break;
    case TokenTypes::HEADER4:
      header_cnt_ = 4;
      break;
    case TokenTypes::HEADER5:
      header_cnt_ = 5;
      break;
    case TokenTypes::HEADER6:
      header_cnt_ = 6;
      break;
    default:
      break;
  }
}

string HeaderContent::OutputHtml() {
  auto output_html = Content::OutputHtml();
  if (output_html.empty()) {
    return "";
  }
  const string start_header = StrCat("<h", std::to_string(header_cnt_), ">");
  const string end_header = StrCat("</h", std::to_string(header_cnt_), ">");
  string inner_html = Content::OutputHtml();
  // Remove not allowed tags in html.
  StripTags(&inner_html);
  return StrCat(start_header, inner_html, end_header);
}

void HeaderContent::AddContent(const string& content) { content_ += content; }

}  // namespace md_parser
