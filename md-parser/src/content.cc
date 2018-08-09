#include "content.h"
#include <limits>
#include <vector>
#include "util.h"

namespace md_parser {

namespace {
// Return how many matches.
int FindOneOrTwoConsecutiveChar(const string& s, size_t start, char c) {
  if (s[start] == c) {
    if (start + 1 < s.size() && s[start + 1] == c) {
      return 2;
    }
    return 1;
  }
  return 0;
}
}

Content::Content(const string& content) : content_(content) { return; }

string Content::OutputHtml() {
  struct HtmlFragments {
    enum Types { BOLD, ITALIC, TEXT } type;

    // Start and end are inclusive.
    int str_start;
    int str_end;

    HtmlFragments(Types t) : type(t) {}
    HtmlFragments(Types t, int start, int end)
        : type(t), str_start(start), str_end(end) {}
  };

  // When both not defined :
  //  Neither of bold_start < italic_start nor bold_start > italic_start
  // When only one of them are defined :
  //  (defined one) < (not defined one)
  // When both are defined :
  //  (earlier one) < (later one)
  const int int_max = std::numeric_limits<int>::max();
  int bold_start = int_max;
  int italic_start = int_max;
  int text_start = -1;

  std::vector<HtmlFragments> fragments;

  // Any unescaped * or _ are considered as a format token.
  for (size_t i = 0; i < content_.size(); i++) {
    int matches = std::max(FindOneOrTwoConsecutiveChar(content_, i, '*'),
                           FindOneOrTwoConsecutiveChar(content_, i, '_'));
    if (matches == 2) {
      // If italic * is defined later than the defined italic, then we only read
      // one *.
      if (bold_start < italic_start && italic_start != int_max) {
        matches = 1;
        italic_start = int_max;
        fragments.push_back(
            HtmlFragments(HtmlFragments::Types::TEXT, text_start, i - 1));
        fragments.push_back(HtmlFragments(HtmlFragments::Types::ITALIC));
      } else {
        bold_start = (bold_start == int_max ? i : int_max);
        fragments.push_back(
            HtmlFragments(HtmlFragments::Types::TEXT, text_start, i - 1));
        fragments.push_back(HtmlFragments(HtmlFragments::Types::BOLD));
      }
      text_start = -1;
    } else if (matches == 1) {
      italic_start = (italic_start == int_max ? i : int_max);
      fragments.push_back(
          HtmlFragments(HtmlFragments::Types::TEXT, text_start, i - 1));
      fragments.push_back(HtmlFragments(HtmlFragments::Types::ITALIC));
      text_start = -1;
    } else {
      if (text_start == -1) {
        text_start = i;
      }
    }
  }
  fragments.push_back(HtmlFragments(HtmlFragments::Types::TEXT, text_start,
                                    content_.size() - 1));

  // Now we have to generate formatted html.
  bool bold = false;
  bool italic = false;
  string html;
  for (size_t i = 0; i < fragments.size(); i++) {
    if (fragments[i].type == HtmlFragments::Types::BOLD) {
      if (!bold)
        html += "<span class='font-weight-bold'>";
      else
        html += "</span>";
      bold = !bold;
    } else if (fragments[i].type == HtmlFragments::Types::ITALIC) {
      if (!italic)
        html += "<span class='font-weight-italic'>";
      else
        html += "</span>";
      italic = !italic;
    } else {
      html +=
          content_.substr(fragments[i].str_start,
                          fragments[i].str_end - fragments[i].str_start + 1);
    }
  }
  return html;
}

HeaderContent::HeaderContent(const string& content, TokenTypes token_type)
    : Content(content) {
  // Header type to the actual number of #s
  header_cnt_ = 4;
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
    default:
      break;
  }
}

string HeaderContent::OutputHtml() {
  const string start_header = StrCat("<h", std::to_string(header_cnt_), ">");
  const string end_header = StrCat("</h", std::to_string(header_cnt_), ">");

  return StrCat(start_header, Content::OutputHtml(), end_header);
}

void HeaderContent::AddContent(const string& content) { content_ += content; }

EnumListContent::EnumListContent(const string& content, int enum_cnt,
                                 int enum_depth)
    : Content(content), enum_cnt_(enum_cnt), enum_depth_(enum_depth) {}

string EnumListContent::OutputHtml() {
  return StrCat("<li>", Content::OutputHtml(), "</li>");
};
}
