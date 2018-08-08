#pragma once
#include <string>

namespace md_parser {
class Content {
  std::string content_;

 public:
  Content(std::string content);
  virtual std::string OutputHtml() = 0;
};
}
