#include "content.h"
#include <functional>
#include <limits>
#include <memory>
#include <cstdlib>
#include "chroma.h"
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

std::unique_ptr<char[]> cstring_from_string(const string& s) {
  std::unique_ptr<char[]> c_str{new char[s.size() + 1]};
  for (size_t i = 0; i < s.size(); i++) {
    c_str[i] = s.at(i);
  }
  c_str[s.size()] = '\0';
  return c_str;
}

string GetHtmlFragmentText(const string& content, const HtmlFragments& fragment,
                           bool is_str = true) {
  if (is_str) {
    return content.substr(fragment.str_start,
                          fragment.str_end - fragment.str_start + 1);
  }
  return content.substr(fragment.link_start,
                        fragment.link_end - fragment.link_start + 1);
}

string FormatCodeUsingChroma(const string& code, const string& lang,
                             const string& schema) {
  auto code_ = cstring_from_string(code);
  auto lang_ = cstring_from_string(lang);
  auto schema_ = cstring_from_string(schema);

  char* formatted =
      FormatCodeWithoutInlineCss(code_.get(), lang_.get(), schema_.get());
  string formatted_code = formatted;
  free (formatted);

  return formatted_code;
}

}  // namespace

Content::Content(const string& content) : content_(content) { return; }

void Content::AddContent(const string& s) { content_ += s; }

string Content::OutputHtml() {
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

  std::vector<std::function<size_t(Content*, const size_t,
                                   std::vector<HtmlFragments>*, int*)>>
      handlers = {&Content::HandleLinks, &Content::HandleImages,
                  &Content::HandleCodes};
  // Any unescaped * or _ are considered as a format token.
  for (size_t i = 0; i < content_.size(); i++) {
    bool handled = false;
    for (const auto& handler : handlers) {
      size_t result = handler(this, i, &fragments, &text_start);
      if (result != i) {
        i = result;
        handled = true;
        break;
      }
    }
    if (handled) continue;

    // Handles Bold, Italic, Strikethroughs here.
    int matches = Max(FindOneOrTwoConsecutiveChar(content_, i, '*'),
                      FindOneOrTwoConsecutiveChar(content_, i, '_'),
                      FindOneOrTwoConsecutiveChar(content_, i, '~'));
    if (matches == 0) {
      if (text_start == -1) {
        text_start = i;
      }
    } else {
      // Since tilde (~) is ignored.
      if (matches == 1 && content_[i] == '~') continue;
      // Mark the end of the text segment.
      if (text_start != -1) {
        fragments.push_back(
            HtmlFragments(HtmlFragments::Types::TEXT, text_start, i - 1));
        text_start = -1;
      }
      if (matches == 2) {
        // If italic * is defined later than the defined italic, then we only
        // read one *.
        if (bold_start < italic_start && italic_start != int_max) {
          italic_start = int_max;
          fragments.push_back(HtmlFragments(HtmlFragments::Types::ITALIC));
        } else {
          bold_start = (bold_start == int_max ? i : int_max);
          fragments.push_back(HtmlFragments(HtmlFragments::Types::BOLD));
          i++;
        }
      } else if (matches == 1) {
        italic_start = (italic_start == int_max ? i : int_max);
        if (text_start != -1) {
          fragments.push_back(
              HtmlFragments(HtmlFragments::Types::TEXT, text_start, i - 1));
          text_start = -1;
        }
        fragments.push_back(HtmlFragments(HtmlFragments::Types::ITALIC));
      }
    }
  }
  if (text_start != -1) {
    fragments.push_back(HtmlFragments(HtmlFragments::Types::TEXT, text_start,
                                      content_.size() - 1));
  }

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
        html += "<span class='font-italic'>";
      else
        html += "</span>";
      italic = !italic;
    } else if (fragments[i].type == HtmlFragments::Types::LINK) {
      html += StrCat("<a href='",
                     GetHtmlFragmentText(content_, fragments[i], false), "'>",
                     GetHtmlFragmentText(content_, fragments[i]), "</a>");
    } else if (fragments[i].type == HtmlFragments::Types::IMAGE) {
      html += StrCat(
          "<img src='", GetHtmlFragmentText(content_, fragments[i], false),
          "' alt='", GetHtmlFragmentText(content_, fragments[i]), "'>");
    } else if (fragments[i].type == HtmlFragments::Types::CODE) {
      html += FormatCodeUsingChroma(GetHtmlFragmentText(content_, fragments[i]),
                                    "cpp", "github");
    } else {
      html += GetHtmlFragmentText(content_, fragments[i]);
    }
  }
  return html;
}

size_t Content::HandleLinks(const size_t start_pos,
                            std::vector<HtmlFragments>* fragments,
                            int* text_start) {
  if (content_[start_pos] != '[') {
    return start_pos;
  }

  // Search for the ending ']'.
  size_t end_bracket = content_.find(']', start_pos);
  if (end_bracket == string::npos) return start_pos;

  if (end_bracket + 1 >= content_.size() || content_[end_bracket + 1] != '(') {
    return start_pos;
  }
  size_t link_start = end_bracket + 1;
  size_t link_end = content_.find(')', link_start);
  if (link_end == string::npos) return start_pos;

  if (*text_start != -1) {
    fragments->push_back(
        HtmlFragments(HtmlFragments::Types::TEXT, *text_start, start_pos - 1));
    *text_start = -1;
  }
  fragments->push_back(HtmlFragments(HtmlFragments::Types::LINK, start_pos + 1,
                                     end_bracket - 1, link_start + 1,
                                     link_end - 1));
  return link_end;
}

size_t Content::HandleImages(const size_t start_pos,
                             std::vector<HtmlFragments>* fragments,
                             int* text_start) {
  if (content_[start_pos] != '!' || start_pos == content_.size() - 1)
    return start_pos;
  // Images are in exact same format as the links except for the starting !
  // symbol.
  size_t res = HandleLinks(start_pos + 1, fragments, text_start);
  if (res == start_pos + 1) return start_pos;

  // Need to change LINK to IMAGE.
  fragments->back().type = HtmlFragments::Types::IMAGE;
  return res;
}

size_t Content::HandleCodes(const size_t start_pos,
                            std::vector<HtmlFragments>* fragments,
                            int* text_start) {
  if (start_pos + 2 >= content_.size() ||
      content_.substr(start_pos, 3) != "```") {
    return start_pos;
  }
  size_t code_start = start_pos + 3;
  size_t code_end;
  if ((code_end = content_.find("```", code_start)) == string::npos) {
    return start_pos;
  }

  code_end--;
  if (*text_start != -1) {
    fragments->push_back(
        HtmlFragments(HtmlFragments::Types::TEXT, *text_start, start_pos - 1));
    *text_start = -1;
  }
  fragments->push_back(
      HtmlFragments(HtmlFragments::Types::CODE, code_start, code_end));
  return code_end + 3;
}

string Content::OutputHtml(ParserEnvironment*) {
  return OutputHtml();
}

}  // namespace md_parser
