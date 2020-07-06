#include "fast_asm_syntax_highlighter.h"

#include <unordered_set>

#include "util.h"

namespace md_parser {
namespace {

std::unordered_set<string> kIntelAsmKeywords = {"section", "dd", "dw"};
std::unordered_set<string> kRegisterNames = {
    "rax", "eax", "ah",  "al",  "rcx", "ecx", "cx",  "ch", "cl",  "rdx", "edx",
    "dx",  "dh",  "dl",  "rbx", "ebx", "bx",  "bh",  "bl", "rsp", "esp", "sp",
    "spl", "rbp", "ebp", "bp",  "bpl", "rsi", "esi", "si", "sil", "rdi", "edi",
    "di",  "dil", "ss",  "cs",  "ds",  "es",  "fs",  "gs"};

bool IsWhiteSpace(char c) {
  if (c == '\t' || c == ' ' || c == '\n') {
    return true;
  }
  return false;
}

bool IsNumber(char c) { return '0' <= c && c <= '9'; }

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
  if (c == '(' || c == ')') {  // Allowed for demangled function name.
    return true;
  }
  if (c == '.') {  // For directives.
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

bool IsNumericLiteral(const string& s) {
  if (s.length() == 0) {
    return false;
  }
  if (IsNumber(s[0])) {
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
}  // namespace

bool FastAsmSyntaxHighlighter::ParseCode() {
  size_t line_start = 0;
  size_t line_end = 0;
  while (line_start < code_.length()) {
    line_end = code_.find('\n', line_start);
    if (line_end == string::npos) {
      line_end = code_.length();
    }

    ParseLine(line_start, line_end);
    if (line_end < code_.length()) {
      AppendCurrentToken(WHITESPACE, line_end, line_end + 1, nullptr);
    }
    line_start = line_end + 1;
  }

  return true;
}

bool IsPunctuation(char c) {
  if (c == ',') {
    return true;
  }
  return false;
}

bool FastAsmSyntaxHighlighter::ParseLine(size_t line_start, size_t line_end) {
  // Number of identifiers in this line. First identifier will be marked as an
  // instruction.
  int identifier_cnt = 0;

  if (code_[line_end - 1] == ':') {
    AppendCurrentToken(LABEL, line_start, line_end, &identifier_cnt);
    return true;
  }

  SyntaxTokenType current_token = NONE;
  size_t token_start = 0;

  for (size_t i = line_start; i < line_end; i++) {
    char c = code_[i];
    if (IsIdenfierAllowedChar(c)) {
      if (current_token != IDENTIFIER) {
        AppendCurrentToken(current_token, token_start, i, &identifier_cnt);
        current_token = IDENTIFIER;
        token_start = i;
      }
    } else if (IsBracket(c)) {
      if (current_token != BRACKET) {
        AppendCurrentToken(current_token, token_start, i, &identifier_cnt);
        current_token = BRACKET;
        token_start = i;
      }
    } else if (IsWhiteSpace(c)) {
      if (current_token != WHITESPACE) {
        AppendCurrentToken(current_token, token_start, i, &identifier_cnt);
        current_token = WHITESPACE;
        token_start = i;
      }
    } else if (c == '#') {  // Comment. Every character that comes after the
                            // comment is treated as such.
      AppendCurrentToken(current_token, token_start, i, &identifier_cnt);
      current_token = COMMENT;
      token_start = i;
      break;
    } else if (IsOperator(c)) {
      if (current_token != OPERATOR) {
        AppendCurrentToken(current_token, token_start, i, &identifier_cnt);
        current_token = OPERATOR;
        token_start = i;
      }
    } else if (IsPunctuation(c)) {
      if (current_token != PUNCTUATION) {
        AppendCurrentToken(current_token, token_start, i, &identifier_cnt);
        current_token = PUNCTUATION;
        token_start = i;
      }
    }
  }

  AppendCurrentToken(current_token, token_start, line_end, &identifier_cnt);
  return true;
}

void FastAsmSyntaxHighlighter::AppendCurrentToken(SyntaxTokenType current_token,
                                                  size_t token_start,
                                                  size_t token_end,
                                                  int* identifier_index) {
  if (current_token == IDENTIFIER) {
    string token = code_.substr(token_start, token_end - token_start);
    if (token.empty()) {
      return;
    }

    if (token.back() == ':') {
      current_token = LABEL;
    } else if (token.front() == '.') {
      current_token = DIRECTIVE;
    } else if (SetContains(kRegisterNames, token)) {
      current_token = REGISTER;
    } else if (*identifier_index == 0) {
      // If not label or directive, then the first identifier will be treated as
      // an instruction.
      (*identifier_index)++;
      current_token = INSTRUCTION;
    } else if (IsNumericLiteral(token)) {
      current_token = NUMERIC_LITERAL;
    }
  }

  if (current_token != NONE) {
    token_list_.emplace_back(current_token, token_start, token_end);
  }
}

}  // namespace md_parser

