#include "content_math.h"
#include "util.h"

namespace md_parser {

MathContent::MathContent(const string& content)
    : Content(content) {}

void MathContent::AddContent(const string& content) {
  content_ += content;
}

string MathContent::OutputHtml(ParserEnvironment* parser_env) {
  return StrCat("<p class='math-latex'>$$", content_, "</p>");
}

}
