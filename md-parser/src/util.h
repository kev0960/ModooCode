#include <experimental/optional>
#include <string>
#include <utility>

using std::string;
namespace md_parser {
std::experimental::optional<size_t> ReadUntilEndOfLine(const string& content,
                                                       size_t start);
std::pair<int, int> TrimLeft(string* str);
string FetchFirstToken(const string& line);
string::const_iterator FindFirstOfAny(const string& str,
                                      const string& matching_chars);
}
