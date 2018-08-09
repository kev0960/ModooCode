#pragma once
#include <string>
using std::string;

namespace md_parser {

enum TokenTypes {
  TEXT,
  LIST_ENUM,
  LIST_UNORDER,
  HEADER1,
  HEADER2,
  HEADER3,
  HEADER4,
  QUOTE,
  HORIZONTAL_LINE,
  CODE
};
class Content {
 protected:
  string content_;

 public:
  Content(const string& content);
  virtual string OutputHtml() = 0;
};

class HeaderContent : public Content {
 public:
  HeaderContent(const string& content, TokenTypes header_type);
  string OutputHtml() override;
};
}
