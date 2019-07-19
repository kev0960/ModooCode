#pragma once
#include <string>

#include "content.h"

using std::string;

namespace md_parser {

class ListContent : public Content {
 public:
  ListContent(const string& content, size_t index)
      : Content(content), index_(index), already_preprocessed_(false){};

  void Preprocess(ParserEnvironment* parser_env) override;
  void AddContent(const string& content) override;

 protected:
  size_t index_;

  bool should_start_new_list_tag_;
  std::vector<int> end_tags_;

  bool already_preprocessed_;
};

class EnumListContent : public ListContent {
 public:
  EnumListContent(const string& content, size_t index)
      : ListContent(content, index) {}

  string OutputHtml(ParserEnvironment* parser_env) override;
  string OutputLatex(ParserEnvironment* parser_env) override;

  TokenTypes GetContentType() const override { return TokenTypes::LIST_ENUM; }
};

class UnorderedListContent : public ListContent {
 public:
  UnorderedListContent(const string& content, size_t index)
      : ListContent(content, index) {}

  string OutputHtml(ParserEnvironment* parser_env) override;
  string OutputLatex(ParserEnvironment* parser_env) override;

  TokenTypes GetContentType() const override {
    return TokenTypes::LIST_UNORDER;
  }
};
}  // namespace md_parser
