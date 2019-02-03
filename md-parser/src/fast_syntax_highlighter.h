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
  FUNCTION,
  BUILT_IN,        // range, print
  MAGIC_FUNCTION,  // __init__
  NONE             // Not matched to any token.
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
  FastSyntaxHighlighter(const string& code, const string& language)
      : code_(code), language_(language) {
    /* VS style
    class_to_style_map_.insert({"k", {{"color", "#0000ff"}}});
    class_to_style_map_.insert({"s", {{"color", "#a31515"}}});
    class_to_style_map_.insert({"m", {{"color", "#0000ff"}}});
    class_to_style_map_.insert({"mb", {{"color", "#0000ff"}}});
    class_to_style_map_.insert({"t", {{"color", "#2b91af"}}});
    class_to_style_map_.insert({"c", {{"color", "#008000"}}});
    */

    class_to_style_map_.insert({"k", {{"color", "#ff6188"}}});
    class_to_style_map_.insert({"s", {{"color", "#ffd866"}}});
    class_to_style_map_.insert({"m", {{"color", "#ff6188"}}});
    class_to_style_map_.insert({"mb", {{"color", "#ffd866"}}});
    class_to_style_map_.insert({"t", {{"color", "#78dce8"}}});
    class_to_style_map_.insert({"c", {{"color", "#727072"}}});
    class_to_style_map_.insert({"o", {{"color", "#ff6188"}}});
    class_to_style_map_.insert({"n", {{"color", "#ab9df2"}}});
    class_to_style_map_.insert({"f", {{"color", "#a9dc76"}}});
    class_to_style_map_.insert({"l", {{"color", "#78dce8"}}});
    class_to_style_map_.insert({"g", {{"color", "#78dce8"}}});
    // Background 2d2a2e
  }

  virtual bool ParseCode() { return false; };

  // Merge syntax tokens with same colors.
  void ColorMerge();
  string GenerateHighlightedHTML() const;
  void OutputColorCss(string filename) const;

  virtual ~FastSyntaxHighlighter() = default;

 protected:
  string code_;
  std::vector<SyntaxToken> token_list_;
  std::unordered_map<string, std::unordered_map<string, string>>
      class_to_style_map_;

 private:
  string language_;
};

}  // namespace md_parser
