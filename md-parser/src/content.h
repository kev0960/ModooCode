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

// Class for the regular Text content.
class Content {
 protected:
  string content_;

 public:
  Content(const string& content);
  virtual string OutputHtml();

  // Continuation of the content.
  virtual void AddContent(const string& content) = 0;
  virtual ~Content(){};
};

class HeaderContent : public Content {
  int header_cnt_;

 public:
  // Content does not include the ###s.
  HeaderContent(const string& content, TokenTypes header_type);
  string OutputHtml() override;
  void AddContent(const string& content) override;
};

class EnumListContent : public Content {
  int enum_cnt_;
  int enum_depth_;

 public:
  EnumListContent(const string& content, int enum_cnt, int enum_depth);
  string OutputHtml() override;
  void AddContent(const string& content) override;
};
}
