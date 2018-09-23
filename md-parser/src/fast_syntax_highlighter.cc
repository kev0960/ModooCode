#include "fast_syntax_highlighter.h"

#include "util.h"

namespace md_parser {
namespace {
string TokenTypeToClassName(const SyntaxTokenType token_type) {
  switch (token_type) {
    case KEYWORD:
      return "k";
    case IDENTIFIER:
      return "i";
    case NUMERIC_LITERAL:
      return "n";
    case STRING_LITERAL:
      return "s";
    case BRACKET:
      return "b";
    case PARENTHESES:
      return "p";
    case PUNCTUATION:
      return "u";
    case OPERATOR:
      return "o";
    case COMMENT:
      return "c";
    case MACRO_HEAD:
      return "m";
    case MACRO_BODY:
      return "mb";
    case WHITESPACE:
      return "w";
  }
  return "";
}
}  // namespace
string FastSyntaxHighlighter::GenerateHighlightedHTML() const {
  string html;
  for (const auto& token : token_list_) {
    string class_name = TokenTypeToClassName(token.token_types);
    html += StrCat("<span class='", class_name, "'>");
  }
  return html;
}
}  // namespace md_parser
