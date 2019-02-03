#include "../src/diff.h"

#include <fstream>

#include "../src/util.h"
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

struct DiffInfo {
  bool is_delete;
  int from;
  int to;
  int at;

  DiffInfo(bool is_delete, int from, int to, int at = 0)
      : is_delete(is_delete), from(from), to(to), at(at) {}
};
string DiffInfoToString(std::vector<DiffInfo> info) {
  string diff_str;
  for (const auto& diff_info : info) {
    if (diff_info.is_delete) {
      diff_str.append(StrCat("D ", std::to_string(diff_info.from), " ",
                             std::to_string(diff_info.to), "\n"));
    } else {
      diff_str.append(StrCat("A ", std::to_string(diff_info.from), " ",
                             std::to_string(diff_info.to), " at ",
                             std::to_string(diff_info.at), "\n"));
    }
  }
  return diff_str;
}
}  // namespace

TEST(DiffTest, FollowDiag) {
  string s1 = AddEnlineInBtwChars("abc");
  string s2 = AddEnlineInBtwChars("abc");
  Diff diff(s1, s2);
  EXPECT_EQ(diff.RunDiff(), "");
}

TEST(DiffTest, EmptyDiff) {
  string s1 = "";
  string s2 = "";
  Diff diff(s1, s2);
  EXPECT_EQ(diff.RunDiff(), "");

  s2 = AddEnlineInBtwChars("something");
  Diff diff2(s1, s2);
  EXPECT_EQ(diff2.RunDiff(), DiffInfoToString({{false, 0, 8}}));

  s1 = AddEnlineInBtwChars("something");
  s2 = "";
  Diff diff3(s1, s2);
  EXPECT_EQ(diff3.RunDiff(), DiffInfoToString({{true, 0, 8}}));
}

TEST(DiffTest, BasicDiff) {
  string s1 = AddEnlineInBtwChars("abcabba");
  string s2 = AddEnlineInBtwChars("cbabac");
  Diff diff(s1, s2);
  EXPECT_EQ(
      diff.RunDiff(),
      DiffInfoToString(
          {{true, 0, 1}, {true, 3, 3}, {false, 2, 2, 5}, {false, 5, 5, 7}}));
}
TEST(DiffTest, CompletelyDiff) {
  string s1 = AddEnlineInBtwChars("aaaa");
  string s2 = AddEnlineInBtwChars("bbbb");
  Diff diff(s1, s2);
  EXPECT_EQ(diff.RunDiff(), DiffInfoToString({{false, 0, 3}, {true, 0, 3, 0}}));
}

TEST(DiffTest, ComplexDiff1) {
  string s1 = AddEnlineInBtwChars("abaaacda");
  string s2 = AddEnlineInBtwChars("abadcab");
  Diff diff(s1, s2);
  EXPECT_EQ(
      diff.RunDiff(),
      DiffInfoToString({{true, 3, 5}, {false, 4, 4, 7}, {false, 6, 6, 8}}));
}

TEST(DiffTest, ComplexDiff2) {
  string s1 = AddEnlineInBtwChars("bcadcad");
  string s2 = AddEnlineInBtwChars("dacdbad");
  Diff diff(s1, s2);
  EXPECT_EQ(diff.RunDiff(), DiffInfoToString({{false, 0, 0, 0},
                                              {true, 0, 1},
                                              {false, 2, 2, 3},
                                              {false, 4, 4, 4},
                                              {true, 4, 4}}));
}

TEST(DiffTest, DeletedMiddle) {
  string s1 = AddEnlineInBtwChars("abcdefgxxxxabcdefg");
  string s2 = AddEnlineInBtwChars("abcdefgabcdefg");
  Diff diff(s1, s2);
  EXPECT_EQ(diff.RunDiff(), DiffInfoToString({{true, 7, 10}}));
}

TEST(DiffTest, AddedMiddle) {
  string s1 = AddEnlineInBtwChars("abcdefgabcdefg");
  string s2 = AddEnlineInBtwChars("abcdefgxxxxabcdefg");
  Diff diff(s1, s2);
  EXPECT_EQ(diff.RunDiff(), DiffInfoToString({{false, 7, 10, 7}}));
}

TEST(DiffTest, EmptyPatch) {
  string s1 = "";
  string s2 = "";
  Diff diff(s1, s2);
  string patchs = diff.CreatePatch();
  PatchFromDiff patch(s1, patchs);
  EXPECT_EQ(s2, patch.GetPatchedString());

  s2 = AddEnlineInBtwChars("something");
  Diff diff2(s1, s2);
  patchs = diff2.CreatePatch();
  PatchFromDiff patch2(s1, patchs);
  EXPECT_EQ(s2, patch2.GetPatchedString());

  s1 = AddEnlineInBtwChars("something");
  s2 = "";
  Diff diff3(s1, s2);
  patchs = diff3.CreatePatch();
  PatchFromDiff patch3(s1, patchs);
  EXPECT_EQ(s2, patch3.GetPatchedString());
}

TEST(DiffTest, SimplePatch) {
  string s1 = AddEnlineInBtwChars("aabbbcccc");
  string s2 = AddEnlineInBtwChars("abdcabecf");
  Diff diff(s1, s2);

  string patchs = diff.CreatePatch();
  PatchFromDiff patch(s1, patchs);
  EXPECT_EQ(s2, patch.GetPatchedString());
}

TEST(DiffTest, PatchAddedMiddle) {
  string s1 = AddEnlineInBtwChars("abcdefgabcdefg");
  string s2 = AddEnlineInBtwChars("abcdefgxxxxabcdefg");
  Diff diff(s1, s2);

  string patchs = diff.CreatePatch();
  PatchFromDiff patch(s1, patchs);
  EXPECT_EQ(s2, patch.GetPatchedString());
}

TEST(DiffTest, ExhaustivePatchMatch) {
  string s1 = "aabbbccccde";
  string s2 = AddEnlineInBtwChars("debabdcabecfg");

  do {
    string s1_endl = AddEnlineInBtwChars(s1);
    Diff diff(s1_endl, s2);

    string patchs = diff.CreatePatch();
    PatchFromDiff patch(s1_endl, patchs);
    EXPECT_EQ(s2, patch.GetPatchedString());
  } while (std::next_permutation(s1.begin(), s1.end()));
}

TEST(DiffTest, FileDiff) {
  std::ifstream read_file("../python/md/dump_102.md");
  string content;

  read_file.seekg(0, std::ios::end);
  content.reserve(read_file.tellg());
  read_file.seekg(0, std::ios::beg);

  content.assign((std::istreambuf_iterator<char>(read_file)),
                 std::istreambuf_iterator<char>());

  Diff diff(content, content);
  LOG << diff.CreatePatch();
}
}  // namespace md_parser
