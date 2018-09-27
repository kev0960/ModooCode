#include "fast_syntax_highlighter.h"

#include <algorithm>
#include <fstream>

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
    case FUNCTION:
      return "f";
    case NONE:
      return "";
  }
  return "";
}

void EscapeHTML(string* s) {
  for (size_t i = 0; i < s->length(); i++) {
    if (s->at(i) == '<') {
      s->replace(i, 1, "&lt;");
      i += 3;
    } else if (s->at(i) == '>') {
      s->replace(i, 1, "&gt;");
      i += 3;
    } else if (s->at(i) == '&') {
      s->replace(i, 1, "&amp;");
      i += 3;
    }
  }
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
  string html = "<pre class='chroma'>";
  for (const auto& token : token_list_) {
    string class_name = TokenTypeToClassName(token.token_types);
    string token_str =
        code_.substr(token.token_start, token.token_end - token.token_start);
    EscapeHTML(&token_str);
    html += StrCat("<span class='", class_name, "'>", token_str, "</span>");
  }
  html += "</pre>";
  return html;
}

void FastSyntaxHighlighter::OutputColorCss(string filename) const {
  std::ofstream out(filename);
  for (const auto& kv : class_to_style_map_) {
    const string& class_name = kv.first;
    const auto& css = kv.second;
    out << ".chroma ." << class_name << " {\n";
    for (const auto& style_and_value : css) {
      out << "  " << style_and_value.first << ":" << style_and_value.second
          << ";\n";
    }
    out << "}\n";
  }
}

// Merge the syntax tokens that belongs to same style. This will help to reduce
// the number of DOM elements.
void FastSyntaxHighlighter::ColorMerge() {
  // Ignore first newlines.
  size_t i = 0;
  while (i < token_list_.size() && token_list_[i].token_types == WHITESPACE) {
    string tok =
        code_.substr(token_list_[i].token_start,
                     token_list_[i].token_end - token_list_[i].token_start);
    for (char c : tok) {
      if (c != '\n') {
        goto newline_remove_done;
      }
    }
    token_list_.erase(token_list_.begin() + i);
    i++;
  }
newline_remove_done:
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
  i = 0;
  while (i < token_list_.size() - 1) {
    const auto current_token = token_list_[i].token_types;
    size_t pivot = i;
    while (i < token_list_.size() - 1) {
      const auto next_token = token_list_[i + 1].token_types;
      if (token_type_to_cluster_id[current_token] ==
          token_type_to_cluster_id[next_token]) {
        token_list_[pivot].token_end = token_list_[i + 1].token_end;
        token_list_[i + 1].token_start = token_list_[i + 1].token_end;
        i++;
      } else {
        break;
      }
    }
    i++;
  }
  // Now remove all the '0' size tokens.
  token_list_.erase(std::remove_if(token_list_.begin(), token_list_.end(),
                                   [](const SyntaxToken& token) {
                                     return token.token_start ==
                                            token.token_end;
                                   }),
                    token_list_.end());
}
}  // namespace md_parser
