#pragma once

#include <string>
#include <unordered_map>
#include <vector>

using std::string;

namespace md_parser {

enum SyntaxTokenType {
  KEYWORD,
  IDENTIFIER,
  NUMERIC_LITERAL,
  STRING_LITERAL,
  BRAKET,
  PARENTHESES,
  BRACES,
  PUNCTUATION,  // ',', ';'
  OPERATOR,
  COMMENT,
  MACRO_HEAD,  // "#include"
  MACRO_BODY,  // "<iostream>"
  WHITESPACE,
  NONE // Not matched to any token.
};

struct SyntaxToken {
  SyntaxTokenType token_types;
  size_t token_start;
  size_t token_end;  // Not inclusive.

  SyntaxToken(SyntaxTokenType token_types, size_t token_start, size_t token_end)
      : token_types(token_types),
        token_start(token_start),
        token_end(token_end) {}
};

class FastSyntaxHighlighter {
 public:
  FastSyntaxHighlighter(const string& code) : code_(code) {}
  virtual bool ParseCode() = 0;
  string GenerateHighlightedHTML() const;

 protected:
  const string& code_;
  std::vector<SyntaxToken> token_list_;
};

}  // namespace md_parser
