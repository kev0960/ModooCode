#include "content_math.h"

#include "util.h"

namespace md_parser {

MathContent::MathContent(const string& content) : Content(content) {}

void MathContent::AddContent(const string& content) { content_ += content; }

string MathContent::OutputHtml(ParserEnvironment* parser_env) {
  return StrCat("<p class='math-latex'>$$", content_, "</p>");
}

string MathContent::OutputLatex(ParserEnvironment* parser_env) {
  // Remove trailing $$.
  string math_eq = content_;
  size_t pos = 0;
  if ((pos = math_eq.rfind("$$")) != string::npos) {
    math_eq.erase(pos, 2);
  }
  return StrCat("\n\\[\n", math_eq, "\n\\]\n");
}

}  // namespace md_parser
