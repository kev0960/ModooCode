#include "content_header.h"

#include <algorithm>
#include <limits>
#include <unordered_set>
#include <vector>

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

string HeaderContent::OutputHtml(ParserEnvironment* parser_env) {
  auto output_html = Content::OutputHtml(parser_env);
  if (output_html.empty()) {
    return "";
  }
  string start_header, end_header;
  auto header_type = GetHeaderType(header_token_);
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
    }
    else if (content_ == "chewing-cpp-end") {
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
    }
  } else if (header_type == NORMAL_HEADER) {
    start_header =
        StrCat("<h", std::to_string(header_token_.size()), " id='page-heading-",
               std::to_string(header_index_), "'>");
    end_header = StrCat("</h", std::to_string(header_token_.size()), ">");
  } else if (header_type == FANCY_HEADER_FOR_REF) {
    start_header = StrCat(R"(<h2 class="ref-header" )", "id='page-heading-",
                          std::to_string(header_index_), "'>");
    end_header = R"(</h2>)";
  } else if (header_type == LECTURE_HEADER) {
    start_header = StrCat(R"(<h3 class="lecture-header" )", "id='page-heading-",
                          std::to_string(header_index_), "'>");
    end_header = R"(</h3>)";
    return StrCat(start_header, Content::OutputHtml(parser_env), end_header);
  }
  StripMarkdown(&content_);
  EscapeHtmlString(&content_);
  return StrCat(start_header, content_, end_header);
}

void HeaderContent::AddContent(const string& content) { content_ += content; }

}  // namespace md_parser
