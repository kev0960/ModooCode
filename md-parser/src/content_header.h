#pragma once
#include <string>
#include "content.h"

using std::string;

namespace md_parser {

class HeaderContent : public Content {
  int header_cnt_;

 public:
  // Content does not include the ###s.
  HeaderContent(const string& content, TokenTypes header_type);
  string OutputHtml() override;
  void AddContent(const string& content) override;
};

}  // namespace md_parser
