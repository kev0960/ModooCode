#include "parser.h"
#include <experimental/optional>
#include <utility>
#include <algorithm>
#include "content_header.h"
#include "content_list.h"
#include "parser_environment.h"
#include "util.h"

using std::string;
using std::experimental::optional;

namespace md_parser {
namespace {

void RemoveNewLineAtEnd(string* s) {
  if (!s->empty() && s->back() == '\n') s->erase(s->end() - 1);
}

bool IsHeaderStartOrEnd(const string& s) {
  return std::all_of(s.begin(), s.end(), [](const char c) {
    return c == '-';
  });
}

}  // namespace

const static char kWhiteLists[] = " \t";

MDParser::MDParser(std::string content)
    : content_(content), newline_started_(true), in_code_(false) {}

TokenTypes MDParser::GetTokenInfo(const string& token) {
  if (token.empty()) return NEWLINE;

  // Check Header.
  if (token[0] == '#') {
    size_t num_sharps = 0;
    for (; num_sharps < token.length(); num_sharps++) {
      if (token[num_sharps] != '#') {
        // Header should be separate sequence of #s.
        return TEXT;
      }
    }
    switch (num_sharps) {
      case 1:
        return HEADER1;
      case 2:
        return HEADER2;
      case 3:
        return HEADER3;
      default:
        return HEADER4;
    }
  }
  if (token.length() == 1) {
    if (token[0] == '*') {
      return LIST_UNORDER;
    } else if (token[0] == '>') {
      return QUOTE;
    }
  }
  if (token.length() == 3) {
    if (token == "---")
      return HORIZONTAL_LINE;
    else if (token == "```")
      return CODE;
  }
  if (token[token.length() - 1] == '.') {
    size_t num_digits = 0;
    for (size_t i = 0; i < token.length() - 1; i++) {
      if ('0' <= token[i] && token[i] <= '9') {
        num_digits++;
      } else {
        break;
      }
    }
    if (num_digits > 0 && num_digits == token.length() - 1) {
      return LIST_ENUM;
    }
    return TEXT;
  }
  if (token.length() >= 3 && token.find("```") == 0) {
    return CODE;
  }

  // TEXT does not mean it is not used as a keyword.
  return TEXT;
}

// Analyze the line. It may change the parser state.
void MDParser::AnalyzeLine(const std::string& line,
                           std::pair<int, int> space_and_tab) {
  auto first_white_space = FindFirstOfAny(line, kWhiteLists);

  // Fetch the first token.
  const string first_token = std::string(line.begin(), first_white_space);
  auto first_token_info = GetTokenInfo(first_token);
  const string line_except_first_token = line.substr(first_token.size());
  if (first_token_info == CODE) {
    if (in_code_) {
      in_code_ = false;
      newline_started_ = true;
      parser_env_.AppendToLastContent(StrCat("\n", line));
    } else {
      in_code_ = true;
      // For codes, we have to respect the line break. Think it as a verbatim
      // environment.
      parser_env_.AddNewContent(new Content(line));
    }
    return;
  } else if (in_code_) {
    if (!parser_env_.AppendToLastContent(StrCat("\n", line))) {
      LOG << "(ERROR) Code parinsg error!";
    }
  } else if (first_token_info == NEWLINE) {
    newline_started_ = true;
  } else if (first_token_info == TEXT) {
    // Then we have to continue whatever has done previously.
    if (newline_started_) {
      parser_env_.AddNewContent(new Content(line));
      newline_started_ = false;
    } else {
      // Otherwise add curent content to the previous content list.
      if (!parser_env_.AppendToLastContent(line)) {
        LOG << "(ERROR) Content list is empty :(";
        return;
      }
    }
  } else {
    newline_started_ = false;
    switch (first_token_info) {
      case HEADER1:
      case HEADER2:
      case HEADER3:
      case HEADER4:
      case HEADER5:
      case HEADER6:
        parser_env_.AddNewContent(
            new HeaderContent(line_except_first_token, first_token_info));
        break;
      case LIST_ENUM: {
        parser_env_.AddNextList(LIST_ENUM, space_and_tab);
        auto depth_and_enum = parser_env_.GetCurrentEnum(LIST_ENUM);
        parser_env_.AddNewContent(
            new EnumListContent(line_except_first_token, depth_and_enum.first));
        break;
      }
      case LIST_UNORDER: {
        parser_env_.AddNextList(LIST_UNORDER, space_and_tab);
        auto depth_and_enum = parser_env_.GetCurrentEnum(LIST_UNORDER);
        parser_env_.AddNewContent(new UnorderedListContent(
            line_except_first_token, depth_and_enum.first));
        break;
      }
      default:
        break;
    }
  }
}

void MDParser::Parser() {
  size_t start_pos = ParseHeaderContent();
  size_t end_of_line = ReadUntilEndOfLine(content_, start_pos);
  while (end_of_line <= content_.size()) {
    string line = content_.substr(start_pos, end_of_line - start_pos);
    auto trimmed = TrimLeft(&line);
    RemoveNewLineAtEnd(&line);
    AnalyzeLine(line, trimmed);
    start_pos = end_of_line + 1;
    end_of_line = ReadUntilEndOfLine(content_, start_pos);
  }
}

const std::vector<std::unique_ptr<Content>>& MDParser::GetContentList() const {
  return parser_env_.GetContentList();
}

string MDParser::ConvertToHtml() {
  string output_html;
  do {
    output_html += parser_env_.ParseCurrentContent();
  } while (parser_env_.AdvanceToNextContent());
  return output_html;
}

// The header content is defined as follows.
// -------------------- (Arbitrary length of - s; Should be more than 3)
// title    : <Title of the content>
// date     : <Published date; current date if omitted>
// category : <Path to serve the content>
// <key>    : <value>
// --------------------
size_t MDParser::ParseHeaderContent() {
  size_t start_pos = 0;
  size_t end_of_line = ReadUntilEndOfLine(content_, start_pos);
  bool header_started = false;
  while (end_of_line <= content_.size()) {
    string line = content_.substr(start_pos, end_of_line - start_pos);
    TrimLeft(&line);
    RemoveNewLineAtEnd(&line);
    if (!header_started) {
      if (!IsHeaderStartOrEnd(line)) {
        return 0;
      }
      header_started = true;
    } else {
      if (IsHeaderStartOrEnd(line)) {
        return end_of_line + 1;
      }
      // Then it must be () : () format.
      auto sep = FindFirstOfAny(line, ":");
      string key = string(line.cbegin(), sep);
      string value = string(sep + 1, line.cend());

      // Any spaces around : will be removed.
      TrimLeft(&value);
      TrimRight(&key);
      header_[key] = value;
    }
    start_pos = end_of_line + 1;
    end_of_line = ReadUntilEndOfLine(content_, start_pos);
  }
  return end_of_line;
}

}  // namespace md_parser
