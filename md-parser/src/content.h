#pragma once
#include <string>
#include <vector>

#include "parser_environment.h"
#include "token_types.h"

using std::string;

namespace md_parser {

struct HtmlFragments {
  enum Types {
    BOLD,
    ITALIC,
    TEXT,
    LINK,
    IMAGE,
    CODE,
    INLINE_CODE,
    SIDENOTE,
    INLINE_MATH
  } type;

  // Start and end are inclusive.
  int str_start;
  int str_end;

  int link_start;
  int link_end;
  string formatted_code;
  string code_style;

  HtmlFragments(Types t, int start, int end, const string& style)
      : type(t),
        str_start(start),
        str_end(end),
        link_start(0),
        link_end(0),
        code_style(style) {}
  HtmlFragments(Types t, int start = 0, int end = 0, int link_start = 0,
                int link_end = 0)
      : type(t),
        str_start(start),
        str_end(end),
        link_start(link_start),
        link_end(link_end) {}
};

// Class for the regular Text content.
class Content {
 public:
  Content(const string& content);

  // Continuation of the content.
  virtual void AddContent(const string& content);
  virtual ~Content(){};
  virtual TokenTypes GetContentType() const { return TokenTypes::TEXT; }
  virtual string OutputHtml(ParserEnvironment* parser_env);

 protected:
  string content_;

 private:
  // Returns start_pos again if nothing is handled.
  size_t HandleLinks(const size_t start_pos,
                     std::vector<HtmlFragments>* fragments, int* text_start);
  size_t HandleImages(const size_t start_pos,
                      std::vector<HtmlFragments>* fragments, int* text_start);
  size_t HandleCodes(const size_t start_pos,
                     std::vector<HtmlFragments>* fragments, int* text_start);
  size_t HandleSpecialCommands(const size_t start_pos,
                               std::vector<HtmlFragments>* fragments,
                               int* text_start);
  void ClangFormatEntireCode(std::vector<HtmlFragments>* fragments);
};

}  // namespace md_parser
