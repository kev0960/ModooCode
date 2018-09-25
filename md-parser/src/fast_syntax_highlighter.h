#pragma once

#include <string>
#include <unordered_map>
#include <vector>

using std::string;

namespace md_parser {

enum SyntaxTokenType {
  KEYWORD,
  TYPE_KEYWORD,
  IDENTIFIER,
  NUMERIC_LITERAL,
  STRING_LITERAL,
  BRACKET,
  PARENTHESES,
  BRACE,
  PUNCTUATION,  // ',', ';'
  OPERATOR,
  COMMENT,
  MACRO_HEAD,  // "#include"
  MACRO_BODY,  // "<iostream>"
  WHITESPACE,
  NONE  // Not matched to any token.
};

struct SyntaxToken {
  SyntaxTokenType token_types;
  size_t token_start;
  size_t token_end;  // Not inclusive.

  SyntaxToken(SyntaxTokenType token_types, size_t token_start, size_t token_end)
      : token_types(token_types),
        token_start(token_start),
        token_end(token_end) {}

  bool operator==(const SyntaxToken& token) const {
    return token_types == token.token_types &&
           token_start == token.token_start && token_end == token.token_end;
  }
};

class FastSyntaxHighlighter {
 public:
  FastSyntaxHighlighter(const string& code) : code_(code) {
    class_to_style_map_.insert({"k", {{"color", "#0000ff"}}});
    class_to_style_map_.insert({"s", {{"color", "#a31515"}}});
    class_to_style_map_.insert({"m", {{"color", "#0000ff"}}});
    class_to_style_map_.insert({"mb", {{"color", "#0000ff"}}});
    class_to_style_map_.insert({"t", {{"color", "#2b91af"}}});
    class_to_style_map_.insert({"c", {{"color", "#008000"}}});
  }

  virtual bool ParseCode() { return false; };

  // Merge syntax tokens with same colors.
  void ColorMerge();
  string GenerateHighlightedHTML() const;
  void OutputColorCss(string filename) const;

 protected:
  string code_;
  std::vector<SyntaxToken> token_list_;
  std::unordered_map<string, std::unordered_map<string, string>>
      class_to_style_map_;
};

}  // namespace md_parser
