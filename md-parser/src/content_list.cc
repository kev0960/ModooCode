#include "content_list.h"
#include <limits>
#include <vector>
#include "util.h"

namespace md_parser {

EnumListContent::EnumListContent(const string& content, int enum_cnt,
                                 int enum_depth)
    : Content(content), enum_cnt_(enum_cnt), enum_depth_(enum_depth) {}

string EnumListContent::OutputHtml() {
  return StrCat("<li>", Content::OutputHtml(), "</li>");
}

void EnumListContent::AddContent(const string& content) {}
}  // namespace md_parser
