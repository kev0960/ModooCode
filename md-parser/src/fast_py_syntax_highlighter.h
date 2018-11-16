#pragma once

#include "fast_syntax_highlighter.h"

namespace md_parser {
class FastPySyntaxHighlighter : public FastSyntaxHighlighter {
 public:
  FastPySyntaxHighlighter(const string& code) : FastSyntaxHighlighter(code) {}
  bool ParseCode() override;

 private:
  void AppendCurrentToken(SyntaxTokenType current_token, size_t token_start,
                          size_t token_end);
  size_t HandleStringLiteral(size_t string_literal_start);
};
}  // namespace md_parser
