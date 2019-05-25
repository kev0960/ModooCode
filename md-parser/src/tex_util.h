#ifndef TEX_UTIL_H
#define TEX_UTIL_H

#include <string>
using std::string;

namespace md_parser {

string EscapeLatexString(const string& s);

string CreateTColorBox(const string& content, const string& color,
                       const string& title="", const string& font_color = "white");
}  // namespace md_parser
#endif
