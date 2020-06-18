#include "book.h"

#include <fstream>

#include "tex_util.h"
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
string AddFancyComment(const string& comment, const int comment_width = 55) {
  string long_tex_comment(comment_width, '%');
  long_tex_comment += "\n";

  string tex = "\n";
  tex.reserve(long_tex_comment.size() * 2 + comment.size());
  tex += long_tex_comment;
  tex += "% ";

  int current_line_len = 0;
  for (char c : comment) {
    current_line_len++;

    if (c == '\n') {
      tex.append(
          StrCat(string(comment_width - 2 - current_line_len, ' '), "%\n"));
      tex.append("% ");
      current_line_len = 0;
    } else {
      tex.push_back(c);
      if (current_line_len % (comment_width - 4) == 0) {
        tex.append(" %\n% ");
        current_line_len = 0;
      }
    }
  }
  if (current_line_len > 0) {
    tex.append(
        StrCat(string((comment_width - 3) - current_line_len, ' '), "%\n"));
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
    book_list_.push_back("135");
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
  string tex =
      "\\documentclass[a4paper, 11pt, oneside, chapter, nanum, "
      "footnote]{oblivoir}\n";
  std::vector<Package> package_list = {{"lmodern"},
                                       {"minted"},
                                       {"ulem", "normalem"},
                                       {"kotex", "hangul,nonfrench"},
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
                                       {"color"},
                                       {"beramono"},
                                       {"sourcecodepro"},
                                       {"hyphenat", "htt"},
                                       {"fancyhdr"},
                                       {"tocloft"},
                                       {"tabularx"},
                                       {"fapapersize"},{"pdfpages"}};

  tex += AddBunchOfPackages(package_list);

  // Set Fonts.
  // Check whether the font exists by luaotfload-tool --find="Nanum Gothic"
  tex += R"(
%\setkomainfont(Nanum Myeongjo)
%\setsansfont{Nanum Gothic}
\setmonofont{Source Code Pro}
\setsansfont{Myriad Pro}
)";

  // Add note for generating pygmentize.sty
  tex += AddFancyComment(
      "Note: To generate pygmentize.sty, use \npygmentize -S default -f tex > "
      "pygments.sty");

  // Relative path for all image files.
  tex += "\\graphicspath {{../../static/}}\n";

  // Define mdprogout and sidenote box.
  tex += R"(
\newmdenv[%
  backgroundcolor=black!5,
  frametitlebackgroundcolor=black!10,
  frametitlefont={\normalfont\sffamily\color{black}},
  roundcorner=5pt,
  skipabove=\topskip,
  innertopmargin=\topskip,
  splittopskip=\topskip,
  frametitle={실행 결과},
  frametitlerule=true,
  nobreak=false,
  usetwoside=false
]{mdprogout}

\newmdenv[%
  backgroundcolor=black!5,
  roundcorner=5pt,
  skipabove=\topskip,
  innertopmargin=\topskip,
  splittopskip=\topskip,
  nobreak=false,
  usetwoside=false
]{infoverb}

\newmdenv[%
  backgroundcolor=red!5!,
  frametitlebackgroundcolor=red!75!white,
  frametitlefont={\normalfont\sffamily\color{white}},
  roundcorner=5pt,
  skipabove=\topskip,
  innertopmargin=\topskip,
  splittopskip=\topskip,
  frametitle={컴파일 오류},
  frametitlerule=true,
  nobreak=false,
  usetwoside=false
]{mdcompilerwarning}

\newmdenv[leftline=false,rightline=false,font=\footnotesize]{sidenotebox}
)";

  tex += R"(
\setminted[cpp]{
  frame=single,
  framesep=1.5mm,
  baselinestretch=1.2,
  tabsize=2,
  fontsize=\footnotesize,
  breaklines
}
)";

  // Set Paragraph indent size and paragraph skip size.
  tex += R"(
\setlength{\parindent}{0em}
\setlength{\parskip}{0.5em}
)";

  // Adjust margin between lstlisting and tcolorbox.
  tex += R"(
\lstset{aboveskip=-0.5em,belowskip=-0.5em,basicstyle=\footnotesize\ttfamily,breaklines=true}
)";

  // Set header
  tex += R"(
\pagestyle{fancy}
\fancyhf{}
\renewcommand{\chaptermark}[1]{\markboth{#1}{#1}}
\fancyhead[LO]{\small\sffamily\nouppercase\leftmark}
\fancyhead[RO]{\small\sffamily\thepage}
\renewcommand{\headrulewidth}{0.4pt}
\renewcommand{\chaptername}{}
)";

  // Geometry
  tex += R"(
\usefapapersize{*,*,30mm,*,35mm,20mm}
)";

  // Chapter Style
  /*
  tex += R"(
%\chapterstyle{ell}
\renewcommand*{\chapterheadstart}{}
\renewcommand*{\printchapternum}{
  \chapnumfont 제 \thechapter ~장
}
\renewcommand*{\chapnumfont}{\normalfont\large\sffamily}
\renewcommand*{\chaptitlefont}{\normalfont\Huge\sffamily}
\renewcommand*{\midchapskip}{0.5cm}
\renewcommand*{\printchaptertitle}[1] {%
 \hrule \vspace{0.7cm} \chaptitlefont #1 \vspace{0.7cm} \hrule}
\renewcommand*{\printchaptername}{}
)";
*/

  // Section and subsection styles.
  tex += R"(
\titleformat*{\section}{\Huge\sffamily}
\titleformat*{\subsection}{\bfseries\huge\sffamily}
\titleformat*{\subsubsection}{\bfseries\large\sffamily}
)";

  // Spacing between lines.
  tex += R"(
\renewcommand{\baselinestretch}{1.3}
)";

  // Fixing minted spacing issue.
  tex += R"(
%\setlength\partopsep{-\topsep}
%\addtolength\partopsep{-\parskip}
%\addtolength\partopsep{0.3cm}
)";

  // Link color setup.
  tex += R"(
\hypersetup {colorlinks, linkcolor=red}
)";

  // TOC only shows up to the subsection.
  tex += R"(
\newcommand\chap[1]{%
  \chapter*{#1}%
  \addcontentsline{toc}{chapter}{#1}}
\setlength{\cftsubsecindent}{2cm}
\setlength{\cftsubsubsecindent}{4cm}
)";

  // Korean support.
  /*
  tex += R"(
\renewcommand{\chaptername}{제}
\renewcommand*{\afterchapternum}{ 장 \par\vspace{0.8cm}}
)";
*/
  // Font sizes
  tex += R"(
\setsecheadstyle{\bfseries\huge}
\renewcommand*{\marginfont}{\footnotesize}
)";

  // compiler-warning
  tex += R"(
\tcbuselibrary{minted, skins}
\newtcblisting{compilerwarning}[1][] {
  enhanded,
  breakable,
  listing engine=minted,
  colback=red!5!,
  colframe=red!75!black,
  title=컴파일 오류,
  left=3pt,
  right=3pt,
  listing only,
  minted language=text,
  minted options={breaklines, fontsize=\footnotesize, breaksymbolleft=}
}
)";

  // Set chapter style.
  tex += R"(
\makechapterstyle{obmadsen}{% requires graphicx package
  \chapterstyle{default}
%  \renewcommand*{\chapnamefont}{%
%    \normalfont\Large\scshape\raggedleft}
  \renewcommand*{\prechapternum}{\normalfont\Large\scshape\raggedleft}
  \renewcommand*{\postchapternum}{}
  \renewcommand*{\chaptitlefont}{%
    \normalfont\Huge\bfseries\sffamily\raggedleft}
  \renewcommand*{\chapternamenum}{}
  \renewcommand*{\printchapternum}{%
    \makebox[0pt][l]{\hspace{0.4em}
      \resizebox{!}{4ex}{%
        \chapnamefont\bfseries\sffamily\thechapter}
    }%
  }%
  \renewcommand*{\printchapternonum}{%
    \chapnamefont \phantom{\printchaptername \chapternamenum \printchapternum}
    \afterchapternum %
  }%
  \renewcommand*{\afterchapternum}{%
    \par\hspace{1.5cm}\hrule\vskip\midchapskip}}

\chapterstyle{obmadsen}
)";

  tex += "\\begin{document}\n";

  // Introduction page.
  tex += AddFancyComment("Introduction Page");
  tex += R"(
\thispagestyle{empty}
\includepdf{cover.pdf}

\thispagestyle{empty}
~\vfill
\noindent Copyright \textcopyright\  2019-2020 이재범

\noindent
이 책은 \textbf{모두의 코드}에 연재된 씹어먹는 C++ 강좌를 책으로 옮긴 것입니다. 해당 강좌는
 \url{https://modoocode.com} 에서 볼 수 있습니다.
\newpage
)";

  tex += "\\tableofcontents\n\\mainmatter\n";
  // Add \include{filename}
  tex += AddFancyComment("List of book files.");
  for (const string& file_name : book_list_) {
    auto chapter_itr = file_info_->at(file_name).find("chapter");
    if (chapter_itr != file_info_->at(file_name).end()) {
      string chapter = chapter_itr->second;
      chapter = EscapeLatexString(chapter);
      tex += StrCat("\n\\newpage\\chapter{", chapter, "}\n");
    }
    auto title_itr = file_info_->at(file_name).find("tex_title");
    if (title_itr != file_info_->at(file_name).end()) {
      string title = title_itr->second;
      title = EscapeLatexString(title);
      tex += StrCat("\n\\newpage\\section*{", title, "}\n");
      tex += StrCat("\\addcontentsline{toc}{section}{", title, "}\n");
    }
    tex += StrCat("\\input{", file_name, "}\n");
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
