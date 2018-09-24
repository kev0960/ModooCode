#include "../src/fast_cpp_syntax_highlighter.h"
#include "../src/util.h"
#include "gtest/gtest.h"

namespace md_parser {
namespace {
string TokenTypeToString(SyntaxTokenType type) {
  switch (type) {
    case KEYWORD:
      return "KEYWORD";
    case IDENTIFIER:
      return "IDENTIFIER";
    case NUMERIC_LITERAL:
      return "NUMERIC_LITERAL";
    case STRING_LITERAL:
      return "STRING_LITERAL";
    case BRACKET:
      return "BRACKET";
    case PARENTHESES:
      return "PARENTHESES";
    case BRACE:
      return "BRACE";
    case PUNCTUATION:
      return "PUNCTUATION";
    case OPERATOR:
      return "OPERATOR";
    case COMMENT:
      return "COMMENT";
    case MACRO_HEAD:
      return "MACRO_HEAD";
    case MACRO_BODY:
      return "MACRO_BODY";
    case WHITESPACE:
      return "WHITESPACE";
    case NONE:
      return "NONE";
  }
  return "";
}
}  // namespace

class MockSyntaxHighlighter : public FastCppSyntaxHighlighter {
 public:
  MockSyntaxHighlighter(const string& content)
      : FastCppSyntaxHighlighter(content) {}

  void CheckSyntaxTokens(std::vector<SyntaxToken> token_list) {
    EXPECT_EQ(token_list_.size(), token_list.size());
    for (size_t i = 0; i < std::min(token_list_.size(), token_list.size());
         i++) {
      if (i < token_list_.size() && i < token_list.size()) {
        EXPECT_EQ(TokenTypeToString(token_list[i].token_types),
                  TokenTypeToString(token_list_[i].token_types));
        EXPECT_EQ(token_list[i].token_start, token_list_[i].token_start);
        EXPECT_EQ(token_list[i].token_end, token_list_[i].token_end);
      }
    }
  }
  void PrintTokens() {
    LOG << "Parsed code : " << code_;
    for (size_t i = 0; i < token_list_.size(); i++) {
      LOG << TokenTypeToString(token_list_[i].token_types);
      LOG << " [" << token_list_[i].token_start << " , "
          << token_list_[i].token_end << "]";
    }
  }
};

TEST(SyntaxHighlightTest, CppMacro) {
  MockSyntaxHighlighter syn("#include <iostream>");
  syn.ParseCode();
  syn.CheckSyntaxTokens(
      {{MACRO_HEAD, 0, 8}, {WHITESPACE, 8, 9}, {MACRO_BODY, 9, 19}});

  MockSyntaxHighlighter syn2("#define  SOME_FUNC(X, X) \\\nX*X\n");
  syn2.ParseCode();
  syn2.CheckSyntaxTokens({{MACRO_HEAD, 0, 7},
                          {WHITESPACE, 7, 9},
                          {MACRO_BODY, 9, 30},
                          {WHITESPACE, 30, 31}});
}

TEST(SyntaxHighlightTest, StringLiterals) {
  MockSyntaxHighlighter syn("'a';'b';");
  syn.ParseCode();
  syn.CheckSyntaxTokens({{STRING_LITERAL, 0, 3},
                         {PUNCTUATION, 3, 4},
                         {STRING_LITERAL, 4, 7},
                         {PUNCTUATION, 7, 8}});

  MockSyntaxHighlighter syn2(R"(string s = "hi \"asdf";)");
  syn2.ParseCode();
  syn2.CheckSyntaxTokens({{IDENTIFIER, 0, 6},
                          {WHITESPACE, 6, 7},
                          {IDENTIFIER, 7, 8},
                          {WHITESPACE, 8, 9},
                          {OPERATOR, 9, 10},
                          {WHITESPACE, 10, 11},
                          {STRING_LITERAL, 11, 22},
                          {PUNCTUATION, 22, 23}});

  MockSyntaxHighlighter syn3(R"test(string s = R"(some"") \ \ a)";)test");
  syn3.ParseCode();
  syn3.CheckSyntaxTokens({{IDENTIFIER, 0, 6},
                          {WHITESPACE, 6, 7},
                          {IDENTIFIER, 7, 8},
                          {WHITESPACE, 8, 9},
                          {OPERATOR, 9, 10},
                          {WHITESPACE, 10, 11},
                          {IDENTIFIER, 11, 12},
                          {STRING_LITERAL, 12, 29},
                          {PUNCTUATION, 29, 30}});

  MockSyntaxHighlighter syn4(
      R"test(string s = R"abc(some")")" \ \ a)abc";)test");
  syn4.ParseCode();
  syn4.CheckSyntaxTokens({{IDENTIFIER, 0, 6},
                          {WHITESPACE, 6, 7},
                          {IDENTIFIER, 7, 8},
                          {WHITESPACE, 8, 9},
                          {OPERATOR, 9, 10},
                          {WHITESPACE, 10, 11},
                          {IDENTIFIER, 11, 12},
                          {STRING_LITERAL, 12, 37},
                          {PUNCTUATION, 37, 38}});
}

TEST(SyntaxHighlightTest, CppNumerals) {
  MockSyntaxHighlighter syn("int a = -123;");
  syn.ParseCode();
  syn.CheckSyntaxTokens({{KEYWORD, 0, 3},
                         {WHITESPACE, 3, 4},
                         {IDENTIFIER, 4, 5},
                         {WHITESPACE, 5, 6},
                         {OPERATOR, 6, 7},
                         {WHITESPACE, 7, 8},
                         {OPERATOR, 8, 9},
                         {NUMERIC_LITERAL, 9, 12},
                         {PUNCTUATION, 12, 13}});

  MockSyntaxHighlighter syn2("float a = 1.2f;");
  syn2.ParseCode();
  syn2.CheckSyntaxTokens({{KEYWORD, 0, 5},
                          {WHITESPACE, 5, 6},
                          {IDENTIFIER, 6, 7},
                          {WHITESPACE, 7, 8},
                          {OPERATOR, 8, 9},
                          {WHITESPACE, 9, 10},
                          {NUMERIC_LITERAL, 10, 14},
                          {PUNCTUATION, 14, 15}});

  MockSyntaxHighlighter syn3("float a = .1E4f;");
  syn3.ParseCode();
  syn3.CheckSyntaxTokens({{KEYWORD, 0, 5},
                          {WHITESPACE, 5, 6},
                          {IDENTIFIER, 6, 7},
                          {WHITESPACE, 7, 8},
                          {OPERATOR, 8, 9},
                          {WHITESPACE, 9, 10},
                          {NUMERIC_LITERAL, 10, 15},
                          {PUNCTUATION, 15, 16}});

  MockSyntaxHighlighter syn4("float a = 0x10.1p0;");
  syn4.ParseCode();
  syn4.CheckSyntaxTokens({{KEYWORD, 0, 5},
                          {WHITESPACE, 5, 6},
                          {IDENTIFIER, 6, 7},
                          {WHITESPACE, 7, 8},
                          {OPERATOR, 8, 9},
                          {WHITESPACE, 9, 10},
                          {NUMERIC_LITERAL, 10, 18},
                          {PUNCTUATION, 18, 19}});

  MockSyntaxHighlighter syn5("float a = 123.456e-67;");
  syn5.ParseCode();
  syn5.CheckSyntaxTokens({{KEYWORD, 0, 5},
                          {WHITESPACE, 5, 6},
                          {IDENTIFIER, 6, 7},
                          {WHITESPACE, 7, 8},
                          {OPERATOR, 8, 9},
                          {WHITESPACE, 9, 10},
                          {NUMERIC_LITERAL, 10, 21},
                          {PUNCTUATION, 21, 22}});
}

TEST(SyntaxHighlightTest, CppStatements) {
  MockSyntaxHighlighter syn(R"(int a;if(a+1>3){a++;})");
  syn.ParseCode();
  syn.CheckSyntaxTokens({{KEYWORD, 0, 3},
                         {WHITESPACE, 3, 4},
                         {IDENTIFIER, 4, 5},
                         {PUNCTUATION, 5, 6},
                         {KEYWORD, 6, 8},
                         {PARENTHESES, 8, 9},
                         {IDENTIFIER, 9, 10},
                         {OPERATOR, 10, 11},
                         {NUMERIC_LITERAL, 11, 12},
                         {OPERATOR, 12, 13},
                         {NUMERIC_LITERAL, 13, 14},
                         {PARENTHESES, 14, 15},
                         {BRACE, 15, 16},
                         {IDENTIFIER, 16, 17},
                         {OPERATOR, 17, 19},
                         {PUNCTUATION, 19, 20},
                         {BRACE, 20, 21}});
}

TEST(SyntaxHighlightTest, CppComments) {
  MockSyntaxHighlighter syn("abc; // Do something\ndef;");
  syn.ParseCode();
  syn.CheckSyntaxTokens({{IDENTIFIER, 0, 3},
                         {PUNCTUATION, 3, 4},
                         {COMMENT, 5, 20},
                         {WHITESPACE, 20, 21},
                         {IDENTIFIER, 21, 24},
                         {PUNCTUATION, 24, 25}});

  MockSyntaxHighlighter syn2("abc; /* this is some comment */ asdf;");
  syn2.ParseCode();
  syn2.CheckSyntaxTokens({{IDENTIFIER, 0, 3},
                         {PUNCTUATION, 3, 4},
                         {COMMENT, 5, 31},
                         {WHITESPACE, 31, 32},
                         {IDENTIFIER, 32, 36},
                         {PUNCTUATION, 36, 37}});
}
}  // namespace md_parser
