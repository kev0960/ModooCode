#include "../src/path.h"

#include <algorithm>
#include <cctype>

#include "gtest/gtest.h"

namespace md_parser {
namespace {

// Remove every whitespace fron the string.
string StripWhitespace(const string& s) {
  string temp = s;
  temp.erase(std::remove_if(temp.begin(), temp.end(), isspace), temp.end());
  return temp;
}

}  // namespace
TEST(PageTest, SimpleRootPath) {
  PagePath page_path;
  EXPECT_EQ(R"({"":{"files":[]}})",
            StripWhitespace(page_path.DumpPageStructureToJson()));
}

TEST(PageTest, AddFileToRoot) {
  PagePath page_path;
  page_path.AddPagePath("/a");
  page_path.AddPagePath("/b");
  page_path.AddPagePath("/c/");
  EXPECT_EQ(R"({"":{"files":["a","b","c"]}})",
            StripWhitespace(page_path.DumpPageStructureToJson()));
}

TEST(PageTest, AddMultipleFiles) {
  PagePath page_path;
  page_path.AddPagePath("/a/b");
  page_path.AddPagePath("/a/c");
  page_path.AddPagePath("/b/c");
  EXPECT_EQ(R"({"":{"files":[],"a":{"files":["b","c"]},"b":{"files":["c"]}}})",
            StripWhitespace(page_path.DumpPageStructureToJson()));
}

TEST(PageTest, AddMoreMultipleFiles) {
  PagePath page_path;
  page_path.AddPagePath("/a");
  page_path.AddPagePath("/a/b");
  page_path.AddPagePath("/a/c/");
  page_path.AddPagePath("/a/b/c");
  page_path.AddPagePath("/a/b/d/");
  EXPECT_EQ(
      R"({"":{"files":["a"],"a":{"files":["b","c"],"b":{"files":["c","d"]}}}})",
      StripWhitespace(page_path.DumpPageStructureToJson()));
}

}  // namespace md_parser
