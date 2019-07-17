#include "content.h"

#include <unistd.h>

#include <cstdlib>
#include <fstream>
#include <functional>
#include <limits>
#include <memory>
#include <thread>
#include <unordered_set>

#ifdef USE_CHROMA
#include "chroma.h"
#endif

#include "fast_cpp_syntax_highlighter.h"
#include "fast_py_syntax_highlighter.h"
#include "tex_util.h"
#include "util.h"

static const std::unordered_set<string> kSpecialCommands = {"sidenote", "sc"};

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

void EscapeHtmlString(string* s) {
  for (size_t i = 0; i < s->length(); i++) {
    if (s->at(i) == '<') {
      s->replace(i, 1, "&lt;");
    } else if (s->at(i) == '>') {
      s->replace(i, 1, "&gt;");
    }
  }
}

[[maybe_unused]] std::unique_ptr<char[]> cstring_from_string(const string& s) {
  std::unique_ptr<char[]> c_str{new char[s.size() + 1]};
  for (size_t i = 0; i < s.size(); i++) {
    c_str[i] = s.at(i);
  }
  c_str[s.size()] = '\0';
  return c_str;
}

string GetHtmlFragmentText(const string& content, const Fragments& fragment,
                           bool is_str = true) {
  if (is_str) {
    return content.substr(fragment.str_start,
                          fragment.str_end - fragment.str_start + 1);
  }
  return content.substr(fragment.link_start,
                        fragment.link_end - fragment.link_start + 1);
}

string GetLatexFragmentText(const string& content, const Fragments& fragment,
                            bool is_str = true, bool no_escape = false) {
  if (is_str) {
    if (!no_escape) {
      return EscapeLatexString(content.substr(
          fragment.str_start, fragment.str_end - fragment.str_start + 1));
    } else {
      return content.substr(fragment.str_start,
                            fragment.str_end - fragment.str_start + 1);
    }
  }
  return content.substr(fragment.link_start,
                        fragment.link_end - fragment.link_start + 1);
}

#ifdef USE_CHROMA
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
#endif

void StripItguruFromLink(string* link) {
  const string itguru = "http://itguru.tistory.com";
  size_t itguru_pos = link->find(itguru);
  if (itguru_pos == string::npos) {
    return;
  }
  link->replace(itguru_pos, itguru.length(), "");
}

bool IsFileExist(const string& filename) {
  std::ifstream f(filename);
  return f.good();
}

bool CompareToken(const string& content_, int pos, const string& token) {
  if (pos + token.size() > content_.size()) {
    return false;
  }
  return content_.substr(pos, token.size()) == token;
}

}  // namespace

Content::Content(const string& content)
    : content_(content), already_preprocessed_(false) {
  return;
}

void Content::AddContent(const string& s) { content_ += s; }

void Content::Preprocess(ParserEnvironment* parser_env) {
  if (already_preprocessed_) {
    return;
  }
  GenerateFragments();
  already_preprocessed_ = true;
}

void Content::GenerateFragments() {
  // Priorities in processing content.
  //   Inline Code ( ` )
  //   Inline Math ( $$ )
  // ----------------------------------
  //   StrikeThrough (~)
  //   Bold (**, __)
  //   Italic (*, _)
  //     Note that when closing, whichever came first must close first.

  std::unordered_map<string, int> token_start_pos = {
      {"**", -1}, {"*", -1},  {"__", -1}, {"_", -1},
      {"`", -1},  {"$$", -1}, {"~~", -1}};

  std::unordered_map<string, Fragments::Types> token_and_type = {
      {"`", Fragments::Types::INLINE_CODE},
      {"$$", Fragments::Types::INLINE_MATH},
      {"~~", Fragments::Types::STRIKE_THROUGH},
      {"**", Fragments::Types::BOLD},
      {"__", Fragments::Types::BOLD},
      {"*", Fragments::Types::ITALIC},
      {"_", Fragments::Types::ITALIC}};

  // When one of following tokens are activated, it ignores anything that
  // comes after.
  std::vector<string> high_priorities = {"`", "$$"};

  // Following tokens can come play between each other.
  std::vector<string> low_priorities = {"~~", "**", "__", "*", "_"};

  int text_start = -1;

  // Now iterate through each character in the content and parse it.
  for (size_t i = 0; i < content_.size(); i++) {
    string activated_high_priority_token;
    for (const string& token : high_priorities) {
      if (token_start_pos.at(token) != -1) {
        activated_high_priority_token = token;
        break;
      }
    }

    // When high priority token is already activated, then we do not
    // proceed to process other token.
    if (!activated_high_priority_token.empty()) {
      if (CompareToken(content_, i, activated_high_priority_token)) {
        fragments_.emplace_back(token_and_type[activated_high_priority_token],
                                token_start_pos[activated_high_priority_token] +
                                    activated_high_priority_token.size(),
                                i - 1);
        token_start_pos[activated_high_priority_token] = -1;
        i += (activated_high_priority_token.size() - 1);
      }
      continue;
    }

    bool token_handled = false;
    for (const string& token : high_priorities) {
      if (CompareToken(content_, i, token)) {
        if (text_start != -1) {
          fragments_.emplace_back(Fragments::Types::TEXT, text_start, i - 1);
          text_start = -1;
        }
        token_start_pos[token] = i;
        token_handled = true;
        i += (token.size() - 1);
        break;
      }
    }

    if (token_handled) {
      continue;
    }

    // Handle links and images.
    std::vector<std::function<size_t(Content*, const size_t, int*)>> handlers =
        {&Content::HandleLinks, &Content::HandleImages,
         &Content::HandleSpecialCommands};

    bool handled = false;
    for (const auto& handler : handlers) {
      size_t result = handler(this, i, &text_start);
      if (result != i) {
        i = result;
        handled = true;
        break;
      }
    }
    if (handled) {
      continue;
    }

    // Now try to process low priority tokens.
    for (const string& token : low_priorities) {
      if (CompareToken(content_, i, token)) {
        token_handled = true;

        int token_start = token_start_pos[token];
        if (token_start == -1) {
          if (text_start != -1) {
            fragments_.emplace_back(Fragments::Types::TEXT, text_start, i - 1);
            text_start = -1;
          }
          fragments_.emplace_back(token_and_type[token]);

          token_start_pos[token] = i;
          i += (token.size() - 1);
        } else {
          // There is one edge case we have to care about.
          // When '**' is found, it is possible that it is actually two
          // separate '*' and '*'. The only case this is true is
          // '**' token came before '*' is entered.
          // E.g  **abc*c***
          //  ==> **abc*c* **  (1)
          //      *abc**c***
          //  ==> *abc**c** *  (2)

          if (text_start != -1) {
            fragments_.emplace_back(Fragments::Types::TEXT, text_start, i - 1);
            text_start = -1;
          }
          if (token.size() == 2) {
            string half_token = token.substr(0, 1);
            if (token_start < token_start_pos[half_token]) {
              // In this case we have to recognize token as a half token.
              // Note that this is the case (1).
              fragments_.emplace_back(token_and_type[half_token]);
              token_start_pos[half_token] = -1;
              i += (half_token.size() - 1);
            } else {
              fragments_.emplace_back(token_and_type[token]);
              token_start_pos[token] = -1;
              i += (token.size() - 1);
            }
          } else {
            fragments_.emplace_back(token_and_type[token]);
            token_start_pos[token] = -1;
            i += (token.size() - 1);
          }
          text_start = -1;
        }

        break;
      }
    }

    if (token_handled) {
      continue;
    }

    // Otherwise, it is a simple text token.
    if (text_start == -1) {
      text_start = i;
    }
  }

  // Handle last chunk of text_start (if exists).
  if (text_start != -1) {
    fragments_.emplace_back(Fragments::Types::TEXT, text_start,
                            content_.size() - 1);
  }
}

string Content::OutputHtml(ParserEnvironment* parser_env) {
  bool bold = false;
  bool italic = false;
  bool strike_through = false;

  string html = "<p>";
  for (size_t i = 0; i < fragments_.size(); i++) {
    if (fragments_[i].type == Fragments::Types::BOLD) {
      if (!bold) {
        html += "<span class='font-weight-bold'>";
      } else {
        html += "</span>";
      }
      bold = !bold;
    } else if (fragments_[i].type == Fragments::Types::ITALIC) {
      if (!italic) {
        html += "<span class='font-italic'>";
      } else {
        html += "</span>";
      }
      italic = !italic;
    } else if (fragments_[i].type == Fragments::Types::STRIKE_THROUGH) {
      if (!strike_through) {
        html += "<span class='font-strike'>";
      } else {
        html += "</span>";
      }
      strike_through = !strike_through;
    } else if (fragments_[i].type == Fragments::Types::SIDENOTE) {
      html +=
          StrCat("</p><aside class='sidenote'>",
                 GetHtmlFragmentText(content_, fragments_[i]), "</aside><p>");
    } else if (fragments_[i].type == Fragments::Types::SMALL_CAPS) {
      html += StrCat("<span class='font-smallcaps'>",
                     GetHtmlFragmentText(content_, fragments_[i]), "</span>");
    } else if (fragments_[i].type == Fragments::Types::LINK) {
      string url = GetHtmlFragmentText(content_, fragments_[i], false);
      StripItguruFromLink(&url);
      // If the link does not contain "http://", then this is a link that goes
      // back to our website.
      string link_text = GetHtmlFragmentText(content_, fragments_[i]);
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
    } else if (fragments_[i].type == Fragments::Types::IMAGE) {
      string img_src = GetHtmlFragmentText(content_, fragments_[i], false);

      // (alt) caption= (caption)
      string alt_and_caption = GetHtmlFragmentText(content_, fragments_[i]);
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

    } else if (fragments_[i].type == Fragments::Types::CODE) {
      html += StrCat("</p>", fragments_[i].formatted_code, "<p>");
    } else if (fragments_[i].type == Fragments::Types::INLINE_CODE) {
      string inline_code = GetHtmlFragmentText(content_, fragments_[i]);
      string ref_url = parser_env->GetUrlOfReference(&inline_code);
      EscapeHtmlString(&inline_code);
      if (!ref_url.empty()) {
        html += StrCat("<a href='", ref_url, "' class='link-code'>",
                       inline_code, "</a>");
      } else {
        html += StrCat("<code class='inline-code'>", inline_code, "</code>");
      }
    } else if (fragments_[i].type == Fragments::Types::INLINE_MATH) {
      html += StrCat("<span class='math-latex'>$",
                     GetHtmlFragmentText(content_, fragments_[i]), "$</span>");
    } else {
      string text = GetHtmlFragmentText(content_, fragments_[i]);
      EscapeHtmlString(&text);
      html += text;
    }
  }
  html += "</p>";
  RemoveEmptyPTag(&html);
  return html;
}

string Content::OutputLatex(ParserEnvironment* parser_env) {
  bool bold = false;
  bool italic = false;
  bool strike_through = false;

  string latex;
  for (const auto& fragment : fragments_) {
    if (fragment.type == Fragments::Types::BOLD) {
      if (!bold) {
        latex += "\\textbf{";
      } else {
        latex += "}";
      }
      bold = !bold;
    } else if (fragment.type == Fragments::Types::ITALIC) {
      if (!italic) {
        latex += "\\emph{";
      } else {
        latex += "}";
      }
      italic = !italic;
    } else if (fragment.type == Fragments::Types::STRIKE_THROUGH) {
      if (!strike_through) {
        // \usepackage[normalem]{ulem}
        latex += "\\sout{";
      } else {
        latex += "}";
      }
      strike_through = !strike_through;
    } else if (fragment.type == Fragments::Types::SIDENOTE) {
      /*
      latex += StrCat("\n\\begin{sidenotebox}\n",
                      GetLatexFragmentText(content_, fragment),
                      "\n\\end{sidenotebox}\n");
                      */
      latex += StrCat(" \\marginpar{\\footnotesize ",
                      GetLatexFragmentText(content_, fragment), "}\n");
    } else if (fragment.type == Fragments::Types::SMALL_CAPS) {
      latex +=
          StrCat("\\textsc{", GetLatexFragmentText(content_, fragment), "}");
    } else if (fragment.type == Fragments::Types::LINK) {
      // \usepackage{hyperref}
      string url = GetLatexFragmentText(content_, fragment, false);
      StripItguruFromLink(&url);
      // If the link does not contain "http://", then this is a link that goes
      // back to our website.
      string link_text = GetLatexFragmentText(content_, fragment);
      if (url.find("http") == string::npos) {
        string url = parser_env->GetUrlOfReference(&link_text);
        if (!url.empty()) {
          latex += StrCat("\\href{", url, "}{", link_text, "}");
          continue;
        }
      }
      latex += StrCat("\\href{", url, "}{", link_text, "}");
    } else if (fragment.type == Fragments::Types::IMAGE) {
      string img_src = GetLatexFragmentText(content_, fragment, false);

      // (alt) caption= (caption)
      string alt_and_caption = GetLatexFragmentText(content_, fragment);
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
      string ext = img_src.substr(img_src.size() - 3);
      if (ext == "gif" || ext == "svg") {
        img_src.erase(img_src.size() - 3);
        img_src.append("png");
      }
      if (caption.empty()) {
        latex += StrCat(
            "\n\\begin{figure}[H]\n\\centering\n\\includegraphics[max width="
            "0.7\\linewidth]{",
            img_src, "}\n\\end{figure}\n");
      } else {
        latex += StrCat(
            "\n\\begin{figure}[H]\n\\centering\n\\includegraphics[max width="
            "0.7\\linewidth]{",
            img_src, "}\n\\caption*{", caption, "}\n\\end{figure}\n");
      }
    } else if (fragment.type == Fragments::Types::INLINE_CODE) {
      string inline_code = GetLatexFragmentText(content_, fragment);
      latex += StrCat("\\texttt{", inline_code, "}");
    } else if (fragment.type == Fragments::Types::INLINE_MATH) {
      // Should use unescaped fragment text.
      latex += StrCat("$", GetHtmlFragmentText(content_, fragment), "$");
    } else {
      latex += GetLatexFragmentText(content_, fragment);
    }
  }
  return latex;
}

size_t Content::HandleLinks(const size_t start_pos, int* text_start) {
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
    fragments_.emplace_back(Fragments::Types::TEXT, *text_start, start_pos - 1);
    *text_start = -1;
  }
  fragments_.emplace_back(Fragments::Types::LINK, start_pos + 1,
                          end_bracket - 1, link_start + 1, link_end - 1);
  return link_end;
}

size_t Content::HandleSpecialCommands(const size_t start_pos, int* text_start) {
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
  if (!SetContains(kSpecialCommands, delimiter)) {
    return start_pos;
  }
  if (*text_start != -1) {
    fragments_.emplace_back(Fragments::Types::TEXT, *text_start, start_pos - 1);
    *text_start = -1;
  }
  if (delimiter == "sidenote") {
    fragments_.emplace_back(Fragments::Types::SIDENOTE, delimiter_pos + 1,
                            body_end - 1);
    return body_end;
  } else if (delimiter == "sc") {
    fragments_.emplace_back(Fragments::Types::SMALL_CAPS, delimiter_pos + 1,
                            body_end - 1);
    return body_end;
  }
  return start_pos;
}

size_t Content::HandleImages(const size_t start_pos, int* text_start) {
  if (content_[start_pos] != '!' || start_pos == content_.size() - 1) {
    return start_pos;
  }
  // Images are in exact same format as the links except for the starting !
  // symbol.
  size_t res = HandleLinks(start_pos + 1, text_start);
  if (res == start_pos + 1) return start_pos;

  // Need to change LINK to IMAGE.
  fragments_.back().type = Fragments::Types::IMAGE;
  return res;
}

}  // namespace md_parser
