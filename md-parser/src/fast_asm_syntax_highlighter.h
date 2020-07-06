#pragma once

#include "fast_syntax_highlighter.h"

namespace md_parser {

class FastAsmSyntaxHighlighter : public FastSyntaxHighlighter {
 public:
  enum ASM_SYNTAX { INTEL, AT_T };
  FastAsmSyntaxHighlighter(const string& code, const string& language,
                           ASM_SYNTAX asm_syntax)
      : FastSyntaxHighlighter(code, language), asm_syntax_(asm_syntax) {
    class_to_style_map_.insert({"in", {{"color", "#6dbeff"}}});
    class_to_style_map_.insert({"rg", {{"color", "#78dce8"}}});
    class_to_style_map_.insert({"u", {{"color", "#b26a2f"}}});
    class_to_style_map_.insert({"lb", {{"color", "#f19798"}}});
    class_to_style_map_.insert({"dr", {{"color", "#ff3133"}}});
  }

  bool ParseCode() override;

 private:
  bool ParseLine(size_t line_start, size_t line_end);
  void AppendCurrentToken(SyntaxTokenType current_token, size_t token_start,
                          size_t token_end, int* identifier_index);

  ASM_SYNTAX asm_syntax_;
};

}  // namespace md_parser
