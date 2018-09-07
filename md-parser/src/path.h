#include <experimental/optional>
#include <memory>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::experimental::optional;

namespace md_parser {
class PageStructure {
 public:
  PageStructure(bool is_root_page, const string& current_page_dir);
  bool ParsePathAndAdd(const string& page_path);
  string GetDirName() const;
  string DumpJson() const;
  std::vector<string> FlattenIntoVector() const;

 private:
  const bool is_root_page_;
  const string current_page_dir_;

  // Directories in current path.
  std::vector<std::unique_ptr<PageStructure>> child_dirs_;

  // Pages in current directory.
  std::set<string> pages_;
};

class PagePath {
 public:
  PagePath();
  bool AddPagePath(const string& page_path);

  string DumpPageStructureToJson();
  string GenerateSiteMap();

 private:
  std::unique_ptr<PageStructure> root_page_;
};

class PathReader {
 public:
  PathReader();
  PathReader(const std::unordered_map<string, string>& excluded_files);
  bool ReadAndBuildPagePath(const string& filename);
  string DumpPagePath();
  string GenerateSiteMap();

 private:
  std::unordered_map<string, string> excluded_files_;
  PagePath path_;
};

}  // namespace md_parser
