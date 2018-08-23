#include "util.h"

#include <algorithm>

using std::string;
using std::experimental::optional;

namespace md_parser {

// Find the End of line and return it.
size_t ReadUntilEndOfLine(const string& content, size_t start) {
  if (start >= content.size()) return content.size() + 1;

  size_t eol = content.find('\n', start);
  if (eol == string::npos) {
    return content.size();
  }
  return eol;
}

// Remove preceding whitespace from left. Returns the number of spaces that are
// removed.
std::pair<int, int> TrimLeft(string* str) {
  int space_cnt = 0;
  int tab_cnt = 0;
  size_t i = 0;
  for (; i < str->size(); i++) {
    if (str->at(i) == ' ') {
      space_cnt++;
    } else if (str->at(i) == '\t') {
      tab_cnt++;
    } else {
      break;
    }
  }
  str->erase(0, i);
  return std::make_pair(space_cnt, tab_cnt);
}

// Remove preceding whitespace from left. Returns the number of spaces that are
// removed.
std::pair<int, int> TrimRight(string* str) {
  int space_cnt = 0;
  int tab_cnt = 0;
  int i = str->size() - 1;
  for (; i >= 0; i --) {
    if (str->at(i) == ' ') {
      space_cnt++;
    } else if (str->at(i) == '\t') {
      tab_cnt++;
    } else {
      break;
    }
  }
  str->erase(i + 1, str->size());
  return std::make_pair(space_cnt, tab_cnt);
}

void Trim(string* str) {
  TrimLeft(str);
  TrimRight(str);
}

string::const_iterator FindFirstOfAny(const string& str,
                                      const string& matching_chars) {
  return FindFirstOfAny(str, 0, matching_chars);
}

string::const_iterator FindFirstOfAny(const string& str, const size_t start_pos,
                                      const string& matching_chars) {
  for (auto itr = str.begin() + start_pos; itr != str.end(); itr++) {
    if (std::any_of(matching_chars.begin(), matching_chars.end(),
                    [&](const char c) {  return c == *itr; })) {
      return itr;
    }
  }
  return str.end();
}

string::const_iterator FindFirstWhitespace(const string& str) {
  return FindFirstWhitespace(str, 0);
}

string::const_iterator FindFirstWhitespace(const string& str,
                                           const size_t start_pos) {
  const string matching_chars = " \t";
  for (auto itr = str.begin() + start_pos; itr != str.end(); itr++) {
    if (std::any_of(matching_chars.begin(), matching_chars.end(),
                    [&](const char c) { return c == *itr; })) {
      return itr;
    } else if (static_cast<unsigned char>(*itr) == 194) {
      if ((itr + 1) != str.end() &&
          static_cast<unsigned char>(*(itr + 1)) == 160) {
        return itr;
      }
    }
  }
  return str.end();
}

string StrCat(const string& s) { return s; }

}  // namespace md_parser
