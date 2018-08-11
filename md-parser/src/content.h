#pragma once
#include <string>
#include <vector>
using std::string;

namespace md_parser {

enum TokenTypes {
  TEXT,
  LIST_ENUM,
  LIST_UNORDER,
  HEADER1,
  HEADER2,
  HEADER3,
  HEADER4,
  HEADER5,
  HEADER6,
  QUOTE,
  HORIZONTAL_LINE,
  CODE
};

struct HtmlFragments {
  enum Types { BOLD, ITALIC, TEXT, LINK, IMAGE, CODE } type;

  // Start and end are inclusive.
  int str_start;
  int str_end;

  int link_start;
  int link_end;

  HtmlFragments(Types t) : type(t) {}
  HtmlFragments(Types t, int start, int end)
      : type(t), str_start(start), str_end(end) {}
  HtmlFragments(Types t, int start, int end, int link_start, int link_end)
      : type(t),
        str_start(start),
        str_end(end),
        link_start(link_start),
        link_end(link_end) {}
};

// Class for the regular Text content.
class Content {
 protected:
  string content_;

 public:
  Content(const string& content);
  virtual string OutputHtml();

  // Continuation of the content.
  virtual void AddContent(const string& content);
  virtual ~Content(){};

 private:
  // Returns start_pos again if nothing is handled.
  size_t HandleLinks(size_t start_pos, std::vector<HtmlFragments>* fragments);
  size_t HandleImages(size_t start_pos, std::vector<HtmlFragments>* fragments);
  size_t HandleCodes(size_t start_pos, std::vector<HtmlFragments>* fragments);
};

}  // namespace md_parser
