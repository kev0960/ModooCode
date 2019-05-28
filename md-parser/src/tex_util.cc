#include "tex_util.h"

#include <unordered_set>

#include "util.h"

namespace md_parser {

string EscapeLatexString(const string& s) {
  // These characters must be escaped in Latex.
  std::unordered_set<char> special_chars = {'&', '%', '$', '#', '_',
                                            '{', '}', '~', '^', '\\'};
  string escaped_str;
  escaped_str.reserve(s.size());

  for (char c : s) {
    if (SetContains(special_chars, c)) {
      if (c == '~') {
        escaped_str += "$\\sim$";
      } else if (c == '^') {
        escaped_str += "$\\hat{}$";
      } else if (c == '\\') {
        escaped_str += "\\textbackslash ";
      } else {
        escaped_str.push_back('\\');
        escaped_str.push_back(c);
      }
    } else {
      escaped_str.push_back(c);
    }
  }

  return escaped_str;
}

string CreateTColorBox(const string& content, const string& color,
                       const string& title, const string& font_color) {
  if (title.empty()) {
    return StrCat("\n\\begin{tcolorbox}[colback=", color, "!5!", font_color,
                  ",colframe=", color, "!75!black,left=3pt,right=3pt]\n",
                  content, "\n\\end{tcolorbox}\n");
  } else {
    return StrCat("\n\\begin{tcolorbox}[colback=", color, "!5!", font_color,
                  ",colframe=", color, "!75!black,title=", title,
                  ",left=3pt,right=3pt]\n", content, "\n\\end{tcolorbox}\n");
  }
}
}  // namespace md_parser
