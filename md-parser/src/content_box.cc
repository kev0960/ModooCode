#include "content_box.h"

#include <unistd.h>

#include <thread>
#include <utility>

#include "fast_cpp_syntax_highlighter.h"
#include "fast_py_syntax_highlighter.h"
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
  } else if (box_name == "summary") {
    box_type_ = BOX_CONTENT_TYPES::SUMMARY;
  }
}

string BoxContent::OutputHtml(ParserEnvironment* parser_env) {
  // Remove the non-necessary endline at front.
  if (content_[0] == '\n') {
    content_.erase(0, 1);
  }

  // If the type of the box is code, then we do not parse it as
  // a Markdown text.
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
      EscapeHtmlString(&content_);
      break;
    default:
      break;
  }

  switch (box_type_) {
    case WARNING: {
      string output_html = Content::OutputHtml(parser_env);
      NewlineToBr(&output_html);
      return StrCat("<div class='warning warning-text'>", output_html,
                    "</div>");
    }
    case COMPILER_WARNING:
      return StrCat("<pre class='warning'>", content_, "</pre>");
    case INFO:
      return StrCat("<pre class='info'>", content_, "</pre>");
    case INFO_TEXT:
      return StrCat("<div class='info'>", Content::OutputHtml(parser_env),
                    "</div>");
    case EXEC:
      return StrCat("<pre class='exec-preview'>", content_, "</pre>");
    case SUMMARY:
      return StrCat("<div class='summary'>", Content::OutputHtml(parser_env),
                    "</div>");
    default:
      return content_;
  }
  return "";
}

void BoxContent::AddContent(const string& content) { content_ += content; }
}  // namespace md_parser
