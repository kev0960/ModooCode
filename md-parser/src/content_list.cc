#include "content_list.h"

#include <limits>
#include <vector>

#include "util.h"

namespace md_parser {

void EnumListContent::Preprocess(ParserEnvironment* parser_env) {
  // We just remember the choices.
  if (already_preprocessed_) {
    return;
  }
  already_preprocessed_ = true;

  should_start_new_list_tag_ = parser_env->ShouldStartNewListTag();
  close_tag_count_ = parser_env->ShouldEndListTag();
}

string EnumListContent::OutputHtml(ParserEnvironment* parser_env) {
  string output_html;
  // Decide whether to start with a new <ul>.
  if (should_start_new_list_tag_) {
    output_html += "<ol>";
  }
  Content::Preprocess(parser_env);
  output_html += StrCat("<li>", Content::OutputHtml(parser_env), "</li>");
  int close_tag_count = close_tag_count_;
  while (close_tag_count) {
    output_html += "</ol>";
    close_tag_count--;
  }
  return output_html;
}

string EnumListContent::OutputLatex(ParserEnvironment* parser_env) {
  string output_tex;
  // Decide whether to start with a new <ul>.
  if (should_start_new_list_tag_) {
    output_tex += "\n\\begin{enumerate}";
  }
  Content::Preprocess(parser_env);
  output_tex += StrCat("\n\\item ", Content::OutputLatex(parser_env));
  int close_tag_count = close_tag_count_;
  while (close_tag_count) {
    output_tex += "\n\\end{enumerate}\n";
    close_tag_count--;
  }
  return output_tex;
}

void EnumListContent::AddContent(const string& content) { content_ += content; }

void UnorderedListContent::Preprocess(ParserEnvironment* parser_env) {
  // We just remember the choices.
  if (already_preprocessed_) {
    return;
  }
  already_preprocessed_ = true;

  should_start_new_list_tag_ = parser_env->ShouldStartNewListTag();
  close_tag_count_ = parser_env->ShouldEndListTag();
}

string UnorderedListContent::OutputHtml(ParserEnvironment* parser_env) {
  string output_html;
  // Decide whether to start with a new <ul>.
  if (should_start_new_list_tag_) {
    output_html += "<ul>";
  }
  Content::Preprocess(parser_env);
  output_html += StrCat("<li>", Content::OutputHtml(parser_env), "</li>");
  int close_tag_count = close_tag_count_;
  while (close_tag_count) {
    output_html += "</ul>";
    close_tag_count--;
  }
  return output_html;
}

string UnorderedListContent::OutputLatex(ParserEnvironment* parser_env) {
  string output_tex;
  // Decide whether to start with a new <ul>.
  if (should_start_new_list_tag_) {
    output_tex += "\n\\begin{itemize}";
  }
  Content::Preprocess(parser_env);
  output_tex += StrCat("\n\\item ", Content::OutputLatex(parser_env));
  int close_tag_count = close_tag_count_;
  while (close_tag_count) {
    output_tex += "\n\\end{itemize}\n";
    close_tag_count--;
  }
  return output_tex;
}

void UnorderedListContent::AddContent(const string& content) {
  content_ += content;
}
}  // namespace md_parser
