#include "../src/parser.h"

#include "../src/util.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace md_parser {

static std::unordered_map<string, std::vector<ReferenceInfo>> ref_to_url = {};
static std::vector<string> path_vec = {};

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

struct ListOrElem {
  string content;
  bool is_list;

  ListOrElem(const string& s, bool is_list = false)
      : content(s), is_list(is_list) {}
};

ListOrElem MakeOrderedList(std::vector<ListOrElem> list) {
  string output = "<ol>";
  for (const auto& s : list) {
    if (s.is_list) {
      output += s.content;
    } else {
      output += StrCat("<li>", s.content, "</li>");
    }
  }
  output += "</ol>";
  return ListOrElem(output, true);
}

ListOrElem MakeUnorderedList(std::vector<ListOrElem> list) {
  string output = "<ul>";
  for (const auto& s : list) {
    if (s.is_list) {
      output += s.content;
    } else {
      output += StrCat("<li>", s.content, "</li>");
    }
  }
  output += "</ul>";
  return ListOrElem(output, true);
}

ListOrElem MakeOrderedListLatex(std::vector<ListOrElem> list) {
  string output = "\n\\begin{enumerate}";
  for (const auto& s : list) {
    if (s.is_list) {
      output += s.content;
    } else {
      output += StrCat("\n\\item ", s.content);
    }
  }
  output += "\n\\end{enumerate}\n";
  return ListOrElem(output, true);
}

string MakeTable(const std::vector<std::vector<string>>& table,
                 const std::vector<string>& column_class) {
  string html = "<table>";
  if (table.size() == 0) {
  }
  for (size_t i = 0; i < table.size(); i++) {
    if (i == 0) {
      html += "<thead>";
    }
    html += "<tr>";
    for (size_t j = 0; j < table[i].size(); j++) {
      if (j < column_class.size() && !column_class[j].empty()) {
        html += StrCat(R"(<td class=")", column_class[j], R"("><p>)",
                       table[i][j], "</p></td>");
      } else {
        html += StrCat("<td><p>", table[i][j], "</p></td>");
      }
    }
    html += "</tr>";
    if (i == 0) {
      html += "</thead>";
      html += "<tbody>";
    }
  }
  html += "</tbody></table>";
  return html;
}

string MakeBox(const string& type, const string& cls, const string& content) {
  return StrCat("<", type, " class='", cls, "'>", content, "</", type, ">");
}

}  // namespace

class MockMDParser : public MDParser {
 public:
  virtual const std::vector<std::unique_ptr<Content>>& GetContentList() const {
    return MDParser::GetContentList();
  }

  MockMDParser(const string& content) : MDParser(content, false) {
    Parser(ParserConfig{});
  }
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
  const auto list_elem_a = ListOrElem("<p> a</p>");
  const auto list_elem_b = ListOrElem("<p> b</p>");
  const auto list_elem_c = ListOrElem("<p> c</p>");
  EXPECT_EQ(parser_enum_list.ConvertToHtml(&ref_to_url, path_vec),
            MakeOrderedList({list_elem_a, list_elem_a,
                             MakeOrderedList({list_elem_b, list_elem_b,
                                              MakeOrderedList({list_elem_c})}),
                             list_elem_a})
                .content);

  const auto list_elem_a_tex = ListOrElem(" a");
  const auto list_elem_b_tex = ListOrElem(" b");
  const auto list_elem_c_tex = ListOrElem(" c");
  EXPECT_EQ(
      parser_enum_list.ConvertToLatex(&ref_to_url, path_vec),
      MakeOrderedListLatex(
          {list_elem_a_tex, list_elem_a_tex,
           MakeOrderedListLatex({list_elem_b_tex, list_elem_b_tex,
                                 MakeOrderedListLatex({list_elem_c_tex})}),
           list_elem_a_tex})
          .content);
}

TEST(ParserTest, ComplexListParser) {
  string enum_list = R"(
    1. a
      1. b
        1. c
        * c
      1. b
      * b
    1. a
  )";
  MockMDParser parser_enum_list(enum_list);
  const auto list_elem_a = ListOrElem("<p> a</p>");
  const auto list_elem_b = ListOrElem("<p> b</p>");
  const auto list_elem_c = ListOrElem("<p> c</p>");
  EXPECT_EQ(
      parser_enum_list.ConvertToHtml(&ref_to_url, path_vec),
      MakeOrderedList(
          {list_elem_a,
           MakeOrderedList({list_elem_b, MakeOrderedList({list_elem_c}),
                            MakeUnorderedList({list_elem_c}), list_elem_b}),
           MakeUnorderedList({list_elem_b}), list_elem_a})
          .content);

  string unordered_list_with_text = R"(
    1. a
      1. b

this is a text
)";

  MockMDParser parser_unordered_list_with_text(unordered_list_with_text);
  EXPECT_EQ(
      parser_unordered_list_with_text.ConvertToHtml(&ref_to_url, path_vec),
      MakeOrderedList({list_elem_a, MakeOrderedList({list_elem_b})}).content +
          "<p>this is a text</p>");
}

TEST(ParserTest, Box) {
  string box_str = R"(
  ```warning
  This is a warning
  ```
)";

  MockMDParser parser_box(box_str);
  EXPECT_EQ(
      MakeBox("div", "warning warning-text", "<p>  This is a warning</p>"),
      parser_box.ConvertToHtml(&ref_to_url, path_vec));
  EXPECT_EQ(
      StrCat(
          "\n\\begin{tcolorbox}[colback=red!5!white,colframe=red!75!black]\n",
          "  This is a warning\n", "\\end{tcolorbox}\n"),
      parser_box.ConvertToLatex(&ref_to_url, path_vec));

  string box_code = R"(
```cpp
#include <iostream>
int main() { std::cout << "hi" << std::endl; }
```
)";

  string formatted_code =
      "<span class='m'>#include</span><span class='w'> </span><span "
      "class='mb'>&lt;iostream&gt;</span><span class='w'>\n</span><span "
      "class='t'>int</span><span class='w'> </span><span "
      "class='f'>main</span><span class='p'>() { std</span><span "
      "class='o'>::</span><span class='i'>cout </span><span "
      "class='o'>&lt;&lt;</span><span class='w'> </span><span "
      "class='s'>\"hi\"</span><span class='w'> </span><span "
      "class='o'>&lt;&lt;</span><span class='w'> std</span><span "
      "class='o'>::</span><span class='i'>endl; }</span>";

  MockMDParser parser_code(box_code);
  EXPECT_EQ(MakeBox("pre", "chroma lang-cpp", formatted_code),
            parser_code.ConvertToHtml(&ref_to_url, path_vec));
  EXPECT_EQ(StrCat("\\begin{minted}{cpp}\n",
                   "#include <iostream>\nint main() { std::cout << \"hi\" << "
                   "std::endl; }\n",
                   "\\end{minted}\n"),
            parser_code.ConvertToLatex(&ref_to_url, path_vec));
}

TEST(ParserTest, Table) {
  string table_str = R"(
  | col 1 | col 2 | col 3 |
  |:-----:|:------|------:|
  |row a1 | row a2| row a3|
  |row b1 | row b2| row b3|
  )";
  MockMDParser parser_table(table_str);
  EXPECT_EQ(MakeTable({{"col 1", "col 2", "col 3"},
                       {"row a1", "row a2", "row a3"},
                       {"row b1", "row b2", "row b3"}},
                      {"td-align-center", "", "td-align-right"}),
            parser_table.ConvertToHtml(&ref_to_url, path_vec));

  string table_tex = R"(
\begin{tabular}{|c|l|r|}
\hline
col 1 & col 2 & col 3 \\ \hline
row a1 & row a2 & row a3 \\ \hline
row b1 & row b2 & row b3 \\ \hline
\end{tabular}
)";
  EXPECT_EQ(table_tex, parser_table.ConvertToLatex(&ref_to_url, path_vec));
}

TEST(ParserTest, Math) {
  string math_str = R"(
    $$1 + 1 = 2$$
  )";
  MockMDParser parser_math(math_str);
  EXPECT_EQ(R"(<p class='math-latex'>$$1 + 1 = 2$$</p>)",
            parser_math.ConvertToHtml(&ref_to_url, path_vec));

  string long_math_str = R"(
    $$1 + 1 =
      2 + 2 =
      3 $$
  )";
  MockMDParser parser_math_2(long_math_str);
  EXPECT_EQ(R"(<p class='math-latex'>$$1 + 1 =2 + 2 =3 $$</p>)",
            parser_math_2.ConvertToHtml(&ref_to_url, path_vec));
}

TEST(ParserTest, Header) {
  string header = R"(
  ------------
  title : some title
  date : 2018-08-22
  ------------
  )";
  std::map<string, string> parsed_header{{"title", "some title"},
                                         {"date", "2018-08-22"}};
  MockMDParser header_parser(header);
  EXPECT_THAT(header_parser.GetHeaderInfo(),
              ::testing::ContainerEq(parsed_header));

  string header2 = R"(
  ------------
  date :
  k e y               :             v
  ------------
  )";
  std::map<string, string> parsed_header2{{"date", ""}, {"k e y", "v"}};
  MockMDParser header_parser2(header2);
  EXPECT_THAT(header_parser2.GetHeaderInfo(),
              ::testing::ContainerEq(parsed_header2));
}
}  // namespace md_parser
