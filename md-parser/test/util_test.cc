#include "../src/util.h"
#include "gtest/gtest.h"

namespace md_parser {

TEST(UtilTest, ReadUntilEndOfLine) {
  string line_1 = "abc\ndef\n";
  auto eol = ReadUntilEndOfLine(line_1, 0);
  EXPECT_EQ(3, eol.value());

  auto eol2 = ReadUntilEndOfLine(line_1, 3);
  EXPECT_EQ(3, eol2.value());

  string no_newline = "abc";
  auto eol3 = ReadUntilEndOfLine(no_newline, 0);
  EXPECT_EQ(std::experimental::nullopt, eol3);
}

TEST(UtilTest, TrimLeft) {
  string line_1 = "    \t\taaa";
  auto res = TrimLeft(&line_1);

  EXPECT_STREQ("aaa", line_1.c_str());
  EXPECT_EQ(std::make_pair(4, 2), res);

  string empty_line = "";
  auto res_2 = TrimLeft(&empty_line);

  EXPECT_STREQ("", empty_line.c_str());
  EXPECT_EQ(std::make_pair(0, 0), res_2);
}

TEST(UtilTest, FindFirstOfAny) {
  string line_1 = "ab c\td";
  auto res = FindFirstOfAny(line_1, " \t");

  EXPECT_EQ(line_1.begin() + 2, res);
}

TEST(UtilTest, StrCat) { EXPECT_EQ("con cat", StrCat("c", "on", " ", "cat")); }

TEST(UtilTest, Max) {
  EXPECT_EQ(5, Max(1, 2, 5, 4, 3));
  EXPECT_EQ(5, Max(3, 5, 2, 3, 4));
  EXPECT_EQ(5, Max(5, 2, 3, 1, 3));
  EXPECT_EQ(5, Max(4, 2, 3, 4, 5));
}
}  // namespace md_parser
