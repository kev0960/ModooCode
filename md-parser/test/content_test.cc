#include "../src/content.h"
#include "../src/util.h"
#include "gtest/gtest.h"

namespace md_parser {

string create_bold_html(const string& s) {
  return StrCat("<span class='font-weight-bold'>", s, "</span>");
}

string create_italic_html(const string& s) {
  return StrCat("<span class='font-italic'>", s, "</span>");
}

TEST(ContentTest, BasicContent) {
  Content plain_content("abcd");
  EXPECT_EQ("abcd", plain_content.OutputHtml());

  Content simple_italic("*abc*");
  EXPECT_EQ(create_italic_html("abc"), simple_italic.OutputHtml());

  Content simple_bold("**abc**");
  EXPECT_EQ(create_bold_html("abc"), simple_bold.OutputHtml());

  Content simple_bold_and_italic("***abc***");
  EXPECT_EQ(create_bold_html(create_italic_html("abc")),
            simple_bold_and_italic.OutputHtml());
}

TEST(ContentTest, ComplexContent) {
  // Interpreted as <b>abc <i> a b c </i></b>abc.
  Content content_1("**abc * a b c ***abc");

  EXPECT_EQ(
      StrCat(create_bold_html(StrCat("abc ", create_italic_html(" a b c "))),
             "abc"),
      content_1.OutputHtml());

  // Interpreted as abc <i>abc<b>a</b>b<b>cc</b></i>.
  Content content_2("abc *abc**a**b**cc***");
  EXPECT_EQ(
      StrCat("abc ", create_italic_html(StrCat("abc", create_bold_html("a"),
                                               "b", create_bold_html("cc")))),
      content_2.OutputHtml());

  Content content_3("****abc****");
  EXPECT_EQ(StrCat(create_bold_html(""), "abc", create_bold_html("")),
            content_3.OutputHtml());
}
}  // namespace md_parser
