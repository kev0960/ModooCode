#pragma once

#include "content.h"

#include <memory>
#include <string>
#include <utility>
#include <vector>

/*

Parsing Rules.

- Parsing is done by line by line basis.
- The whitespace preceeded in the line are ignored.
- All tabs are replaced by 2 spaces.

Markdown Rules

Headings

  The line preceeded by #, ##, ###, ... are marked as Heading.
  Any space in front of #s are ignored (This is not typically correct in most
  of the markdown use cases).

Styling Text

  Bold; **bold** or __bold__
  Italic; *italic* or _italic_

  Simple rule is applied
  1) If the line starts with * and space immediately follows --> It is an
     unordered list
  2) Otherwise, any * appear will be interpreted as styling symbol.
  3) ** must be not separated by any other characters to be tokenized as is.
  4) *** can be either parsed as * ** or ** *. If the next token is * then, it
     is read as ** *. Otherwise, it is * **.

Line Breaks
  1) Single alone linebreak is considered as a continuation of the sentence from
     the previous line.

     e.g.

     aaaaa
     bbbbb

     is interpreted as aaaaabbbbb

  2) Double linbreaks are considered as an actual linebreak. However, it does
     not discontinue any listings or styles.

     e.g

     * aa

     bb

     is interpreted as
     - aa
       bb
  3) Triple linebreaks are considered as an actual linebreak. It also
     DISCONTINUES any formatting passed from above.

*/

namespace md_parser {
enum ParserStateInfo { IDLE, BOLD_START, ITALIC_START, ENUM_START, LIST_START };

struct ParserState {
  ParserStateInfo state;

  // The thing comes below are optional.
  int list_depth;
};

class MDParser {
  std::string content_;
  std::vector<ParserState> states_;

  // List of parsed contents of MD file.
  std::vector<std::unique_ptr<Content>> content_list;

 public:
  MDParser(std::string content);
  void Parser();
  void AnalyzeLine(const std::string& line, std::pair<int, int> space_and_tab);
  TokenTypes GetTokenInfo(const std::string& token);
};
}  // namespace md_parser
