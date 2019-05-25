#include "content_box.h"

#include <unistd.h>

#include <thread>
#include <utility>

#include "fast_cpp_syntax_highlighter.h"
#include "fast_py_syntax_highlighter.h"
#include "tex_util.h"
#include "util.h"

static char kClangFormatName[] = "clang-format";
static char kClangFormatConfig[] = "-style=google";

namespace md_parser {
namespace {

string FormatCodeUsingFSH(const string& content, const string& code_type) {
  std::unique_ptr<FastSyntaxHighlighter> highlighter;
  if (code_type == "cpp") {
    highlighter =
        std::make_unique<FastCppSyntaxHighlighter>(content, code_type);
  } else {
    highlighter = std::make_unique<FastPySyntaxHighlighter>(content, code_type);
  }
  highlighter->ParseCode();
  highlighter->ColorMerge();
  return highlighter->GenerateHighlightedHTML();
}

void DoClangFormat(const string& code, string* formatted_code) {
  int pipe_p2c[2], pipe_c2p[2];
  if (pipe(pipe_p2c) != 0 || pipe(pipe_c2p) != 0) {
    LOG << "Pipe error!";
    return;
  }
  int pid = fork();
  if (pid < 0) {
    LOG << "Fork error!";
    return;
  }
  // Parent process;
  if (pid > 0) {
    // Close unused pipes.
    close(pipe_p2c[0]);
    close(pipe_c2p[1]);

    // Write the code we are trying to format.
    int result = write(pipe_p2c[1], code.c_str(), code.size());
    if (result == -1 || static_cast<size_t>(result) != code.size()) {
      LOG << "Error; STDOUT to clang format has not completed succesfully";
    }
    close(pipe_p2c[1]);

    // Retrieve the formatted code from the child process.

    // Clear the formatted code.
    formatted_code->clear();

    char buf[1024];
    int read_cnt;
    while ((read_cnt = read(pipe_c2p[0], buf, 1024)) > 0) {
      auto current_size = formatted_code->size();
      formatted_code->reserve(current_size + read_cnt + 1);
      for (int i = 0; i < read_cnt; i++) {
        formatted_code->push_back(buf[i]);
      }
    }
    close(pipe_c2p[0]);
  } else {
    // In child process, call execve into the clang format.

    // Close unused pipes.
    close(pipe_p2c[1]);
    close(pipe_c2p[0]);

    // Bind the input and output stream to the pipe.
    dup2(pipe_p2c[0], STDIN_FILENO);
    dup2(pipe_c2p[1], STDOUT_FILENO);

    close(pipe_p2c[0]);
    close(pipe_c2p[0]);

    char* clang_format_argv[] = {kClangFormatName, kClangFormatConfig, NULL};
    char* env[] = {NULL};
    int ret = execve("/usr/bin/clang-format", clang_format_argv, env);
    LOG << "CLANG FORMAT ERROR : " << ret;
  }
}

// Nbsp; 0xC2 0xA0 as a utf-8 format.
void RemoveNbsp(string* s) {
  for (size_t i = 0; i < s->size(); i++) {
    if (static_cast<unsigned char>(s->at(i)) == 0xc2 && i + 1 < s->size() &&
        static_cast<unsigned char>(s->at(i + 1)) == 0xa0) {
      s->erase(i, 2);
      i--;
    }
  }
}

void EscapeHtmlString(string* s) {
  for (size_t i = 0; i < s->length(); i++) {
    if (s->at(i) == '<') {
      s->replace(i, 1, "&lt;");
    } else if (s->at(i) == '>') {
      s->replace(i, 1, "&gt;");
    }
  }
}

void NewlineToBr(string* s) {
  size_t double_new_line = 0;
  while ((double_new_line = s->find("\n\n")) != string::npos) {
    s->replace(double_new_line, 2, "<br>\n");
  }
}

void NewlineToBrBr(string* s) {
  size_t double_new_line = 0;
  while ((double_new_line = s->find("\n\n")) != string::npos) {
    s->replace(double_new_line, 2, "<br><br>\n");
  }
}

string SplitNewlineToParagraph(const string& s) {
  std::vector<size_t> newline_pos;
  for (size_t i = 0; i < s.size(); i++) {
    if (s.at(i) == '\n') {
      newline_pos.push_back(i);
    }
  }

  // Merge adjacent newline pos.
  for (int i = 0; i < static_cast<int>(newline_pos.size()) - 1; i++) {
    if (newline_pos[i] + 1 == newline_pos[i + 1]) {
      newline_pos.erase(newline_pos.begin() + i + 1);
      i--;
    }
  }

  // Now Insert <p> tag.
  string inserted_str;
  int current = 0;
  for (int pos : newline_pos) {
    // Copy current ~ newline_pos - 1.
    inserted_str.append(s.substr(current, pos - current));
    inserted_str.append("</p><p>");
    current = pos + 1;
  }

  inserted_str.append(s.substr(current, s.size()));
  return inserted_str;
}

string SplitNewlineToItemize(const string& s) {
  std::vector<size_t> newline_pos;
  for (size_t i = 0; i < s.size(); i++) {
    if (s.at(i) == '\n') {
      newline_pos.push_back(i);
    }
  }

  // Merge adjacent newline pos.
  for (int i = 0; i < static_cast<int>(newline_pos.size()) - 1; i++) {
    if (newline_pos[i] + 1 == newline_pos[i + 1]) {
      newline_pos.erase(newline_pos.begin() + i + 1);
      i--;
    }
  }

  // Now Insert <p> tag.
  string inserted_str = "\n\\begin{itemize}\n";
  int current = 0;
  for (int pos : newline_pos) {
    // Copy current ~ newline_pos - 1.
    inserted_str.append("\n\\item ");
    inserted_str.append(s.substr(current, pos - current));
    current = pos + 1;
  }

  inserted_str.append(s.substr(current, s.size()));
  inserted_str.append("\n\\end{itemize}\n");
  return inserted_str;
}

}  // namespace

BoxContent::BoxContent(const string& content, const string& box_name)
    : Content(content) {
  if (box_name == "cpp") {
    box_type_ = BOX_CONTENT_TYPES::CPP_CODE;
  } else if (box_name == "cpp-formatted") {
    box_type_ = BOX_CONTENT_TYPES::CPP_FORMATTED_CODE;
  } else if (box_name == "py") {
    box_type_ = BOX_CONTENT_TYPES::PY_CODE;
  } else if (box_name == "info") {
    box_type_ = BOX_CONTENT_TYPES::INFO;
  } else if (box_name == "info-format") {
    box_type_ = BOX_CONTENT_TYPES::INFO_FORMAT;
  } else if (box_name == "info-text") {
    box_type_ = BOX_CONTENT_TYPES::INFO_TEXT;
  } else if (box_name == "exec") {
    box_type_ = BOX_CONTENT_TYPES::EXEC;
  } else if (box_name == "warning") {
    box_type_ = BOX_CONTENT_TYPES::WARNING;
  } else if (box_name == "code-warning") {
    box_type_ = BOX_CONTENT_TYPES::CODE_WARNING;
  } else if (box_name == "compiler-warning") {
    box_type_ = BOX_CONTENT_TYPES::COMPILER_WARNING;
  } else if (box_name == "lec-warning") {
    box_type_ = BOX_CONTENT_TYPES::LEC_WARNING;
  } else if (box_name == "lec-summary") {
    box_type_ = BOX_CONTENT_TYPES::LEC_SUMMARY;
  }
}

void BoxContent::Preprocess(ParserEnvironment* parser_env) {
  if (content_.size() == 0) {
    return;
  }

  // Remove the non-necessary endline at front.
  if (content_[0] == '\n') {
    content_.erase(0, 1);
  }

  switch (box_type_) {
    case CPP_CODE:
    case INFO_FORMAT:
    case CODE_WARNING:
      RemoveNbsp(&content_);
      DoClangFormat(content_, &content_);
    default:
      break;
  }
}

string BoxContent::OutputHtml(ParserEnvironment* parser_env) {
  // If the type of the box is code, then we do not parse it as
  // a Markdown text.
  switch (box_type_) {
    case CPP_CODE:
    case INFO_FORMAT:
    case CODE_WARNING:
    case COMPILER_WARNING:
    case INFO:
    case EXEC:
      EscapeHtmlString(&content_);
      break;
    default:
      break;
  }

  switch (box_type_) {
    case WARNING: {
      Content::Preprocess(parser_env);
      string output_html = Content::OutputHtml(parser_env);
      NewlineToBr(&output_html);
      return StrCat("<div class='warning warning-text'>", output_html,
                    "</div>");
    }
    case COMPILER_WARNING:
      return StrCat(
          "<p class='compiler-warning-title'><i class='xi-warning'></i>컴파일 "
          "오류</p><pre class='compiler-warning'>",
          content_, "</pre>");
    case INFO:
      return StrCat("<pre class='info'>", content_, "</pre>");
    case INFO_TEXT:
      Content::Preprocess(parser_env);
      return StrCat("<div class='info'>", Content::OutputHtml(parser_env),
                    "</div>");
    case EXEC:
      return StrCat(
          "<p class='exec-preview-title'>실행 결과</p><pre "
          "class='exec-preview'>",
          content_, "</pre>");
    case LEC_WARNING: {
      Content::Preprocess(parser_env);
      string output_html = Content::OutputHtml(parser_env);
      NewlineToBrBr(&output_html);
      return StrCat(
          "<p class='compiler-warning-title'><i class='xi-warning'></i>주의 "
          "사항</p><div class='lec-warning'>",
          output_html, "</div>");
    }
    case LEC_SUMMARY: {
      Content::Preprocess(parser_env);
      string output_html = Content::OutputHtml(parser_env);
      output_html = SplitNewlineToParagraph(output_html);
      return StrCat(
          "<div class='lec-summary'><h3>뭘 배웠지?</h3><div "
          "class='lec-summary-content'>",
          output_html, "</div></div>");
    }
    default:
      return content_;
  }
  return "";
}

string BoxContent::OutputLatex(ParserEnvironment* parser_env) {
  switch (box_type_) {
    case CPP_CODE:
    case INFO_FORMAT:
    case CODE_WARNING:
      RemoveNbsp(&content_);
      DoClangFormat(content_, &content_);
    case CPP_FORMATTED_CODE:
      content_ = FormatCodeUsingFSH(content_, "cpp");
      break;
    case PY_CODE:
      content_ = FormatCodeUsingFSH(content_, "py");
      break;
    case COMPILER_WARNING:
    case INFO:
    case EXEC:
      break;
    default:
      break;
  }

  switch (box_type_) {
    case CPP_CODE:
    case CPP_FORMATTED_CODE:
      return StrCat("\\begin{minted}{cpp}\n", content_, "\n\\end{minted}\n");
    case PY_CODE:
      return StrCat("\\begin{minted}{python}\n", content_, "\n\\end{minted}\n");
    case WARNING: {
      Content::Preprocess(parser_env);
      string output_tex = Content::OutputLatex(parser_env);
      return CreateTColorBox(output_tex, "red");
    }
    case COMPILER_WARNING: {
      Content::Preprocess(parser_env);
      string output_tex = EscapeLatexString(content_);
      return CreateTColorBox(output_tex, "red", "컴파일 오류");
    }
    case INFO: {
      Content::Preprocess(parser_env);
      string output_tex = EscapeLatexString(content_);
      return CreateTColorBox(output_tex, "green");
    }
    case INFO_TEXT: {
      Content::Preprocess(parser_env);
      return CreateTColorBox(Content::OutputLatex(parser_env), "green");
    }
    case EXEC:
      return StrCat("\\begin{mdprogout}\n\\begin{verbatim}", content_,
                    "\\end{verbatim}\n\\end{mdprogout}\n");
    case LEC_WARNING: {
      Content::Preprocess(parser_env);
      string output_tex = Content::OutputLatex(parser_env);
      return CreateTColorBox(output_tex, "red", "주의 사항");
    }
    case LEC_SUMMARY: {
      Content::Preprocess(parser_env);
      string output_tex = Content::OutputLatex(parser_env);
      return CreateTColorBox(SplitNewlineToItemize(output_tex), "blue",
                             "뭘 배웠지?");
    }
    default:
      return EscapeLatexString(content_);
  }
  return "";
}
void BoxContent::AddContent(const string& content) { content_ += content; }
}  // namespace md_parser
