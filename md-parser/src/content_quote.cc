#include "content_quote.h"
#include "util.h"

namespace md_parser {

QuoteContent::QuoteContent(const string& content, TokenTypes header_type)
    : Content(content) {}

void QuoteContent::AddContent(const string& content) {
  content_ += content;
}

string QuoteContent::OutputHtml() {
  return StrCat("<p class='quote'>", Content::OutputHtml(), "</p>");
}

}
