#include "content_header.h"

#include <algorithm>
#include <limits>
#include <unordered_set>
#include <vector>

#include "tex_util.h"
#include "util.h"

namespace md_parser {
namespace {
void StripMarkdown(string* html) {
  html->erase(std::remove_if(html->begin(), html->end(),
                             [](char c) { return c == '`'; }),
              html->end());
}

void EscapeHtmlString(string* s) {
  for (size_t i = 0; i < s->length(); i++) {
    if (s->at(i) == '<') {
      s->replace(i, 1, "&lt;");
    } else if (s->at(i) == '>') {
      s->replace(i, 1, "&gt;");
    }
  }
}

HeaderType GetHeaderType(const string& header_token) {
  if (std::all_of(header_token.begin(), header_token.end(),
                  [](const char c) { return c == '#'; })) {
    return NORMAL_HEADER;
  } else if (header_token == "#@") {
    return FANCY_HEADER_FOR_REF;
  } else if (header_token == "###@") {
    return LECTURE_HEADER;
  } else if (header_token == "##@") {
    return TEMPLATE;
  }
  return NORMAL_HEADER;
}

}  // namespace

HeaderContent::HeaderContent(const string& content, const string& header_token,
                             int header_index)
    : Content(content),
      header_token_(header_token),
      header_index_(header_index) {}

void HeaderContent::Preprocess(ParserEnvironment* parser_env) {}

string HeaderContent::OutputHtml(ParserEnvironment* parser_env) {
  Content::Preprocess(parser_env);
  auto output_html = Content::OutputHtml(parser_env);
  if (output_html.empty()) {
    return "";
  }
  string start_header, end_header;
  auto header_type = GetHeaderType(header_token_);
  string header_id =
      " id='page-heading-" + std::to_string(header_index_) + "' ";
  string header_id_anchor =
      " id='page-heading-" + std::to_string(header_index_) + "-hash' ";
  if (header_type == TEMPLATE) {
    TrimLeft(&content_);
    if (content_ == "chewing-c-end") {
      string s = R"(
<div class='next-lecture-box'>강좌를 보다가 조금이라도 <span class='font-weight-bold'>궁금한 것이나 이상한 점이 있다면 꼭 댓글</span>을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요. <br><br>
현재 여러분이 보신 강좌는 <span class='font-italic lecture-title'>&lt;)";
      string t =
          R"(&gt;</span> 입니다. 이번 강좌의 모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요
<div class="next-lecture"><a href="/notice/15">다음 강좌 보러가기</a></div></div>
      )";
      string page_title = parser_env->GetPageTitle();
      StripMarkdown(&page_title);
      EscapeHtmlString(&page_title);
      return StrCat(s, page_title, t);
    } else if (content_ == "chewing-cpp-end") {
      string s = R"(
<div class='next-lecture-box'>강좌를 보다가 조금이라도 <span class='font-weight-bold'>궁금한 것이나 이상한 점이 있다면 꼭 댓글</span>을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요. <br><br>
현재 여러분이 보신 강좌는 <span class='font-italic lecture-title'>&lt;)";
      string t =
          R"(&gt;</span> 입니다. 이번 강좌의 모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요
<div class="next-lecture"><a href="/135">다음 강좌 보러가기</a></div></div>
      )";
      string page_title = parser_env->GetPageTitle();
      StripMarkdown(&page_title);
      EscapeHtmlString(&page_title);
      return StrCat(s, page_title, t);
    } else if (content_ == "cpp-ref-start") {
      string s =
          R"(<div class='cpp-ref-start'><p class='cpp-ref-link'>이 레퍼런스의 모든 내용은
             <a href="https://cppreference.com">여기</a>를 기초로 하여 작성하였습니다.</p>)";
      string t =
          R"(<p class='cpp-lec-introduce'>아직 C++ 에 친숙하지 않다면 <a href="https://modoocode.com/135">씹어먹는 C++</a> 은 어때요?</p></div>)";
      return StrCat(s, t);
    }
  } else if (header_type == NORMAL_HEADER) {
    start_header = StrCat("<h", std::to_string(header_token_.size()), header_id,
                          "class='header-general'><a class='anchor-offset'",
                          header_id_anchor, ">");
    end_header = StrCat("</a></h", std::to_string(header_token_.size()), ">");
  } else if (header_type == FANCY_HEADER_FOR_REF) {
    start_header = StrCat(R"(<h2 class="ref-header" )", header_id, ">");
    end_header = R"(</h2>)";
  } else if (header_type == LECTURE_HEADER) {
    start_header = StrCat(R"(<h3 class="lecture-header" )", header_id,
                          "class='header-general'><a class='anchor-offset'",
                          header_id_anchor, ">");
    end_header = R"(</a></h3>)";
    return StrCat(start_header, Content::OutputHtml(parser_env), end_header);
  }
  StripMarkdown(&content_);
  EscapeHtmlString(&content_);
  return StrCat(start_header, content_, end_header);
}

string HeaderContent::OutputLatex(ParserEnvironment* parser_env) {
  string start_header, end_header;
  auto header_type = GetHeaderType(header_token_);
  if (header_type == NORMAL_HEADER) {
    if (header_token_.size() == 3) {
      start_header = "\n\\subsection{";
    } else if (header_token_.size() == 4) {
      start_header = "\n\\subsubsection{";
    }
    end_header = "}\n";
  } else {
    return "";
  }

  StripMarkdown(&content_);
  string tex = EscapeLatexString(content_);
  Trim(&tex);

  return StrCat(start_header, tex, end_header);
}
void HeaderContent::AddContent(const string& content) { content_ += content; }

}  // namespace md_parser
