#include "fast_py_syntax_highlighter.h"

#include <unordered_set>

#include "util.h"

namespace md_parser {

namespace {
std::unordered_set<string> kPyKeywords = {
    "assert", "async", "await",  "break", "class",    "continue",
    "def",    "del",   "elif",   "else",  "except",   "finally",
    "for",    "from",  "global", "if",    "import",   "in",
    "lambda", "pass",  "raise",  "self",  "nonlocal", "return",
    "try",    "while", "yield",  "as",    "with"};

std::unordered_set<string> kPyBuiltIn = {
    "__import__", "abs",        "all",          "any",      "bin",
    "bool",       "bytearray",  "bytes",        "char",     "classmethod",
    "cmp",        "compile",    "complex",      "delattr",  "dict",
    "dir",        "divmod",     "enumerate",    "eval",     "filter",
    "float",      "format",     "frozenset",    "getattr",  "globals",
    "hasattr",    "hash",       "hex",          "id",       "input",
    "int",        "isinstance", "issubclass",   "iter",     "len",
    "list",       "locals",     "map",          "max",      "memoryview",
    "min",        "next",       "object",       "oct",      "open",
    "ord",        "pow",        "print",        "property", "range",
    "repr",       "reversed",   "round",        "set",      "setattr",
    "slice",      "sorted",     "staticmethod", "str",      "sum",
    "super",      "tuple",      "type",         "vars",     "zip"};

std::unordered_set<string> kPyMagicFunctions = {"__abs__",
                                                "__add__",
                                                "__aenter__",
                                                "__aexit__",
                                                "__aiter__",
                                                "__and__",
                                                "__anext__",
                                                "__await__",
                                                "__bool__",
                                                "__bytes__",
                                                "__call__",
                                                "__complex__",
                                                "__contains__",
                                                "__del__",
                                                "__delattr__",
                                                "__delete__",
                                                "__delitem__",
                                                "__dir__",
                                                "__divmod__",
                                                "__enter__",
                                                "__eq__",
                                                "__exit__",
                                                "__float__",
                                                "__floordiv__",
                                                "__format__",
                                                "__ge__",
                                                "__get__",
                                                "__getattr__",
                                                "__getattribute__",
                                                "__getitem__",
                                                "__gt__",
                                                "__hash__",
                                                "__iadd__",
                                                "__iand__",
                                                "__ifloordiv__",
                                                "__ilshift__",
                                                "__imatmul__",
                                                "__imod__",
                                                "__import__",
                                                "__imul__",
                                                "__index__",
                                                "__init__",
                                                "__instancecheck__",
                                                "__int__",
                                                "__invert__",
                                                "__ior__",
                                                "__ipow__",
                                                "__irshift__",
                                                "__isub__",
                                                "__iter__",
                                                "__itruediv__",
                                                "__ixor__",
                                                "__le__",
                                                "__len__",
                                                "__length_hint__",
                                                "__lshift__",
                                                "__lt__",
                                                "__matmul__",
                                                "__missing__",
                                                "__mod__",
                                                "__mul__",
                                                "__ne__",
                                                "__neg__",
                                                "__new__",
                                                "__next__",
                                                "__or__",
                                                "__pos__",
                                                "__pow__",
                                                "__prepare__",
                                                "__radd__",
                                                "__rand__",
                                                "__rdivmod__",
                                                "__repr__",
                                                "__reversed__",
                                                "__rfloordiv__",
                                                "__rlshift__",
                                                "__rmatmul__",
                                                "__rmod__",
                                                "__rmul__",
                                                "__ror__",
                                                "__round__",
                                                "__rpow__",
                                                "__rrshift__",
                                                "__rshift__",
                                                "__rsub__",
                                                "__rtruediv__",
                                                "__rxor__",
                                                "__set__",
                                                "__setattr__",
                                                "__setitem__",
                                                "__str__",
                                                "__sub__",
                                                "__subclasscheck__",
                                                "__truediv__",
                                                "__xor__"};

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
bool FastPySyntaxHighlighter::ParseCode() {
  SyntaxTokenType current_token = NONE;
  size_t token_start = 0;

  for (size_t i = 0; i < code_.length(); i++) {
    char c = code_[i];
    if (c == '#') {
      AppendCurrentToken(current_token, token_start, i);

      // Read until end of the line.
      size_t comment_end = code_.find("\n", i + 1);
      if (comment_end == string::npos) {
        comment_end = code_.length();
      }

      token_list_.emplace_back(COMMENT, i, comment_end);
      current_token = NONE;
      i = comment_end - 1;
      continue;
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

  // If any identifier is preceded by '(', then we think that the identifier is
  // a function.
  for (size_t i = 0; i < token_list_.size(); i++) {
    if (token_list_[i].token_types == IDENTIFIER &&
        i < token_list_.size() - 1) {
      // Ignore Whitespaces.
      size_t next_parenth = i + 1;
      while (token_list_[next_parenth].token_types == WHITESPACE) {
        next_parenth++;
      }
      if (token_list_[next_parenth].token_types == PARENTHESES &&
          code_[token_list_[next_parenth].token_start] == '(') {
        token_list_[i].token_types = FUNCTION;
      }
    }
  }
  return true;
}

size_t FastPySyntaxHighlighter::HandleStringLiteral(
    size_t string_literal_start) {
  // First check whether it starts with '''.
  if (string_literal_start + 3 < code_.length() &&
      code_.substr(string_literal_start, 3) == "'''") {
    // Then this string is enclosed with other """.
    size_t cur = string_literal_start + 2;
    while (cur < code_.size()) {
      cur = code_.find("'''", cur + 1);
      if (cur == string::npos) {
        cur = code_.size();
        break;
      }
      if (code_[cur - 1] != '\\') {
        cur = cur + 3;
        break;
      }
    }
    token_list_.emplace_back(STRING_LITERAL, string_literal_start, cur);
    return cur;
  } else {
    char quote = code_[string_literal_start];
    size_t cur = string_literal_start;
    while (cur < code_.size()) {
      cur = code_.find(quote, cur + 1);
      if (cur == string::npos) {
        cur = code_.size();
        break;
      }
      if (code_[cur - 1] != '\\') {
        break;
      }
    }
    if (cur == code_.size()) {
      cur--;
    }
    token_list_.emplace_back(STRING_LITERAL, string_literal_start, cur + 1);
    return cur;
  }
  return 0;
}

void FastPySyntaxHighlighter::AppendCurrentToken(SyntaxTokenType current_token,
                                                 size_t token_start,
                                                 size_t token_end) {
  if (current_token == IDENTIFIER) {
    // Check whether it matches one of our keyword set.
    string token = code_.substr(token_start, token_end - token_start);
    if (SetContains(kPyBuiltIn, token)) {
      current_token = BUILT_IN;
    } else if (SetContains(kPyKeywords, token)) {
      current_token = KEYWORD;
    } else if (SetContains(kPyMagicFunctions, token)) {
      current_token = MAGIC_FUNCTION;
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
    token_list_.emplace_back(current_token, token_start, token_end);
  } else if (current_token != NONE) {
    token_list_.emplace_back(current_token, token_start, token_end);
  }
}
}  // namespace md_parser
