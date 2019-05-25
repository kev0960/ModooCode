#pragma once
#include "content.h"

namespace md_parser {

class QuoteContent : public Content {
 public:
  QuoteContent(const string& content);
  string OutputHtml(ParserEnvironment* parser_env) override;
  string OutputLatex(ParserEnvironment* parser_env) override;
  void Preprocess(ParserEnvironment* parser_env) override {}

  void AddContent(const string& content) override;
  TokenTypes GetContentType() const override { return TokenTypes::QUOTE; }
};

} // namespace md_parser
