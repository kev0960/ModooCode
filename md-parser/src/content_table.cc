#include "content_table.h"

#include "util.h"

namespace md_parser {

namespace {
bool ParseTableRow(const string& row, std::vector<Content>* elems) {
  if (row[0] != '|') {
    return false;
  }
  size_t current_start = 1;
  bool in_inline_code = false;
  for (size_t i = 1; i < row.size(); i++) {
    if (row[i] == '|' && !in_inline_code) {
      // (current_start ~ i - 1) is the string part.
      string elem = row.substr(current_start, i - current_start);
      Trim(&elem);
      elems->emplace_back(elem);
      current_start = i + 1;
    } else if (row[i] == '`') {
      in_inline_code = !in_inline_code;
    }
  }
  return true;
}

bool ParseTableRow(const string& row, std::vector<string>* elems) {
  if (row[0] != '|') {
    return false;
  }
  size_t current_start = 1;
  bool in_inline_code = false;
  for (size_t i = 1; i < row.size(); i++) {
    if (row[i] == '|' && !in_inline_code) {
      // (current_start ~ i - 1) is the string part.
      string elem = row.substr(current_start, i - current_start);
      Trim(&elem);
      elems->push_back(elem);
      current_start = i + 1;
    } else if (row[i] == '`') {
      in_inline_code = !in_inline_code;
    }
  }
  return true;
}

void ParseColumnStyle(const std::vector<string>& column_style_row,
                      std::vector<ColumnStyle>* column_style) {
  for (auto s : column_style_row) {
    if (s[0] == ':' && s.back() == ':') {
      column_style->push_back(ColumnStyle(ColumnStyle::ColumnAlign::MIDDLE));
    } else if (s[0] == ':') {
      column_style->push_back(ColumnStyle());
    } else if (s.back() == ':') {
      column_style->push_back(ColumnStyle(ColumnStyle::ColumnAlign::RIGHT));
    } else {
      column_style->push_back(ColumnStyle());
    }
  }
}

string GenerateTableRow(std::vector<Content>* row,
                        const std::vector<ColumnStyle>& column_styles,
                        ParserEnvironment* parser_env) {
  string html = "";
  html += "<tr>";
  size_t column_index = 0;
  for (auto& content : *row) {
    string column_class;
    if (column_index < column_styles.size()) {
      column_class = column_styles[column_index].GetClass();
    }
    if (!column_class.empty()) {
      content.Preprocess(parser_env);
      html += StrCat(R"(<td class=")", column_class,
                     R"(">)", content.OutputHtml(parser_env), "</td>");
    } else {
      content.Preprocess(parser_env);
      html += StrCat("<td>", content.OutputHtml(parser_env), "</td>");
    }
    column_index++;
  }
  html += "</tr>";
  return html;
}

string GenerateLatexTableRow(std::vector<Content>* row,
                             ParserEnvironment* parser_env) {
  string latex;
  int cnt = 0;
  for (auto& content : *row) {
    if (cnt == 0) {
      content.Preprocess(parser_env);
      latex += content.OutputLatex(parser_env);
    } else {
      content.Preprocess(parser_env);
      latex += StrCat(" & ", content.OutputLatex(parser_env));
    }
    cnt++;
  }
  latex += " \\\\ \\hline\n";
  return latex;
}

string GenerateTable(std::vector<std::vector<Content>>* table,
                     const std::vector<ColumnStyle>& column_styles,
                     ParserEnvironment* parser_env) {
  string html = "<table>";
  if (column_styles.empty()) {
    html += GenerateTableRow(&table->at(0), column_styles, parser_env);
  } else {
    int row_index = 0;
    for (auto& contents : *table) {
      if (row_index == 0) {
        html += "<thead>";
      }
      html += GenerateTableRow(&contents, column_styles, parser_env);
      if (row_index == 0) {
        html += "</thead><tbody>";
      }
      row_index++;
    }
    html += "</tbody>";
  }
  html += "</table>";
  return html;
}

}  // namespace
TableContent::TableContent(const string& line)
    : Content(""), already_preprocessed_(false) {
  table_rows_.push_back(line);
}

void TableContent::AddContent(const string& line) {
  table_rows_.push_back(line);
}

void TableContent::Preprocess(ParserEnvironment* parser_env) {
  if (already_preprocessed_) {
    return;
  }
  already_preprocessed_ = true;

  table_.reserve(table_rows_.size());

  // Parse the header.
  table_.push_back(std::vector<Content>());
  ParseTableRow(table_rows_[0], &table_.back());

  if (table_rows_.size() < 2) {
    return;
  }
  std::vector<string> column_style_row;
  ParseTableRow(table_rows_[1], &column_style_row);
  ParseColumnStyle(column_style_row, &column_styles_);

  for (size_t i = 2; i < table_rows_.size(); i++) {
    table_.push_back(std::vector<Content>());
    ParseTableRow(table_rows_[i], &table_.back());
  }
}

string TableContent::OutputHtml(ParserEnvironment* parser_env) {
  return GenerateTable(&table_, column_styles_, parser_env);
}

string TableContent::OutputLatex(ParserEnvironment* parser_env) {
  string latex = "\n\\begin{tabular}";
  if (column_styles_.empty()) {
    latex += GenerateLatexTableRow(&table_.at(0), parser_env);
  } else {
    latex += "{|";
    int cnt = 0;
    for (const auto& style : column_styles_) {
      if (cnt > 0) {
        latex += "|";
      }
      latex += style.GetAlignName();
      cnt++;
    }
    latex += "|}\n\\hline\n";
    for (auto& row : table_) {
      latex += GenerateLatexTableRow(&row, parser_env);
    }
  }
  latex += "\\end{tabular}\n";

  return latex;
}

}  // namespace md_parser
