#include "content_list.h"

#include <limits>
#include <vector>

#include "util.h"

namespace md_parser {
namespace {
string BuildEndTags(const std::vector<int>& end_tags) {
  string html;
  for (int tag : end_tags) {
    if (tag == 0) {
      html += "</ol>";
    } else if (tag == 1) {
      html += "</ul>";
    }
  }
  return html;
}

string BuildEndLatex(const std::vector<int>& end_tags) {
  string html;
  for (int tag : end_tags) {
    if (tag == 0) {
      html += "\n\\end{enumerate}\n";
    } else if (tag == 1) {
      html += "\n\\end{itemize}\n";
    }
  }
  return html;
}
}  // namespace

void ListContent::Preprocess(ParserEnvironment* parser_env) {
  // We just remember the choices.
  if (already_preprocessed_) {
    return;
  }
  already_preprocessed_ = true;

  should_start_new_list_tag_ = parser_env->ShouldStartNewListTag(index_);
  end_tags_ = parser_env->GetEndListTag(index_);
}

void ListContent::AddContent(const string& content) {
  // For newline inside of the list, it will enforce \newline
  content_ += ("\\newline{}" + content);
}

string EnumListContent::OutputHtml(ParserEnvironment* parser_env) {
  string output_html;
  Content::Preprocess(parser_env);

  // Decide whether to start with a new <ul>.
  if (should_start_new_list_tag_) {
    output_html += "<ol>";
  }

  output_html += StrCat("<li>", Content::OutputHtml(parser_env), "</li>");
  output_html += BuildEndTags(end_tags_);

  return output_html;
}

string EnumListContent::OutputLatex(ParserEnvironment* parser_env) {
  string output_tex;
  Content::Preprocess(parser_env);

  // Decide whether to start with a new <ul>.
  if (should_start_new_list_tag_) {
    output_tex += "\n\\begin{enumerate}";
  }
  output_tex += StrCat("\n\\item ", Content::OutputLatex(parser_env));
  output_tex += BuildEndLatex(end_tags_);
  return output_tex;
}

string UnorderedListContent::OutputHtml(ParserEnvironment* parser_env) {
  string output_html;
  Content::Preprocess(parser_env);

  // Decide whether to start with a new <ul>.
  if (should_start_new_list_tag_) {
    output_html += "<ul>";
  }
  output_html += StrCat("<li>", Content::OutputHtml(parser_env), "</li>");
  output_html += BuildEndTags(end_tags_);
  return output_html;
}

string UnorderedListContent::OutputLatex(ParserEnvironment* parser_env) {
  string output_tex;
  Content::Preprocess(parser_env);

  // Decide whether to start with a new <ul>.
  if (should_start_new_list_tag_) {
    output_tex += "\n\\begin{itemize}";
  }
  output_tex += StrCat("\n\\item ", Content::OutputLatex(parser_env));
  output_tex += BuildEndLatex(end_tags_);
  return output_tex;
}

}  // namespace md_parser
