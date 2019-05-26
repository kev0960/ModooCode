#ifndef BOOK_H
#define BOOK_H

#include <map>
#include <string>
#include <vector>

using std::string;

namespace md_parser {
enum BookType { C, CPP };

class BookManager {
 public:
  BookManager(BookType book_type,
              const std::map<string, std::map<string, string>>* file_info);

  void GenerateMainTex();
  bool IsBookFile(const string& filename);
  string GetBookType();

 private:
  BookType book_type_;
  const std::map<string, std::map<string, string>>* file_info_;

  std::vector<string> book_list_;
};

}  // namespace md_parser

#endif

