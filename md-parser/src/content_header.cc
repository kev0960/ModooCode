#include "content_header.h"
#include <limits>
#include <vector>
#include "util.h"

namespace md_parser {

HeaderContent::HeaderContent(const string& content, TokenTypes token_type)
    : Content(content) {
  // Header type to the actual number of #s
  header_cnt_ = 6;
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
    case TokenTypes::HEADER4:
      header_cnt_ = 4;
      break;
    case TokenTypes::HEADER5:
      header_cnt_ = 5;
      break;
    case TokenTypes::HEADER6:
      header_cnt_ = 6;
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

}  // namespace md_parser
