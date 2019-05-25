#pragma once
#include "content.h"

namespace md_parser {

struct ColumnStyle {
  enum ColumnAlign { LEFT, MIDDLE, RIGHT };
  ColumnAlign align;
  ColumnStyle(ColumnAlign a = LEFT) : align(a) {}
  string GetClass() const {
    string class_names;
    if (align == MIDDLE) {
      class_names += "td-align-center ";
    } else if (align == RIGHT) {
      class_names += "td-align-right ";
    }
    if (class_names.size() > 0) {
      class_names.pop_back();
    }
    return class_names;
  }

  string GetAlignName() const {
    if (align == LEFT) {
      return "l";
    } else if (align == MIDDLE) {
      return "c";
    } else {
      return "r";
    }
  }
};

class TableContent : public Content {
 public:
  TableContent(const string& line);
  string OutputHtml(ParserEnvironment* parser_env) override;
  string OutputLatex(ParserEnvironment* parser_env) override;
  void Preprocess(ParserEnvironment* parser_env) override;

  void AddContent(const string& content) override;
  TokenTypes GetContentType() const override { return TokenTypes::TABLE; }

 private:
  std::vector<string> table_rows_;
  std::vector<ColumnStyle> column_styles_;

  std::vector<std::vector<Content>> table_;
};

}  // namespace md_parser
