#include "fast_syntax_highlighter.h"

#include "util.h"

namespace md_parser {
namespace {
string TokenTypeToClassName(const SyntaxTokenType token_type) {
  switch (token_type) {
    case KEYWORD:
      return "k";
    case TYPE_KEYWORD:
      return "t";
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
    case BRACE:
      return "r";
    case NONE:
      return "";
  }
  return "";
}

template <typename K, typename V>
bool IsUnorderedMapIdentical(const std::unordered_map<K, V>& m1,
                             const std::unordered_map<K, V>& m2) {
  if (m1.size() != m2.size()) {
    return false;
  }
  for (const auto& kv : m1) {
    if (m2.find(kv.first) == m2.end()) {
      return false;
    }
    if (kv.second != m2.at(kv.first)) {
      return false;
    }
  }
  return true;
}

}  // namespace
string FastSyntaxHighlighter::GenerateHighlightedHTML() const {
  string html;
  for (const auto& token : token_list_) {
    string class_name = TokenTypeToClassName(token.token_types);
    html += StrCat(
        "<span class='", class_name, "'>",
        code_.substr(token.token_start, token.token_end - token.token_start),
        "</span>");
  }
  return html;
}

// Merge the syntax tokens that belongs to same style. This will help to reduce
// the number of DOM elements.
void FastSyntaxHighlighter::ColorMerge() {
  // First build a set that tells what Token Types belongs to same style.
  int current_id = 0;
  std::unordered_map<SyntaxTokenType, int> token_type_to_cluster_id;
  for (int token_type = KEYWORD; token_type != NONE; token_type++) {
    const auto tt = static_cast<SyntaxTokenType>(token_type);
    bool added = false;
    for (const auto& kv : token_type_to_cluster_id) {
      if (IsUnorderedMapIdentical(
              class_to_style_map_[TokenTypeToClassName(tt)],
              class_to_style_map_[TokenTypeToClassName(kv.first)])) {
        token_type_to_cluster_id.insert({tt, kv.second});
        added = true;
        break;
      }
    }
    if (!added) {
      token_type_to_cluster_id.insert({tt, current_id++});
    }
  }
  // Now iterate through the token list and merge the tokens with same style.
  size_t i = 0;
  while (i < token_list_.size() - 1) {
    const auto current_token = token_list_[i].token_types;
    size_t pivot = i;
    while (i < token_list_.size() - 1) {
      const auto next_token = token_list_[i + 1].token_types;
      if (token_type_to_cluster_id[current_token] ==
          token_type_to_cluster_id[next_token]) {
        token_list_[pivot].token_end = token_list_[i + 1].token_end;
        i ++;
      } else {
        break;
      }
    }
    i ++;
  }
}
}  // namespace md_parser
