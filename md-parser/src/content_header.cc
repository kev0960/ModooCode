#include "content_header.h"

#include <algorithm>
#include <limits>
#include <unordered_set>
#include <vector>

#include "util.h"

#define CONTINUE_IF_NOT_FOUND(s) \
  if (s == string::npos) {       \
    continue;                    \
  }

namespace md_parser {
namespace {
void StripTags(string* html) {
  std::unordered_set<string> disallowed_tags = {"code", "p", "span"};
  string stripped_string = "";
  for (size_t i = 0; i < html->size(); i++) {
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

HeaderType GetHeaderType(const string& header_token) {
  if (std::all_of(header_token.begin(), header_token.end(),
                  [](const char c) { return c == '#'; })) {
    return NORMAL_HEADER;
  } else if (header_token == "#@") {
    return FANCY_HEADER_FOR_REF;
  }
  return NORMAL_HEADER;
}

}  // namespace

HeaderContent::HeaderContent(const string& content, const string& header_token)
    : Content(content), header_token_(header_token) {}

string HeaderContent::OutputHtml() {
  auto output_html = Content::OutputHtml();
  if (output_html.empty()) {
    return "";
  }
  string start_header, end_header;
  auto header_type = GetHeaderType(header_token_);
  if (header_type == NORMAL_HEADER) {
    start_header = StrCat("<h", std::to_string(header_token_.size()), ">");
    end_header = StrCat("</h", std::to_string(header_token_.size()), ">");
  } else if (header_type == FANCY_HEADER_FOR_REF) {
    start_header = R"(<h2 class="ref-header">)";
    end_header = R"(</h2>)";
  }
  string inner_html = Content::OutputHtml();
  // Remove not allowed tags in html.
  StripTags(&inner_html);
  return StrCat(start_header, inner_html, end_header);
}

void HeaderContent::AddContent(const string& content) { content_ += content; }

}  // namespace md_parser
