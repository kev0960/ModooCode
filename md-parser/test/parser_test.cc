#include "../src/parser.h"
#include "../src/util.h"
#include "gtest/gtest.h"

namespace md_parser {

namespace {
bool CheckParsedContentOrders(
    const std::vector<std::unique_ptr<Content>>& contents,
    const std::vector<TokenTypes>& content_types) {
  EXPECT_EQ(contents.size(), content_types.size());
  for (size_t i = 0; i < std::min(content_types.size(), contents.size()); i++) {
    EXPECT_EQ(contents.at(i)->GetContentType(), content_types.at(i));
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

  MockMDParser(const string& content) : MDParser(content) { Parser(); }
};

TEST(ParserTest, SimpleParser) {
  MockMDParser parser("This is sample text");
  CheckParsedContentOrders(parser.GetContentList(), {TEXT});

  MockMDParser parser_text_contd("abc\ndef\n");
  CheckParsedContentOrders(parser_text_contd.GetContentList(), {TEXT});

  MockMDParser parser_text_paragraphs("abc\n\ndef\n");
  CheckParsedContentOrders(parser_text_paragraphs.GetContentList(),
                           {TEXT, TEXT});

  MockMDParser parser_header("### This is a header");
  CheckParsedContentOrders(parser_header.GetContentList(), {HEADER});

  string unordered_list = R"(
    * List
    * List
      Conted Text

    Paragraph
    * Another List)";
  MockMDParser parser_unordered_list(std::move(unordered_list));
  CheckParsedContentOrders(parser_unordered_list.GetContentList(),
                           {LIST_UNORDER, LIST_UNORDER, TEXT, LIST_UNORDER});

  string enum_list = R"(
    This is enum list
      1. Enum 1
      2. Enum 2

    New Enum List
      1. Enum 1)";
  MockMDParser parser_enum_list(std::move(enum_list));
  CheckParsedContentOrders(parser_enum_list.GetContentList(),
                           {TEXT, LIST_ENUM, LIST_ENUM, TEXT, LIST_ENUM});
}

TEST(ParserTest, SimpleOrderedListParser) {
  string enum_list = R"(
    1. a
    1. a
      1. b
      1. b
        1. c
    1. a
  )";
  MockMDParser parser_enum_list(enum_list);
  EXPECT_EQ(parser_enum_list.ConvertToHtml(), "");
}
}
