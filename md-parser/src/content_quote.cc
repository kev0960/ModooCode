#include "content_quote.h"

#include <unordered_set>

#include "util.h"

#define CONTINUE_IF_NOT_FOUND(s) \
  if (s == string::npos) {       \
    continue;                    \
  }

namespace md_parser {
namespace {
void StripTags(string* html) {
  std::unordered_set<string> disallowed_tags = {"p"};
  string stripped_string = "";
  for (size_t i = 0; i < html->size(); i++) {
    if (html->at(i) == '<') {
      auto tag_name_end = html->find_first_of(" >", i + 1);
      CONTINUE_IF_NOT_FOUND(tag_name_end);

      auto opening_tag_close_bracket = html->find(">", tag_name_end);
      CONTINUE_IF_NOT_FOUND(opening_tag_close_bracket);
      const string tag_name = html->substr(i + 1, tag_name_end - (i + 1));
      // If found tag is not allowed, then only take the inner html text.
      if (disallowed_tags.find(tag_name) != disallowed_tags.end()) {
        // Find the ending tag.
        const string end_tag = StrCat("</", tag_name, ">");
        auto closing_tag_start = html->find(end_tag, tag_name_end);
        CONTINUE_IF_NOT_FOUND(closing_tag_start);
        // We have to remove i ~ opening_tag_close_bracket
        // and end_tag ~ end_tag + end_tag.length(). Note that we have to
        // remove the end tag first (to preserve the index).
        html->erase(closing_tag_start, end_tag.length());
        html->erase(i, opening_tag_close_bracket - i + 1);
        if (i != 0) {
          i--;
        }
      }
    }
  }
}
}  // namespace

QuoteContent::QuoteContent(const string& content) : Content(content) {}

void QuoteContent::AddContent(const string& content) { content_ += content; }

string QuoteContent::OutputHtml(ParserEnvironment* parser_env) {
  Content::Preprocess(parser_env);
  string html = Content::OutputHtml(parser_env);
  StripTags(&html);
  return StrCat("<blockquote class='quote'>", html, "</blockquote>");
}

string QuoteContent::OutputLatex(ParserEnvironment* parser_env) {
  Content::Preprocess(parser_env);
  string tex = Content::OutputLatex(parser_env);
  // \usepackage{csquotes}
  return StrCat("\n\\begin{displayquote}\n", tex, "\n\\end{displayquote}\n");
}

}  // namespace md_parser
