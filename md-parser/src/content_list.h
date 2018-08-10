#pragma once
#include <string>
#include "content.h"

using std::string;

namespace md_parser {
class EnumListContent : public Content {
  int enum_cnt_;
  int enum_depth_;

 public:
  EnumListContent(const string& content, int enum_cnt, int enum_depth);
  string OutputHtml() override;
  void AddContent(const string& content) override;
};
}  // namespace md_parser
