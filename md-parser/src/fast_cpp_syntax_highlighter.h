#pragma once

#include "fast_syntax_highlighter.h"

namespace md_parser {
class FastCppSyntaxHighlighter : public FastSyntaxHighlighter {
 public:
  FastCppSyntaxHighlighter(const string& code) : FastSyntaxHighlighter(code) {}
  bool ParseCode() override;

 private:
  void AppendCurrentToken(SyntaxTokenType current_token, size_t token_start,
                          size_t token_end);
  size_t HandleMacro(size_t macro_start);
};
}  // namespace md_parser
