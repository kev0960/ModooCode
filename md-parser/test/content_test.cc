#include "../src/content.h"

#include "../src/util.h"
#include "gtest/gtest.h"

namespace md_parser {

string CreateBoldHtml(const string& s) {
  return StrCat("<span class='font-weight-bold'>", s, "</span>");
}

string CreateItalicHtml(const string& s) {
  return StrCat("<span class='font-italic'>", s, "</span>");
}

string CreateInlineCode(const string& s) {
  return StrCat("<code class='inline-code'>", s, "</code>");
}

string CreateInlineMath(const string& s) {
  return StrCat("<span class='math-latex'>", s, "</span>");
}

string CreateLinkHtml(const string& link_name, const string& link) {
  return StrCat("<a href='", link, "'>", link_name, "</a>");
}

string CreateImageHtml(const string& img_name, const string& img,
                       const string& caption) {
  return StrCat("<figure><img class='content-img' src='", img, "' alt='",
                img_name, "'><figcaption>", caption, "</figcaption></figure>");
}

string CreateBoldLatex(const string& s) { return StrCat("\\textbf{", s, "}"); }

string CreateItalicLatex(const string& s) { return StrCat("\\emph{", s, "}"); }

string CreateInlineLatex(const string& s) {
  return StrCat("\\texttt{", s, "}");
}

string CreateInlineCodeLatex(const string& s) {
  return StrCat("\\texttt{", s, "}");
}
string CreateInlineMathLatex(const string& s) { return StrCat("$", s, "$"); }

string CreateLinkLatex(const string& link_name, const string& link) {
  return StrCat("\\href{", link, "}{", link_name, "}");
}

string CreateImageLatex(const string& img_name, const string& img,
                        const string& caption) {
  if (caption.empty()) {
    return StrCat("\\begin{figure}\n\\includegraphics{", img,
                  "}\n\\end{figure}");
  }
  return StrCat("\\begin{figure}\n\\includegraphics{", img, "}\n\\caption{",
                caption, "}\\end{figure}");
}

string SurroundP(const string& s) { return StrCat("<p>", s, "</p>"); }

static char kFormattedCode[] =
    "<pre class='chroma'><span class='i'>print </span><span "
    "class='s'>'hi'</span></pre>";

static ParserEnvironment mock_parser_env;

TEST(ContentTest, BasicContent) {
  Content plain_content("abcd");
  plain_content.Preprocess(&mock_parser_env);

  EXPECT_EQ(SurroundP("abcd"), plain_content.OutputHtml(&mock_parser_env));

  Content simple_italic("*abc*");
  simple_italic.Preprocess(&mock_parser_env);

  EXPECT_EQ(SurroundP(CreateItalicHtml("abc")),
            simple_italic.OutputHtml(&mock_parser_env));

  Content simple_bold("**abc**");
  simple_bold.Preprocess(&mock_parser_env);

  EXPECT_EQ(SurroundP(CreateBoldHtml("abc")),
            simple_bold.OutputHtml(&mock_parser_env));

  Content simple_bold_and_italic("***abc***");
  simple_bold_and_italic.Preprocess(&mock_parser_env);

  EXPECT_EQ(SurroundP(CreateBoldHtml(CreateItalicHtml("abc"))),
            simple_bold_and_italic.OutputHtml(&mock_parser_env));

  Content simple_bold_and_italic_mixed("*__abc__*");
  simple_bold_and_italic_mixed.Preprocess(&mock_parser_env);

  EXPECT_EQ(SurroundP(CreateItalicHtml(CreateBoldHtml("abc"))),
            simple_bold_and_italic_mixed.OutputHtml(&mock_parser_env));

  Content strike_through("~~strike~~");
  strike_through.Preprocess(&mock_parser_env);

  EXPECT_EQ(SurroundP("<span class='font-strike'>strike</span>"),
            strike_through.OutputHtml(&mock_parser_env));
}

TEST(ContentTest, ComplexContent) {
  // Interpreted as <b>abc <i> a b c </i></b>abc.
  Content content_1("**abc * a b c ***abc");
  content_1.Preprocess(&mock_parser_env);

  EXPECT_EQ(
      SurroundP(StrCat(
          CreateBoldHtml(StrCat("abc ", CreateItalicHtml(" a b c "))), "abc")),
      content_1.OutputHtml(&mock_parser_env));

  // Interpreted as abc <i>abc<b>a</b>b<b>cc</b></i>.
  Content content_2("abc *abc**a**b**cc***");
  content_2.Preprocess(&mock_parser_env);

  EXPECT_EQ(SurroundP(StrCat(
                "abc ", CreateItalicHtml(StrCat("abc", CreateBoldHtml("a"), "b",
                                                CreateBoldHtml("cc"))))),
            content_2.OutputHtml(&mock_parser_env));

  Content content_3("****abc****");
  content_3.Preprocess(&mock_parser_env);

  EXPECT_EQ(SurroundP(StrCat(CreateBoldHtml(""), "abc", CreateBoldHtml(""))),
            content_3.OutputHtml(&mock_parser_env));
}

TEST(ContentTest, Link) {
  Content plain_link("[Modoo Code](http://modoocode.com)");
  plain_link.Preprocess(&mock_parser_env);

  EXPECT_EQ(SurroundP(CreateLinkHtml("Modoo Code", "http://modoocode.com")),
            plain_link.OutputHtml(&mock_parser_env));

  Content empty_name("[](http://modoocode.com)");
  empty_name.Preprocess(&mock_parser_env);

  EXPECT_EQ(SurroundP(CreateLinkHtml("", "http://modoocode.com")),
            empty_name.OutputHtml(&mock_parser_env));

  Content empty_link("[link]()");
  empty_link.Preprocess(&mock_parser_env);

  EXPECT_EQ(SurroundP(CreateLinkHtml("link", "")),
            empty_link.OutputHtml(&mock_parser_env));

  Content not_valid_link1("abc[");
  not_valid_link1.Preprocess(&mock_parser_env);

  Content not_valid_link2("abc[abc]");
  not_valid_link2.Preprocess(&mock_parser_env);

  Content not_valid_link3("abc[abc](");
  not_valid_link3.Preprocess(&mock_parser_env);

  Content not_valid_link4("abc[abc]ab()");
  not_valid_link4.Preprocess(&mock_parser_env);

  EXPECT_EQ(SurroundP("abc["), not_valid_link1.OutputHtml(&mock_parser_env));
  EXPECT_EQ(SurroundP("abc[abc]"),
            not_valid_link2.OutputHtml(&mock_parser_env));
  EXPECT_EQ(SurroundP("abc[abc]("),
            not_valid_link3.OutputHtml(&mock_parser_env));
  EXPECT_EQ(SurroundP("abc[abc]ab()"),
            not_valid_link4.OutputHtml(&mock_parser_env));

  Content link_in_between("this is the [link](http://google.com) thanks");
  link_in_between.Preprocess(&mock_parser_env);

  EXPECT_EQ(
      SurroundP(StrCat("this is the ",
                       CreateLinkHtml("link", "http://google.com"), " thanks")),
      link_in_between.OutputHtml(&mock_parser_env));

  Content link_in_bold("can __[link](http://google.com) in bold? __ maybe");
  link_in_bold.Preprocess(&mock_parser_env);

  EXPECT_EQ(SurroundP(StrCat(
                "can ",
                CreateBoldHtml(StrCat(
                    CreateLinkHtml("link", "http://google.com"), " in bold? ")),
                " maybe")),
            link_in_bold.OutputHtml(&mock_parser_env));

  Content bold_in_link_ignored("[**bold**]()");
}

TEST(ContentTest, Image) {
  Content plain_image("![The Image](/img/a.png)");
  plain_image.Preprocess(&mock_parser_env);

  EXPECT_EQ(CreateImageHtml("The Image", "/img/a.png", ""),
            plain_image.OutputHtml(&mock_parser_env));

  Content excl_and_link("! [a](b)");
  excl_and_link.Preprocess(&mock_parser_env);

  EXPECT_EQ(SurroundP(StrCat("! ", CreateLinkHtml("a", "b"))),
            excl_and_link.OutputHtml(&mock_parser_env));
}

TEST(ContentTest, InlineCode) {
  Content inline_code("this is `print` command");
  inline_code.Preprocess(&mock_parser_env);

  EXPECT_EQ(
      SurroundP(StrCat("this is ", CreateInlineCode("print"), " command")),
      inline_code.OutputHtml(&mock_parser_env));

  Content ignore_other_stuff("this is `a * some_var__x` command");
  ignore_other_stuff.Preprocess(&mock_parser_env);

  EXPECT_EQ(SurroundP(StrCat("this is ", CreateInlineCode("a * some_var__x"),
                             " command")),
            ignore_other_stuff.OutputHtml(&mock_parser_env));
}

TEST(ContentTest, InlineMath) {
  Content inline_math("some $$x=2*b + y$$ math");
  inline_math.Preprocess(&mock_parser_env);

  EXPECT_EQ(
      SurroundP(StrCat("some ", CreateInlineMath("$x=2*b + y$"), " math")),
      inline_math.OutputHtml(&mock_parser_env));
}

TEST(ContentTest, Sidenote) {
  Content sidenote(R"(some \sidenote{this is a sidenote} thing)");
  sidenote.Preprocess(&mock_parser_env);

  EXPECT_EQ(StrCat(SurroundP("some "),
                   "<aside class='sidenote'>this is a sidenote</aside>",
                   SurroundP(" thing")),
            sidenote.OutputHtml(&mock_parser_env));
}

TEST(ContentTest, SmallCaps) {
  Content sidenote(R"(some \sc{SmallCaps} thing)");
  sidenote.Preprocess(&mock_parser_env);

  EXPECT_EQ(
      SurroundP("some <span class='font-smallcaps'>SmallCaps</span> thing"),
      sidenote.OutputHtml(&mock_parser_env));
}

TEST(ContentTest, BasicContentLatex) {
  Content plain_content("abcd");
  plain_content.Preprocess(&mock_parser_env);

  EXPECT_EQ("abcd", plain_content.OutputLatex(&mock_parser_env));

  Content escapes("&%$#{}~^\\");
  escapes.Preprocess(&mock_parser_env);

  EXPECT_EQ(R"(\&\%\$\#\{\}\~\^\\)", escapes.OutputLatex(&mock_parser_env));

  Content simple_italic("*abc*");
  simple_italic.Preprocess(&mock_parser_env);

  EXPECT_EQ(CreateItalicLatex("abc"),
            simple_italic.OutputLatex(&mock_parser_env));

  Content simple_bold("**abc**");
  simple_bold.Preprocess(&mock_parser_env);

  EXPECT_EQ(CreateBoldLatex("abc"), simple_bold.OutputLatex(&mock_parser_env));

  Content simple_bold_and_italic("***abc***");
  simple_bold_and_italic.Preprocess(&mock_parser_env);

  EXPECT_EQ(CreateBoldLatex(CreateItalicLatex("abc")),
            simple_bold_and_italic.OutputLatex(&mock_parser_env));

  Content simple_bold_and_italic_mixed("*__abc__*");
  simple_bold_and_italic_mixed.Preprocess(&mock_parser_env);

  EXPECT_EQ(CreateItalicLatex(CreateBoldLatex("abc")),
            simple_bold_and_italic_mixed.OutputLatex(&mock_parser_env));

  Content strike_through("~~strike~~");
  strike_through.Preprocess(&mock_parser_env);

  EXPECT_EQ("\\sout{strike}", strike_through.OutputLatex(&mock_parser_env));
}

TEST(ContentTest, ComplexContentLatex) {
  // Interpreted as <b>abc <i> a b c </i></b>abc.
  Content content_1("**abc * a b c ***abc");
  content_1.Preprocess(&mock_parser_env);

  EXPECT_EQ(
      StrCat(CreateBoldLatex(StrCat("abc ", CreateItalicLatex(" a b c "))),
             "abc"),
      content_1.OutputLatex(&mock_parser_env));

  // Interpreted as abc <i>abc<b>a</b>b<b>cc</b></i>.
  Content content_2("abc *abc**a**b**cc***");
  content_2.Preprocess(&mock_parser_env);

  EXPECT_EQ(
      StrCat("abc ", CreateItalicLatex(StrCat("abc", CreateBoldLatex("a"), "b",
                                              CreateBoldLatex("cc")))),
      content_2.OutputLatex(&mock_parser_env));

  Content content_3("****abc****");
  content_3.Preprocess(&mock_parser_env);

  EXPECT_EQ(StrCat(CreateBoldLatex(""), "abc", CreateBoldLatex("")),
            content_3.OutputLatex(&mock_parser_env));
}

TEST(ContentTest, LinkLatex) {
  Content plain_link("[Modoo Code](http://modoocode.com)");
  plain_link.Preprocess(&mock_parser_env);

  EXPECT_EQ(CreateLinkLatex("Modoo Code", "http://modoocode.com"),
            plain_link.OutputLatex(&mock_parser_env));

  Content empty_name("[](http://modoocode.com)");
  empty_name.Preprocess(&mock_parser_env);

  EXPECT_EQ(CreateLinkLatex("", "http://modoocode.com"),
            empty_name.OutputLatex(&mock_parser_env));

  Content empty_link("[link]()");
  empty_link.Preprocess(&mock_parser_env);

  EXPECT_EQ(CreateLinkLatex("link", ""),
            empty_link.OutputLatex(&mock_parser_env));

  Content not_valid_link1("abc[");
  not_valid_link1.Preprocess(&mock_parser_env);

  Content not_valid_link2("abc[abc]");
  not_valid_link2.Preprocess(&mock_parser_env);

  Content not_valid_link3("abc[abc](");
  not_valid_link3.Preprocess(&mock_parser_env);

  Content not_valid_link4("abc[abc]ab()");
  not_valid_link4.Preprocess(&mock_parser_env);

  EXPECT_EQ("abc[", not_valid_link1.OutputLatex(&mock_parser_env));
  EXPECT_EQ("abc[abc]", not_valid_link2.OutputLatex(&mock_parser_env));
  EXPECT_EQ("abc[abc](", not_valid_link3.OutputLatex(&mock_parser_env));
  EXPECT_EQ("abc[abc]ab()", not_valid_link4.OutputLatex(&mock_parser_env));

  Content link_in_between("this is the [link](http://google.com) thanks");
  link_in_between.Preprocess(&mock_parser_env);

  EXPECT_EQ(StrCat("this is the ", CreateLinkLatex("link", "http://google.com"),
                   " thanks"),
            link_in_between.OutputLatex(&mock_parser_env));

  Content link_in_bold("can __[link](http://google.com) in bold? __ maybe");
  link_in_bold.Preprocess(&mock_parser_env);

  EXPECT_EQ(
      StrCat("can ",
             CreateBoldLatex(StrCat(
                 CreateLinkLatex("link", "http://google.com"), " in bold? ")),
             " maybe"),
      link_in_bold.OutputLatex(&mock_parser_env));

  Content bold_in_link_ignored("[**bold**]()");
}

TEST(ContentTest, ImageLatex) {
  Content plain_image("![The Image](/img/a.png)");
  plain_image.Preprocess(&mock_parser_env);

  EXPECT_EQ(CreateImageLatex("The Image", "/img/a.png", ""),
            plain_image.OutputLatex(&mock_parser_env));

  Content excl_and_link("! [a](b)");
  excl_and_link.Preprocess(&mock_parser_env);

  EXPECT_EQ(StrCat("! ", CreateLinkLatex("a", "b")),
            excl_and_link.OutputLatex(&mock_parser_env));
}

TEST(ContentTest, InlineCodeLatex) {
  Content inline_code("this is `print` command");
  inline_code.Preprocess(&mock_parser_env);

  EXPECT_EQ(StrCat("this is ", CreateInlineCodeLatex("print"), " command"),
            inline_code.OutputLatex(&mock_parser_env));

  Content ignore_other_stuff("this is `a * some_var__x` command");
  ignore_other_stuff.Preprocess(&mock_parser_env);

  EXPECT_EQ(StrCat("this is ", CreateInlineCodeLatex(R"(a * some\_var\_\_x)"),
                   " command"),
            ignore_other_stuff.OutputLatex(&mock_parser_env));
}

TEST(ContentTest, InlineMathLatex) {
  Content inline_math("some $$x=2*b + y$$ math");
  inline_math.Preprocess(&mock_parser_env);

  EXPECT_EQ(StrCat("some ", CreateInlineMathLatex("x=2*b + y"), " math"),
            inline_math.OutputLatex(&mock_parser_env));
}

TEST(ContentTest, SidenoteLatex) {
  Content sidenote(R"(some \sidenote{this is a sidenote} thing)");
  sidenote.Preprocess(&mock_parser_env);

  EXPECT_EQ(
      StrCat("some ",
             "\n\\begin{sidenotebox}\nthis is a sidenote\n\\end{sidenotebox}\n",
             " thing"),
      sidenote.OutputLatex(&mock_parser_env));
}

TEST(ContentTest, SmallCapsLatex) {
  Content sidenote(R"(some \sc{SmallCaps} thing)");
  sidenote.Preprocess(&mock_parser_env);

  EXPECT_EQ(StrCat("some \\textsc{SmallCaps} thing"),
            sidenote.OutputLatex(&mock_parser_env));
}
}  // namespace md_parser
