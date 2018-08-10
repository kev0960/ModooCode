#include "parser.h"

#include <experimental/optional>
#include <utility>
#include "util.h"

using std::string;
using std::experimental::optional;

namespace md_parser {
namespace {}  // namespace

const static char kWhiteLists[] = " \t";

MDParser::MDParser(std::string content) : content_(content) {}

TokenTypes MDParser::GetTokenInfo(const string& token) {
  // Check Header.
  if (token[0] == '#') {
    size_t num_sharps = 0;
    for (; num_sharps < token.length(); num_sharps++) {
      if (token[num_sharps] != '#') {
        // Header should be separate sequence of #s.
        return TokenTypes::TEXT;
      }
    }
    switch (num_sharps) {
      case 1:
        return TokenTypes::HEADER1;
      case 2:
        return TokenTypes::HEADER2;
      case 3:
        return TokenTypes::HEADER3;
      default:
        return TokenTypes::HEADER4;
    }
  } else if (token.length() == 1) {
    if (token[0] == '*') {
      return LIST_UNORDER;
    } else if (token[0] == '>') {
      return QUOTE;
    }
  } else if (token.length() == 3) {
    if (token == "---")
      return HORIZONTAL_LINE;
    else if (token == "```")
      return CODE;
  } else if (token[token.length() - 1] == '.') {
    size_t num_digits = 0;
    for (size_t i = 0; i < token.length() - 1; i++) {
      if ('0' <= token[i] && token[i] <= '9') {
        num_digits++;
      } else
        break;
    }
    if (num_digits > 0 && num_digits == token.length() - 1) {
      return LIST_ENUM;
    }
    return TEXT;
  }

  // TEXT does not mean it is not used as a keyword.
  return TEXT;
}

// Analyze the line. It may change the parser state.
void MDParser::AnalyzeLine(const std::string& line,
                           std::pair<int, int> space_and_tab) {
  auto first_white_space = FindFirstOfAny(line, kWhiteLists);

  // There is no whitespace in the line.
  if (first_white_space == line.end()) {
    return;
  }

  // Fetch the first token.
  const string first_token = std::string(line.begin(), first_white_space);
  auto first_token_info = GetTokenInfo(first_token);

  switch (first_token_info) {
    case TEXT:
      break;
    case HEADER1:
    case HEADER2:
    case HEADER3:
    case HEADER4:
      content_list.emplace_back(
          new HeaderContent(first_token, first_token_info));
      break;
  }
}

void MDParser::Parser() {
  size_t start_pos = 0;
  optional<size_t> end_of_line = ReadUntilEndOfLine(content_, start_pos);
  while (end_of_line) {
    string line = content_.substr(start_pos, end_of_line.value() - start_pos);
    auto trimmed = TrimLeft(&line);
    AnalyzeLine(line, trimmed);
    start_pos = end_of_line.value() + 1;
    end_of_line = ReadUntilEndOfLine(content_, start_pos);
  }
}
}  // namespace md_parser
