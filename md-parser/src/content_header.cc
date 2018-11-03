#include "content_header.h"

#include <algorithm>
#include <limits>
#include <unordered_set>
#include <vector>

#include "util.h"

namespace md_parser {
namespace {
void StripMarkdown(string* html) {
  html->erase(std::remove_if(html->begin(), html->end(),
                             [](char c) { return c == '`'; }),
              html->end());
}

void EscapeHtmlString(string* s) {
  for (size_t i = 0; i < s->length(); i++) {
    if (s->at(i) == '<') {
      s->replace(i, 1, "&lt;");
    } else if (s->at(i) == '>') {
      s->replace(i, 1, "&gt;");
    }
  }
}

HeaderType GetHeaderType(const string& header_token) {
  if (std::all_of(header_token.begin(), header_token.end(),
                  [](const char c) { return c == '#'; })) {
    return NORMAL_HEADER;
  } else if (header_token == "#@") {
    return FANCY_HEADER_FOR_REF;
  } else if (header_token == "###@") {
    return LECTURE_HEADER;
  }
  return NORMAL_HEADER;
}

}  // namespace

HeaderContent::HeaderContent(const string& content, const string& header_token,
                             int header_index)
    : Content(content),
      header_token_(header_token),
      header_index_(header_index) {}

string HeaderContent::OutputHtml(ParserEnvironment* parser_env) {
  auto output_html = Content::OutputHtml(parser_env);
  if (output_html.empty()) {
    return "";
  }
  string start_header, end_header;
  auto header_type = GetHeaderType(header_token_);
  if (header_type == NORMAL_HEADER) {
    start_header =
        StrCat("<h", std::to_string(header_token_.size()), " id='page-heading-",
               std::to_string(header_index_), "'>");
    end_header = StrCat("</h", std::to_string(header_token_.size()), ">");
  } else if (header_type == FANCY_HEADER_FOR_REF) {
    start_header = StrCat(R"(<h2 class="ref-header" )", "id='page-heading-",
                          std::to_string(header_index_), "'>");
    end_header = R"(</h2>)";
  } else if (header_type == LECTURE_HEADER) {
    start_header = StrCat(R"(<h3 class="lecture-header" )", "id='page-heading-",
                          std::to_string(header_index_), "'>");
    end_header = R"(</h3>)";
    return StrCat(start_header, Content::OutputHtml(parser_env), end_header);
  }
  StripMarkdown(&content_);
  EscapeHtmlString(&content_);
  return StrCat(start_header, content_, end_header);
}

void HeaderContent::AddContent(const string& content) { content_ += content; }

}  // namespace md_parser
