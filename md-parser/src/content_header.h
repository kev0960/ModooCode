#pragma once
#include <string>

#include "content.h"

using std::string;

namespace md_parser {

enum HeaderType {
  NORMAL_HEADER,         // Typical header #, ##, ###, .. etc.
  FANCY_HEADER_FOR_REF,  // #@ form.
  LECTURE_HEADER,        // ###@ form
  TEMPLATE               // ##@ form
};

class HeaderContent : public Content {
 public:
  // Content does not include the ###s.
  HeaderContent(const string& content, const string& header_token,
                int header_index);
  string OutputHtml(ParserEnvironment* parser_env) override;
  void AddContent(const string& content) override;
  TokenTypes GetContentType() const override { return TokenTypes::HEADER; }

 private:
  const string header_token_;
  int header_index_;
};

}  // namespace md_parser
