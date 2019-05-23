#pragma once
#include <string>

#include "content.h"

using std::string;

namespace md_parser {

class BoxContent : public Content {
 public:
  // Content does not include the ###s.
  BoxContent(const string& content, const string& box_name);
  string OutputHtml(ParserEnvironment* parser_env) override;
  string OutputLatex(ParserEnvironment* parser_env) override;
  void AddContent(const string& content) override;
  TokenTypes GetContentType() const override { return TokenTypes::BOX; }

 private:
  enum BOX_CONTENT_TYPES {
    CPP_CODE,
    CPP_FORMATTED_CODE,
    PY_CODE,
    WARNING,
    CODE_WARNING,
    COMPILER_WARNING,
    LEC_WARNING,
    INFO,
    INFO_FORMAT,
    INFO_TEXT,
    EXEC,
    LEC_SUMMARY
  };

  BOX_CONTENT_TYPES box_type_;
};

}  // namespace md_parser
