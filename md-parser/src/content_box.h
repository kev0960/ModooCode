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

  void Preprocess(ParserEnvironment* parser_env) override;

 private:
  enum BOX_CONTENT_TYPES {
    CPP_CODE,
    CPP_FORMATTED_CODE,
    PY_CODE,
    ASM_CODE,
    WARNING,
    CODE_WARNING,
    COMPILER_WARNING,
    LEC_WARNING,
    LEC_INFO,
    INFO,
    INFO_FORMAT,
    INFO_TEXT,
    INFO_TERMINAL,
    INFO_VERB,
    EXEC,
    LEC_SUMMARY,
    HTML_ONLY,
    LATEX_ONLY,
    EMBED,
    SIDENOTE,
    NOTE
  };

  BOX_CONTENT_TYPES box_type_;
};

}  // namespace md_parser
