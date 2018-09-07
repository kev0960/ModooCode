#pragma once
#include <string>
#include "content.h"

using std::string;

namespace md_parser {

class ListContent : public Content {
 public:
  ListContent(const string& content, int depth)
      : Content(content), depth_(depth){};
  int GetDepth() const { return depth_; }

 protected:
  int depth_;
};

class EnumListContent : public ListContent {
 public:
  EnumListContent(const string& content, int enum_depth)
      : ListContent(content, enum_depth) {}

  string OutputHtml() override;
  string OutputHtml(ParserEnvironment* parser_env) override;
  void AddContent(const string& content) override;
  TokenTypes GetContentType() const override { return TokenTypes::LIST_ENUM; }
};

class UnorderedListContent : public ListContent {
 public:
  UnorderedListContent(const string& content, int list_depth)
      : ListContent(content, list_depth) {}
  string OutputHtml() override;
  string OutputHtml(ParserEnvironment* parser_env) override;
  void AddContent(const string& content) override;
  TokenTypes GetContentType() const override {
    return TokenTypes::LIST_UNORDER;
  }
};
}  // namespace md_parser
