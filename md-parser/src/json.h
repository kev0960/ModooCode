#include <fstream>
#include <map>
#include <string>
using std::string;

namespace md_parser {
class Json {
 public:
  Json(const string& filename);
  string JsonSerialize(const std::map<string, string>& m);
  string JsonSerialize(const std::map<string, std::map<string, string>>& m);
  void DumpJson(const string& s);

 private:
  const string filename_;
  std::ofstream out;
};
}
