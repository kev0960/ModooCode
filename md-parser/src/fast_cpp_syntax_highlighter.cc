#include "fast_cpp_syntax_highlighter.h"

#include <unordered_set>

#include "util.h"

namespace md_parser {

char kWhiteSpaces[] = " \t\n";
std::unordered_set<string> kCppKeywords = {
    /* C++ specific */
    "class", "catch", "const_cast", "delete", "dynamic_cast", "explicit",
    "export", "friend", "mutable", "namespace", "new", "operator", "private",
    "protected", "public", "reinterpret_cast", "restrict", "static_cast",
    "template", "this", "throw", "try", "typeid", "typename", "using",
    "virtual", "constexpr", "nullptr", "decltype", "thread_local", "alignas",
    "alignof", "static_assert", "noexcept", "override", "final",
    /* C */
    "asm", "auto", "break", "case", "const", "continue", "default", "do",
    "else", "enum", "extern", "for", "goto", "if", "register", "restricted",
    "return", "sizeof", "static", "struct", "switch", "typedef", "union",
    "volatile", "while"};

std::unordered_set<string> kCppTypeKeywords = {
    "bool",   "int",  "long", "float", "short", "double", "char",    "unsigned",
    "signed", "void", "int8", "int16", "int32", "int64",  "wchar_t", "string"};
namespace {

// Check whether the character is allowed in the identifier.
bool IsIdenfierAllowedChar(char c) {
  if ('0' <= c && c <= '9') {
    return true;
  }
  if ('a' <= c && c <= 'z') {
    return true;
  }
  if ('A' <= c && c <= 'Z') {
    return true;
  }
  if (c == '_') {
    return true;
  }
  return false;
}

bool IsWhiteSpace(char c) {
  if (c == '\t' || c == ' ' || c == '\n') {
    return true;
  }
  return false;
}

bool IsNumber(char c) { return '0' <= c && c <= '9'; }

bool IsNumericLiteral(const string& s) {
  if (s.length() == 0) {
    return false;
  }
  if (IsNumber(s[0])) {
    return true;
  }
  if (s[0] == '.' && s.length() > 1) {
    if (IsNumber(s[1])) {
      return true;
    }
    return false;
  }
  return false;
}

bool IsParentheses(char c) {
  if (c == '(' || c == ')') {
    return true;
  }
  return false;
}

bool IsStringLiteralStart(char c) {
  if (c == '"' || c == '\'') {
    return true;
  }
  return false;
}

bool IsOperator(char c) {
  switch (c) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '^':
    case '&':
    case '!':
    case '?':
    case ':':
    case '|':
    case '=':
    case '<':
    case '>':
    case '~':
    case '.':
      return true;
  }
  return false;
}

bool IsPunctuation(char c) {
  if (c == ',' || c == ';') {
    return true;
  }
  return false;
}

bool IsBracket(char c) {
  if (c == '[' || c == ']') {
    return true;
  }
  return false;
}

bool IsBrace(char c) {
  if (c == '{' || c == '}') {
    return true;
  }
  return false;
}

}  // namespace

// Linear scan the entire code to generate parse the code into tokens.
bool FastCppSyntaxHighlighter::ParseCode() {
  SyntaxTokenType current_token = NONE;
  size_t token_start = 0;

  for (size_t i = 0; i < code_.length(); i++) {
    char c = code_[i];
    if (c == '#') {
      AppendCurrentToken(current_token, token_start, i);
      i = HandleMacro(i);
      token_start = i;
      i--;
      current_token = NONE;
      continue;
    }
    if (c == '/' && i < code_.length() - 1) {
      if (code_[i + 1] == '*') {
        AppendCurrentToken(current_token, token_start, i);
        current_token = NONE;
        size_t comment_end = code_.find("*/", i + 2);
        if (comment_end == string::npos) {
          comment_end = code_.length();
        } else {
          comment_end += 2;
        }
        token_list_.push_back(SyntaxToken(COMMENT, i, comment_end));
        i = comment_end - 1;
        continue;
      } else if (code_[i + 1] == '/') {
        AppendCurrentToken(current_token, token_start, i);
        current_token = NONE;
        size_t comment_end = code_.find("\n", i + 2);
        if (comment_end == string::npos) {
          comment_end = code_.length();
        }
        token_list_.push_back(SyntaxToken(COMMENT, i, comment_end));
        i = comment_end - 1;
        continue;
      }
    }
    if (IsOperator(c)) {
      // '-' or '.' can be located in the middle of floating point number.
      if ((c == '-' || c == '.') && current_token == IDENTIFIER &&
          IsNumericLiteral(code_.substr(token_start, i - token_start)) &&
          i + 1 < code_.length() && IsNumber(code_[i + 1])) {
        continue;
      }
      if (current_token != OPERATOR) {
        AppendCurrentToken(current_token, token_start, i);
        current_token = OPERATOR;
        token_start = i;
      }
    }
    // During tokenizing step, we do not distinguish between identifier versus
    // keyword. After the identifier token has determined, we check whether it
    // matches to one of our keyword set. If it does, then we mark it as a
    // keyword.
    else if (IsIdenfierAllowedChar(c)) {
      if (current_token != IDENTIFIER) {
        AppendCurrentToken(current_token, token_start, i);
        current_token = IDENTIFIER;
        token_start = i;
      }
    } else if (IsWhiteSpace(c)) {
      if (current_token != WHITESPACE) {
        AppendCurrentToken(current_token, token_start, i);
        current_token = WHITESPACE;
        token_start = i;
      }
    } else if (IsParentheses(c)) {
      if (current_token != PARENTHESES) {
        AppendCurrentToken(current_token, token_start, i);
        current_token = PARENTHESES;
        token_start = i;
      }
    } else if (IsStringLiteralStart(c)) {
      AppendCurrentToken(current_token, token_start, i);
      token_start = HandleStringLiteral(i);
      i = token_start - 1;
      current_token = NONE;
    } else if (IsBracket(c)) {
      if (current_token != BRACKET) {
        AppendCurrentToken(current_token, token_start, i);
        current_token = BRACKET;
        token_start = i;
      }
    } else if (IsBrace(c)) {
      if (current_token != BRACE) {
        AppendCurrentToken(current_token, token_start, i);
        current_token = BRACE;
        token_start = i;
      }
    } else if (IsPunctuation(c)) {
      if (current_token != PUNCTUATION) {
        AppendCurrentToken(current_token, token_start, i);
        current_token = PUNCTUATION;
        token_start = i;
      }
    }
  }
  AppendCurrentToken(current_token, token_start, code_.length());
  return true;
}

size_t FastCppSyntaxHighlighter::HandleStringLiteral(
    size_t string_literal_start) {
  if (string_literal_start >= 1 && code_[string_literal_start - 1] == 'R') {
    // Handle raw string.
    // First find the delimiter.
    string delimiter = code_.substr(
        string_literal_start + 1,
        code_.find('(', string_literal_start + 1) - (string_literal_start + 1));
    string end_delimiter = StrCat(")", delimiter, "\"");
    size_t literal_end = code_.find(end_delimiter, string_literal_start + 1);
    AppendCurrentToken(STRING_LITERAL, string_literal_start,
                       literal_end + end_delimiter.length());
    return literal_end + end_delimiter.length();
  }
  char start_quote = code_[string_literal_start];
  for (size_t i = string_literal_start + 1; i < code_.length(); i++) {
    if (code_[i] == start_quote) {
      if (i >= 1 && code_[i - 1] != '\\') {
        AppendCurrentToken(STRING_LITERAL, string_literal_start, i + 1);
        return i + 1;
      }
    }
  }
  return code_.length();
}

size_t FastCppSyntaxHighlighter::HandleMacro(size_t macro_start) {
  // Find the delimiter.
  size_t delimiter_pos = code_.find_first_of(kWhiteSpaces, macro_start + 1);
  size_t header_token_end = delimiter_pos;
  if (delimiter_pos == string::npos) {
    header_token_end = code_.length();
  }
  token_list_.push_back(SyntaxToken(MACRO_HEAD, macro_start, header_token_end));

  if (delimiter_pos == string::npos) {
    return code_.length();
  }
  size_t body_start = delimiter_pos + 1;
  if (code_[delimiter_pos] == ' ') {
    size_t whitespace_start = delimiter_pos;
    while (code_[delimiter_pos] == ' ') {
      delimiter_pos++;
    }
    token_list_.push_back(
        SyntaxToken(WHITESPACE, whitespace_start, delimiter_pos));
    body_start = delimiter_pos;
  }

  delimiter_pos = code_.find("\n", delimiter_pos);

  // Now we have to check the body. We have to consider line continuation!
  while (code_[delimiter_pos - 1] == '\\') {
    delimiter_pos = code_.find("\n", delimiter_pos + 1);
    if (delimiter_pos == string::npos) {
      break;
    }
  }

  if (delimiter_pos == string::npos) {
    delimiter_pos = code_.length();
  }

  token_list_.push_back(SyntaxToken(MACRO_BODY, body_start, delimiter_pos));
  return delimiter_pos;
}

void FastCppSyntaxHighlighter::AppendCurrentToken(SyntaxTokenType current_token,
                                                  size_t token_start,
                                                  size_t token_end) {
  if (current_token == IDENTIFIER) {
    // Check whether it matches one of our keyword set.
    string token = code_.substr(token_start, token_end - token_start);
    if (Contains(kCppTypeKeywords, token)) {
      current_token = TYPE_KEYWORD;
    } else if (Contains(kCppKeywords, token)) {
      current_token = KEYWORD;
    } else if (IsNumericLiteral(token)) {
      current_token = NUMERIC_LITERAL;
      // It is possible that the numeric literal starts with .
      // (e.g .1E4f) In this case, the preceding '.' would be interpreted as an
      // operator.
      if (!token_list_.empty() &&
          code_.substr(token_list_.back().token_start,
                       token_list_.back().token_end -
                           token_list_.back().token_start) == ".") {
        token_list_.pop_back();
        token_start--;
      }
    }
    token_list_.push_back(SyntaxToken(current_token, token_start, token_end));
  } else if (current_token != NONE) {
    token_list_.push_back(SyntaxToken(current_token, token_start, token_end));
  }
}
}  // namespace md_parser
