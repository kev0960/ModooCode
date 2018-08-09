#include "content.h"

namespace md_parser {
Content::Content(const string& content) : content_(content) { return; }

HeaderContent::HeaderContent(const string& content, TokenTypes token_type) : Content(content) {
  // Header type to the actual number of #s
  
}
}
