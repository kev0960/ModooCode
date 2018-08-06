#include "parser.h"

#include <experimental/optional>
#include <utility>

using std::string;
using std::experimental::optional;
namespace md_parser {
namespace {
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
  str->erase(i);
  return std::make_pair(space_cnt, tab_cnt);
}

}  // namespace

MDParser::MDParser(std::string content) : content_(content) {}

void MDParser::Parser() {
  size_t start_pos = 0;
  optional<size_t> end_of_line;
  while (end_of_line = ReadUntilEndOfLine(content_, start_pos)) {
    string line = content_.substr(start_pos, end_of_line.value() - start_pos);
    auto trimmed = TrimLeft(&line);
    start_pos = end_of_line.value() + 1;
  }
}
}  // namespace md_parser
