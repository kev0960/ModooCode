#include "util.h"

#include <algorithm>

using std::experimental::optional;
using std::string;

namespace md_parser {

// Find the End of line and return it.
optional<size_t> ReadUntilEndOfLine(const string& content, size_t start) {
  size_t eol = content.find('\n', start);
  if (eol == string::npos) {
    return std::experimental::nullopt;
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

string::const_iterator FindFirstOfAny(const string& str,
                                      const string& matching_chars) {
  for (auto itr = str.begin(); itr != str.end(); itr++) {
    if (std::any_of(matching_chars.begin(), matching_chars.end(),
                    [&](const char c) { return c == *itr; })) {
      return itr;
    }
  }
  return str.end();
}

}
