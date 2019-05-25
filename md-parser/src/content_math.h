#pragma once
#include "content.h"

namespace md_parser {

class MathContent : public Content {
 public:
  MathContent(const string& content);
  string OutputHtml(ParserEnvironment* parser_env) override;
  string OutputLatex(ParserEnvironment* parser_env) override;
  void Preprocess(ParserEnvironment* parser_env) override {}

  void AddContent(const string& content) override;
  TokenTypes GetContentType() const override { return TokenTypes::MATH; }
};

} // namespace md_parser
