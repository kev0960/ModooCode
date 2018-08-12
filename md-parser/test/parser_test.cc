#include "../src/parser.h"
#include "gtest/gtest.h"

namespace md_parser {

namespace {
bool CheckParsedContentOrders(
    const std::vector<std::unique_ptr<Content>>& contents,
    const std::vector<TokenTypes>& content_types) {
  if (contents.size() != content_types.size()) return false;
  for (size_t i = 0; i < contents.size(); i++) {
    if (contents.at(i)->GetContentType() != content_types.at(i)) return false;
  }
  return true;
}
}

class MockMDParser : public MDParser {
 public:
  virtual const std::vector<std::unique_ptr<Content>>& GetContentList() const {
    return MDParser::GetContentList();
  }

  MockMDParser(const string& content) : MDParser(content) {}
};

TEST(ParserTest, AnalyzeLine) {
  MockMDParser parser("This is sample text");
  EXPECT_TRUE(CheckParsedContentOrders(parser.GetContentList(),
        {TEXT}));
}
}
