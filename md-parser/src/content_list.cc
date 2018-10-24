#include "content_list.h"

#include <limits>
#include <vector>

#include "util.h"

namespace md_parser {

string EnumListContent::OutputHtml(ParserEnvironment* parser_env) {
  string output_html;
  // Decide whether to start with a new <ul>.
  if (parser_env->ShouldStartNewListTag()) {
    output_html += "<ol>";
  }
  output_html += StrCat("<li>", Content::OutputHtml(parser_env), "</li>");
  int close_tag_count = parser_env->ShouldEndListTag();
  while (close_tag_count) {
    output_html += "</ol>";
    close_tag_count--;
  }
  return output_html;
}

void EnumListContent::AddContent(const string& content) { content_ += content; }

string UnorderedListContent::OutputHtml(ParserEnvironment* parser_env) {
  string output_html;
  // Decide whether to start with a new <ul>.
  if (parser_env->ShouldStartNewListTag()) {
    output_html += "<ul>";
  }
  output_html += StrCat("<li>", Content::OutputHtml(parser_env), "</li>");
  int close_tag_count = parser_env->ShouldEndListTag();
  while (close_tag_count) {
    output_html += "</ul>";
    close_tag_count--;
  }
  return output_html;
}

void UnorderedListContent::AddContent(const string& content) {
  content_ += content;
}
}  // namespace md_parser
