#include "book.h"

#include <fstream>

#include "util.h"

namespace md_parser {
namespace {
struct Package {
  string package_name;
  string package_option;

  Package(const string& package_name, const string& package_option = "")
      : package_name(package_name), package_option(package_option) {}
};

string AddPackage(const Package& package) {
  if (package.package_option.empty()) {
    return StrCat("\\usepackage{", package.package_name, "}\n");
  } else {
    return StrCat("\\usepackage[", package.package_option, "]{",
                  package.package_name, "}\n");
  }
}

string AddBunchOfPackages(const std::vector<Package> package_list) {
  string tex;
  for (const auto& pkg : package_list) {
    tex += AddPackage(pkg);
  }
  return tex;
}

string BookTypeToDirName(BookType type) {
  switch (type) {
    case C:
      return "c";
    case CPP:
      return "cpp";
  }
  return "";
}
// Creates a tex comment in a following format
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// % some tex comment comes here %
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
string AddFancyComment(const string& comment) {
  string long_tex_comment(45, '%');
  long_tex_comment += "\n";

  string tex = "\n";
  tex.reserve(long_tex_comment.size() * 2 + comment.size());
  tex += long_tex_comment;
  tex += "% ";

  int current_line_len = 0;
  for (char c : comment) {
    current_line_len++;

    if (c == '\n') {
      tex.append(StrCat(string(43 - current_line_len, ' '), "%\n"));
      tex.append("% ");
      current_line_len = 0;
    } else {
      tex.push_back(c);
      if (current_line_len % 41 == 0) {
        tex.append(" %\n% ");
        current_line_len = 0;
      }
    }
  }
  if (current_line_len > 0) {
    tex.append(StrCat(string(42 - current_line_len, ' '), "%\n"));
  }
  tex += long_tex_comment;
  return tex;
}

}  // namespace

BookManager::BookManager(
    BookType book_type,
    const std::map<string, std::map<string, string>>* file_info)
    : book_type_(book_type), file_info_(file_info) {
  if (book_type_ == BookType::C) {
    book_list_.push_back("5");
  } else if (book_type_ == BookType::CPP) {
    book_list_.push_back("134");
  }

  // Create the list of included file names.
  while (true) {
    const auto& current_file = book_list_.back();
    const auto current_file_info_itr = file_info_->find(current_file);
    if (current_file_info_itr == file_info_->end()) {
      break;
    }
    const auto next_page_itr = current_file_info_itr->second.find("next_page");
    if (next_page_itr == current_file_info_itr->second.end()) {
      break;
    }
    book_list_.push_back(next_page_itr->second);
  }
}

void BookManager::GenerateMainTex() {
  string tex = "\\documentclass[a4paper, 10pt]{memoir}\n";
  std::vector<Package> package_list = {{"inputenc", "utf8"},
                                       {"lmodern"},
                                       {"minted"},
                                       {"ulem", "normalem"},
                                       {"kotex"},
                                       {"amsmath"},
                                       {"amssymb"},
                                       {"geometry"},
                                       {"listings"},
                                       {"xspace"},
                                       {"epigraph"},
                                       {"xcolor"},
                                       {"graphicx"},
                                       {"grffile"},
                                       {"pygmentize"},
                                       {"tcolorbox"},
                                       {"csquotes"},
                                       {"caption"},
                                       {"fancyvrb"},
                                       {"hyperref", "pdfencoding=auto"},
                                       {"titlesec"},
                                       {"verbatim"},
                                       {"spverbatim"},
                                       {"marginnote"},
                                       {"mdframed", "framemethod=TikZ"},
                                       {"fontenc", "T1"},
                                       {"adjustbox", "export"},
                                       {"beramono"}};
  tex += AddBunchOfPackages(package_list);

  // Relative path for all image files.
  tex += "\\graphicspath {{../../static/}}\n";

  // Define mdprogout
  tex += R"(
\newmdenv[%
    backgroundcolor=black!5,
    frametitlebackgroundcolor=black!10,
    roundcorner=5pt,
    skipabove=\topskip,
    innertopmargin=\topskip,
    splittopskip=\topskip,
    frametitle={실행 결과},
    frametitlerule=true,
    nobreak=false,
    usetwoside=false
]{mdprogout}
)";

  tex += R"(
\setminted[cpp]{
    frame=lines,
    framesep=2mm,
    baselinestretch=1.2,
    tabsize=2
}
)";

  tex += "\\begin{document}\n";
  // Add \include{filename}
  tex += AddFancyComment("List of book files.");
  for (const string& file_name : book_list_) {
    tex += StrCat("\\include{", file_name, "}\n");
  }

  tex += "\\end{document}";

  // Generate main.tex
  std::ofstream tex_out(
      StrCat("../book/", BookTypeToDirName(book_type_), "/main.tex"));
  tex_out << tex;
}

bool BookManager::IsBookFile(const string& filename) {
  for (const string& f : book_list_) {
    if (f == filename) return true;
  }
  return false;
}

string BookManager::GetBookType() { return BookTypeToDirName(book_type_); }

}  // namespace md_parser
