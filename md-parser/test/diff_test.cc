#include "../src/diff.h"

#include "gtest/gtest.h"

namespace md_parser {
namespace {
string AddEnlineInBtwChars(const string& s) {
  string t;

  t.reserve(s.size() * 2);
  for (char c : s) {
    t.push_back(c);
    t.push_back('\n');
  }
  return t;
}
}  // namespace

TEST(DiffTest, FollowDiag) {
  Diff diff(AddEnlineInBtwChars("abc"), AddEnlineInBtwChars("abc"));
  EXPECT_EQ(diff.RunDiff(), "");
}
TEST(DiffTest, BasicDiff) {
  Diff diff(AddEnlineInBtwChars("abcabba"), AddEnlineInBtwChars("cbabac"));
  EXPECT_EQ(diff.RunDiff(), "");
}
TEST(DiffTest, CompletelyDiff) {
  Diff diff(AddEnlineInBtwChars("aaaa"), AddEnlineInBtwChars("bbbb"));
  EXPECT_EQ(diff.RunDiff(), "");
}
}  // namespace md_parser
