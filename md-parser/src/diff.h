#include <memory>
#include <string>
#include <string_view>
#include <vector>

using std::string;

namespace md_parser {
class Diff {
  struct Node {
    int x;
    int y;

    Node* prev_node;
    Node(int x, int y, Node* prev_node) : x(x), y(y), prev_node(prev_node) {}
  };

  struct Table {
    const int d;
    std::vector<Node*> v;
    explicit Table(size_t d) : d(d), v(2 * d + 1, nullptr) {}
    Node*& operator[](int pos) { return v[d + pos]; }
  };

  struct DiffInfo {
    bool is_delete;
    int from;
    int to;
    int at;

    DiffInfo(bool is_delete, int from, int to, int at = 0)
        : is_delete(is_delete), from(from), to(to), at(at) {}
  };

 public:
  Diff(const string& content1, const string& content2);
  string RunDiff();

 private:
  std::vector<std::string_view> snippets_[2];
  std::vector<Node> found_diff_;

  void RunMeyerAlgorithm();
  void FollowDiagonal(Node* const node);
  bool CheckDiffFinished(const std::vector<std::unique_ptr<Node>>& nodes);
  string ParseDiffToString();
  int x_size_, y_size_;
};

}  // namespace md_parser
