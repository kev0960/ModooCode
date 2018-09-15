#pragma once

namespace md_parser {

enum TokenTypes {
  TEXT,
  LIST_ENUM,
  LIST_UNORDER,
  HEADER,  // General Header
  HEADER1,
  HEADER2,
  HEADER3,
  HEADER4,
  HEADER5,
  HEADER6,
  QUOTE,
  HORIZONTAL_LINE,
  CODE,
  NEWLINE,
  TABLE,
  MATH
};
}
