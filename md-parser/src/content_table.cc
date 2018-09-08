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
                        const std::vector<ColumnStyle>& column_styles) {
  string html = "";
  html += "<tr>";
  size_t column_index = 0;
  for (auto& content : *row) {
    string column_class;
    if (column_index < column_styles.size()) {
      column_class = column_styles[column_index].GetClass();
    }
    if (!column_class.empty()) {
      html += StrCat(R"(<td class=")", column_class,
                     R"(">)", content.OutputHtml(), "</td>");
    } else {
      html += StrCat("<td>", content.OutputHtml(), "</td>");
    }
    column_index++;
  }
  html += "</tr>";
  return html;
}

string GenerateTable(std::vector<std::vector<Content>>* table,
                     const std::vector<ColumnStyle>& column_styles) {
  string html = "<table>";
  if (column_styles.empty()) {
    html += GenerateTableRow(&table->at(0), column_styles);
  } else {
    int row_index = 0;
    for (auto& contents : *table) {
      if (row_index == 0) {
        html += "<thead>";
      }
      html += GenerateTableRow(&contents, column_styles);
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
TableContent::TableContent(const string& line) : Content("") {
  table_rows_.push_back(line);
}

void TableContent::AddContent(const string& line) {
  table_rows_.push_back(line);
}

string TableContent::OutputHtml() {
  std::vector<std::vector<Content>> table;
  table.reserve(table_rows_.size());

  // Parse the header.
  table.push_back(std::vector<Content>());
  ParseTableRow(table_rows_[0], &table.back());

  if (table_rows_.size() < 2) {
    return GenerateTable(&table, column_styles_);
  }
  std::vector<string> column_style_row;
  ParseTableRow(table_rows_[1], &column_style_row);
  ParseColumnStyle(column_style_row, &column_styles_);

  for (size_t i = 2; i < table_rows_.size(); i++) {
    table.push_back(std::vector<Content>());
    ParseTableRow(table_rows_[i], &table.back());
  }

  return GenerateTable(&table, column_styles_);
}

}  // namespace md_parser
