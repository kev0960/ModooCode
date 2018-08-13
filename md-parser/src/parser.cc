#include "parser.h"
#include "content_header.h"
#include "content_list.h"

#include <experimental/optional>
#include <utility>
#include "util.h"

using std::string;
using std::experimental::optional;

namespace md_parser {
namespace {

int IndentSize(std::pair<int, int> space_and_tab) {
  return space_and_tab.first + 2 * space_and_tab.second;
}

void RemoveNewLineAtEnd(string* s) {
  if (!s->empty() && s->back() == '\n') s->erase(s->end() - 1);
}

}  // namespace

const static char kWhiteLists[] = " \t";

EnumListManager::EnumListManager() {}

void EnumListManager::AddNextList(std::pair<int, int> space_and_tab) {
  int indent_size = IndentSize(space_and_tab);

  // 2 spaces ==> One indent.
  int depth = indent_size / spaces_per_indent;

  while (!state_.empty()) {
    auto& depth_and_enum = state_.top();
    if (depth_and_enum.first == depth) {
      depth_and_enum.second += 1;
      return;
    } else if (depth_and_enum.first > depth) {
      state_.push(std::make_pair(depth, 0));
    }

    state_.pop();
  }
  state_.push(std::make_pair(depth, 0));
}

std::pair<int, int> EnumListManager::GetCurrentEnum() const {
  return state_.top();
}

MDParser::MDParser(std::string content)
    : content_(content), newline_started_(true) {}

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

  // Fetch the first token.
  const string first_token = std::string(line.begin(), first_white_space);
  auto first_token_info = GetTokenInfo(first_token);
  const string line_except_first_token = line.substr(first_token.size());

  if (first_token_info == NEWLINE) {
    newline_started_ = true;
  } else if (first_token_info == TEXT) {
    // Then we have to continue whatever has done previously.
    if (newline_started_) {
      content_list_.emplace_back(new Content(line));
      newline_started_ = false;
    } else {
      // Otherwise add curent content to the previous content list.
      if (content_list_.empty()) {
        LOG << "(ERROR) Content list is empty :(";
        return;
      }
      content_list_.back()->AddContent(line);
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
        content_list_.emplace_back(
            new HeaderContent(line_except_first_token, first_token_info));
        break;
      case LIST_ENUM: {
        enum_list_manager_.AddNextList(space_and_tab);
        auto depth_and_enum = enum_list_manager_.GetCurrentEnum();
        content_list_.emplace_back(new EnumListContent(line_except_first_token,
                                                       depth_and_enum.second,
                                                       depth_and_enum.first));
        break;
      }
      case LIST_UNORDER: {
        unordered_list_manager_.AddNextList(space_and_tab);
        auto depth_and_enum = unordered_list_manager_.GetCurrentEnum();
        content_list_.emplace_back(new UnorderedListContent(
            line_except_first_token, depth_and_enum.first));
        break;
      }
      default:
        break;
    }
  }
}

void MDParser::Parser() {
  size_t start_pos = 0;
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
  return content_list_;
}
}  // namespace md_parser
