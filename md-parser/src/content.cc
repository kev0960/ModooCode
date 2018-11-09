#include "content.h"

#include <unistd.h>

#include <cstdlib>
#include <fstream>
#include <functional>
#include <limits>
#include <memory>
#include <thread>
#include <unordered_set>

#include "chroma.h"
#include "fast_cpp_syntax_highlighter.h"
#include "util.h"

static char kClangFormatName[] = "clang-format";
static char kClangFormatConfig[] = "-style=google";
static const std::unordered_set<string> kSpecialCommands = {"sidenote"};

namespace md_parser {

namespace {

// Remove empty p tags. (e.g <p>  </p>).
void RemoveEmptyPTag(string* s) {
  for (size_t i = 0; i < s->size(); i++) {
    if (s->at(i) == '<') {
      if (i + 2 < s->size() && s->substr(i, 3) == "<p>") {
        size_t p_tag_start = i;
        i += 3;

        // Ignore whitespaces (tab and space).
        while (s->at(i) == ' ' || s->at(i) == '\t') {
          i++;
        }
        if (i + 3 < s->size() && s->substr(i, 4) == "</p>") {
          s->erase(p_tag_start, (i + 4) - p_tag_start);
          i = p_tag_start - 1;
        }
      }
    }
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

// Return how many matches.
int FindOneOrTwoConsecutiveChar(const string& s, size_t start, char c) {
  if (s[start] == c) {
    if (start + 1 < s.size() && s[start + 1] == c) {
      return 2;
    }
    return 1;
  }
  return 0;
}

std::unique_ptr<char[]> cstring_from_string(const string& s) {
  std::unique_ptr<char[]> c_str{new char[s.size() + 1]};
  for (size_t i = 0; i < s.size(); i++) {
    c_str[i] = s.at(i);
  }
  c_str[s.size()] = '\0';
  return c_str;
}

string GetHtmlFragmentText(const string& content, const HtmlFragments& fragment,
                           bool is_str = true) {
  if (is_str) {
    return content.substr(fragment.str_start,
                          fragment.str_end - fragment.str_start + 1);
  }
  return content.substr(fragment.link_start,
                        fragment.link_end - fragment.link_start + 1);
}
[[maybe_unused]] string FormatCodeUsingChroma(const string& code,
                                              const string& lang,
                                              const string& schema) {
  auto code_ = cstring_from_string(code);
  auto lang_ = cstring_from_string(lang);
  auto schema_ = cstring_from_string(schema);

  char* formatted =
      FormatCodeWithoutInlineCss(code_.get(), lang_.get(), schema_.get());
  string formatted_code = formatted;
  free(formatted);

  return formatted_code;
}

string FormatCodeUsingFSH(const string& content) {
  FastCppSyntaxHighlighter highlighter(content);
  highlighter.ParseCode();
  highlighter.ColorMerge();
  return highlighter.GenerateHighlightedHTML();
}

void StripItguruFromLink(string* link) {
  const string itguru = "http://itguru.tistory.com";
  size_t itguru_pos = link->find(itguru);
  if (itguru_pos == string::npos) {
    return;
  }
  link->replace(itguru_pos, itguru.length(), "");
}

string OutputLinksInBox(const string& box_str) {
  string output_html;
  output_html.reserve(box_str.size());
  for (size_t i = 0; i < box_str.size(); i++) {
    if (box_str[i] == '[') {
      size_t end_bracket = box_str.find(']', i + 1);
      if (end_bracket == string::npos) {
        goto handle_normal_char;
      }
      size_t link_start = end_bracket + 1;
      if (box_str[link_start] != '(') {
        goto handle_normal_char;
      }
      size_t link_end = box_str.find(')', link_start + 1);
      if (link_end == string::npos) {
        goto handle_normal_char;
      }
      string link = box_str.substr(link_start + 1, link_end - (link_start + 1));
      StripItguruFromLink(&link);
      const string text = box_str.substr(i + 1, end_bracket - (i + 1));
      output_html += StrCat(R"(<a href=")", link, R"(">)", text, "</a>");
      i = link_end;
      continue;
    }
  handle_normal_char:
    output_html.push_back(box_str[i]);
  }
  return output_html;
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
    char buf[100];
    int read_cnt;
    while ((read_cnt = read(pipe_c2p[0], buf, 100)) > 0) {
      auto current_size = formatted_code->size();
      formatted_code->reserve(current_size + read_cnt + 1);
      for (int i = 0; i < read_cnt; i++) {
        formatted_code->push_back(buf[i]);
      }
    }
    close(pipe_c2p[0]);
    // *formatted_code = FormatCodeUsingChroma(*formatted_code, "cpp",
    // "github");
    *formatted_code = FormatCodeUsingFSH(*formatted_code);
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

bool IsFileExist(const string& filename) {
  std::ifstream f(filename);
  return f.good();
}

}  // namespace

Content::Content(const string& content) : content_(content) { return; }

void Content::AddContent(const string& s) { content_ += s; }

string Content::OutputHtml(ParserEnvironment* parser_env) {
  // When both not defined :
  //  Neither of bold_start < italic_start nor bold_start > italic_start
  // When only one of them are defined :
  //  (defined one) < (not defined one)
  // When both are defined :
  //  (earlier one) < (later one)
  const int int_max = std::numeric_limits<int>::max();
  int bold_start = int_max;
  int italic_start = int_max;
  int code_start = -1;
  int math_start = -1;

  int text_start = -1;
  std::vector<HtmlFragments> fragments;

  std::vector<std::function<size_t(Content*, const size_t,
                                   std::vector<HtmlFragments>*, int*)>>
      handlers = {&Content::HandleLinks, &Content::HandleImages,
                  &Content::HandleCodes, &Content::HandleSpecialCommands};
  // Any unescaped * or _ are considered as a format token.
  for (size_t i = 0; i < content_.size(); i++) {
    // Inline code escapes everything except `.
    if (code_start != -1) {
      if (content_[i] == '`') {
        fragments.push_back(HtmlFragments(HtmlFragments::Types::INLINE_CODE,
                                          code_start, i - 1));
        code_start = -1;
      }
      continue;
    }
    if (math_start != -1) {
      if (content_[i] == '$' && i + 1 < content_.size() &&
          content_[i + 1] == '$') {
        fragments.push_back(
            HtmlFragments(HtmlFragments::Types::INLINE_MATH, math_start, i));
        math_start = -1;
        i += 1;
      }
      continue;
    }
    bool handled = false;
    for (const auto& handler : handlers) {
      size_t result = handler(this, i, &fragments, &text_start);
      if (result != i) {
        i = result;
        handled = true;
        break;
      }
    }
    if (handled) continue;

    // Handles Bold, Italic, Strikethroughs here.
    int matches = Max(FindOneOrTwoConsecutiveChar(content_, i, '*'),
                      FindOneOrTwoConsecutiveChar(content_, i, '_'),
                      FindOneOrTwoConsecutiveChar(content_, i, '~'),
                      FindOneOrTwoConsecutiveChar(content_, i, '`'),
                      FindOneOrTwoConsecutiveChar(content_, i, '$'));

    if (matches == 0) {
      if (text_start == -1) {
        text_start = i;
      }
    } else {
      // Since tilde (~) is ignored.
      if (matches == 1 && content_[i] == '~') continue;
      if (matches == 1 && content_[i] == '`') {
        if (text_start != -1) {
          fragments.push_back(
              HtmlFragments(HtmlFragments::Types::TEXT, text_start, i - 1));
          text_start = -1;
        }
        if (code_start == -1) {
          code_start = i + 1;
        } else {
          LOG << "Inline Code Error :: code start is " << code_start;
        }
        continue;
      }
      // Inline math.
      if (matches == 2 && content_[i] == '$') {
        if (text_start != -1) {
          fragments.push_back(
              HtmlFragments(HtmlFragments::Types::TEXT, text_start, i - 1));
          text_start = -1;
        }
        if (math_start == -1) {
          math_start = i + 1;
        } else {
          LOG << "Inline Math Error :: math start is " << math_start;
        }
        continue;
      }
      // Mark the end of the text segment.
      if (text_start != -1) {
        fragments.push_back(
            HtmlFragments(HtmlFragments::Types::TEXT, text_start, i - 1));
        text_start = -1;
      }
      if (matches == 2) {
        // If italic * is defined later than the defined italic, then we only
        // read one *.
        if (bold_start < italic_start && italic_start != int_max) {
          italic_start = int_max;
          fragments.push_back(HtmlFragments(HtmlFragments::Types::ITALIC));
        } else {
          bold_start = (bold_start == int_max ? i : int_max);
          fragments.push_back(HtmlFragments(HtmlFragments::Types::BOLD));
          i++;
        }
      } else if (matches == 1) {
        italic_start = (italic_start == int_max ? i : int_max);
        if (text_start != -1) {
          fragments.push_back(
              HtmlFragments(HtmlFragments::Types::TEXT, text_start, i - 1));
          text_start = -1;
        }
        fragments.push_back(HtmlFragments(HtmlFragments::Types::ITALIC));
      }
    }
  }
  if (text_start != -1) {
    fragments.push_back(HtmlFragments(HtmlFragments::Types::TEXT, text_start,
                                      content_.size() - 1));
  }

  // Now we have to generate formatted html.

  // First Format all the code.
  ClangFormatEntireCode(&fragments);
  bool bold = false;
  bool italic = false;
  string html = "<p>";
  for (size_t i = 0; i < fragments.size(); i++) {
    if (fragments[i].type == HtmlFragments::Types::BOLD) {
      if (!bold)
        html += "<span class='font-weight-bold'>";
      else
        html += "</span>";
      bold = !bold;
    } else if (fragments[i].type == HtmlFragments::Types::ITALIC) {
      if (!italic)
        html += "<span class='font-italic'>";
      else
        html += "</span>";
      italic = !italic;
    } else if (fragments[i].type == HtmlFragments::Types::SIDENOTE) {
      html +=
          StrCat("</p><aside class='sidenote'>",
                 GetHtmlFragmentText(content_, fragments[i]), "</aside><p>");
    } else if (fragments[i].type == HtmlFragments::Types::LINK) {
      string url = GetHtmlFragmentText(content_, fragments[i], false);
      StripItguruFromLink(&url);
      // If the link does not contain "http://", then this is a link that goes
      // back to our website.
      string link_text = GetHtmlFragmentText(content_, fragments[i]);
      if (url.find("http") == string::npos) {
        string url = parser_env->GetUrlOfReference(&link_text);
        EscapeHtmlString(&link_text);
        if (!url.empty()) {
          html += StrCat("<a href='", url, "' class='link-code'>", link_text,
                         "</a>");
          continue;
        }
      }
      html += StrCat("<a href='", url, "'>", link_text, "</a>");
    } else if (fragments[i].type == HtmlFragments::Types::IMAGE) {
      string img_src = GetHtmlFragmentText(content_, fragments[i], false);

      // (alt) caption= (caption)
      string alt_and_caption = GetHtmlFragmentText(content_, fragments[i]);
      string caption, alt;
      auto caption_pos = alt_and_caption.find("caption=");
      if (caption_pos != string::npos) {
        caption = alt_and_caption.substr(caption_pos + 8);
        alt = alt_and_caption.substr(caption_pos);
      } else {
        alt = alt_and_caption;
      }

      // If this image is from old tistory dump, then we have to switch to the
      // local iamge.
      if (img_src.find("http://img1.daumcdn.net") != string::npos) {
        auto id_start = img_src.find("image%2F");
        if (id_start == string::npos) {
          LOG << "Daum Image URL is weird";
        } else {
          id_start += 8;
          const string image_name = img_src.substr(id_start);
          std::vector<string> file_ext_candidate = {".png", ".jpg", ".jpeg",
                                                    ".gif"};
          for (const auto& ext : file_ext_candidate) {
            if (IsFileExist(StrCat("../static/img/", image_name, ext))) {
              img_src = StrCat("/img/", image_name, ext);
              break;
            }
          }
        }
      }
      // Check webp version exist. If exists, then we use picture tag instead.
      auto image_name_end = img_src.find_last_of(".");
      if (image_name_end != string::npos) {
        const string webp_image_name =
            img_src.substr(0, image_name_end) + ".webp";
        if (IsFileExist("../static" + webp_image_name)) {
          html += StrCat(
              R"(</p><figure><picture><source type="image/webp" srcset=")",
              webp_image_name, R"("><img class="content-img" src=")", img_src,
              R"(" alt=")", alt,
              R"("></picture><figcaption>)", caption,
              R"(</figcaption></figure><p>)");
          continue;
        }
      }
      html += StrCat("</p><figure><img class='content-img' src='", img_src,
                     "' alt='", alt, "'><figcaption>", caption,
                     "</figcaption></figure><p>");

    } else if (fragments[i].type == HtmlFragments::Types::CODE) {
      html += StrCat("</p>", fragments[i].formatted_code, "<p>");
    } else if (fragments[i].type == HtmlFragments::Types::INLINE_CODE) {
      string inline_code = GetHtmlFragmentText(content_, fragments[i]);
      string ref_url = parser_env->GetUrlOfReference(&inline_code);
      EscapeHtmlString(&inline_code);
      if (!ref_url.empty()) {
        html += StrCat("<a href='", ref_url, "' class='link-code'>",
                       inline_code, "</a>");
      } else {
        html += StrCat("<code class='inline-code'>", inline_code, "</code>");
      }
    } else if (fragments[i].type == HtmlFragments::Types::INLINE_MATH) {
      html += StrCat("<span class='math-latex'>",
                     GetHtmlFragmentText(content_, fragments[i]), "</span>");
    } else {
      html += GetHtmlFragmentText(content_, fragments[i]);
    }
  }
  html += "</p>";
  RemoveEmptyPTag(&html);
  return html;
}

size_t Content::HandleLinks(const size_t start_pos,
                            std::vector<HtmlFragments>* fragments,
                            int* text_start) {
  if (content_[start_pos] != '[') {
    return start_pos;
  }

  // Search for the ending ']'.
  size_t end_bracket = content_.find(']', start_pos);
  if (end_bracket == string::npos) return start_pos;
  if (end_bracket + 1 >= content_.size() || content_[end_bracket + 1] != '(') {
    return start_pos;
  }
  size_t link_start = end_bracket + 1;
  size_t link_end = content_.find(')', link_start);
  if (link_end == string::npos) return start_pos;
  if (*text_start != -1) {
    fragments->push_back(
        HtmlFragments(HtmlFragments::Types::TEXT, *text_start, start_pos - 1));
    *text_start = -1;
  }
  fragments->push_back(HtmlFragments(HtmlFragments::Types::LINK, start_pos + 1,
                                     end_bracket - 1, link_start + 1,
                                     link_end - 1));
  return link_end;
}

size_t Content::HandleSpecialCommands(const size_t start_pos,
                                      std::vector<HtmlFragments>* fragments,
                                      int* text_start) {
  if (content_[start_pos] != '\\') {
    return start_pos;
  }
  const auto delimiter_pos = content_.find("{", start_pos + 1);
  if (delimiter_pos == string::npos) {
    return start_pos;
  }
  const auto body_end = content_.find("}", delimiter_pos + 1);
  if (body_end == string::npos) {
    return start_pos;
  }
  const auto delimiter =
      content_.substr(start_pos + 1, delimiter_pos - (start_pos + 1));
  if (!Contains(kSpecialCommands, delimiter)) {
    return start_pos;
  }
  if (*text_start != -1) {
    fragments->push_back(
        HtmlFragments(HtmlFragments::Types::TEXT, *text_start, start_pos - 1));
    *text_start = -1;
  }
  if (delimiter == "sidenote") {
    fragments->push_back(HtmlFragments(HtmlFragments::Types::SIDENOTE,
                                       delimiter_pos + 1, body_end - 1));
    return body_end;
  }
  return start_pos;
}

size_t Content::HandleImages(const size_t start_pos,
                             std::vector<HtmlFragments>* fragments,
                             int* text_start) {
  if (content_[start_pos] != '!' || start_pos == content_.size() - 1)
    return start_pos;
  // Images are in exact same format as the links except for the starting !
  // symbol.
  size_t res = HandleLinks(start_pos + 1, fragments, text_start);
  if (res == start_pos + 1) return start_pos;

  // Need to change LINK to IMAGE.
  fragments->back().type = HtmlFragments::Types::IMAGE;
  return res;
}

size_t Content::HandleCodes(const size_t start_pos,
                            std::vector<HtmlFragments>* fragments,
                            int* text_start) {
  if (start_pos + 2 >= content_.size() ||
      content_.substr(start_pos, 3) != "```") {
    return start_pos;
  }
  // Need to find the code style.
  size_t first_white_space =
      FindFirstOfAny(content_, start_pos, " \n") - content_.begin();
  const string code_style =
      content_.substr(start_pos + 3, first_white_space - (start_pos + 3));

  size_t code_start = first_white_space + 1;
  size_t code_end;
  if ((code_end = content_.find("```", code_start)) == string::npos) {
    return start_pos;
  }

  code_end--;
  if (*text_start != -1) {
    fragments->push_back(HtmlFragments(HtmlFragments::Types::TEXT, *text_start,
                                       start_pos - 1, code_style));
    *text_start = -1;
  }
  fragments->push_back(HtmlFragments(HtmlFragments::Types::CODE, code_start,
                                     code_end, code_style));
  return code_end + 3;
}

void Content::ClangFormatEntireCode(std::vector<HtmlFragments>* fragments) {
  std::vector<std::thread> format_ops;

  for (size_t i = 0; i < fragments->size(); i++) {
    auto& fragment = fragments->at(i);
    if (fragment.type == HtmlFragments::Types::CODE) {
      if (fragment.code_style == "warning") {
        string warning_str = content_.substr(
            fragment.str_start, fragment.str_end - fragment.str_start);
        EscapeHtmlString(&warning_str);
        fragment.formatted_code = StrCat(
            "<pre class='warning'>", OutputLinksInBox(warning_str), "</pre>");
      } else if (fragment.code_style == "info") {
        string info_str = content_.substr(
            fragment.str_start, fragment.str_end - fragment.str_start);
        EscapeHtmlString(&info_str);
        fragment.formatted_code =
            StrCat("<pre class='info'>", OutputLinksInBox(info_str), "</pre>");
      } else if (fragment.code_style == "exec") {
        string info_str = content_.substr(
            fragment.str_start, fragment.str_end - fragment.str_start);
        EscapeHtmlString(&info_str);
        fragment.formatted_code = StrCat("<pre class='exec-preview'>",
                                         OutputLinksInBox(info_str), "</pre>");
      } else if (fragment.code_style == "cpp-formatted") {
        string formatted_code = content_.substr(
            fragment.str_start, fragment.str_end - fragment.str_start + 1);
        formatted_code = FormatCodeUsingFSH(formatted_code);
        fragment.formatted_code = formatted_code;
      } else if (fragment.code_style != "cpp" &&
                 fragment.code_style != "info_format") {
        string unformatted_code = content_.substr(
            fragment.str_start, fragment.str_end - fragment.str_start + 1);
        fragment.formatted_code = unformatted_code;
      } else {
        // Sometimes the code contains NBSP character. This hinders the code to
        // be correctly formatted by the clang-format.
        string unformatted_code = content_.substr(
            fragment.str_start, fragment.str_end - fragment.str_start + 1);
        RemoveNbsp(&unformatted_code);
        format_ops.push_back(std::thread(DoClangFormat, unformatted_code,
                                         &fragment.formatted_code));
      }
    }
  }
  for (auto& t : format_ops) {
    t.join();
  }
}

}  // namespace md_parser
