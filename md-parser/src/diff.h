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
  string CreatePatch();

 private:
  std::vector<std::string_view> snippets_[2];
  std::vector<Node> found_diff_;
  std::vector<DiffInfo> diff_info_list_;
  std::vector<std::unique_ptr<Node>> nodes_;

  void RunMeyerAlgorithm();
  void FollowDiagonal(Node* const node);
  bool CheckDiffFinished();
  void MergeDiffResults();
  string ParseDiffToString();
  int x_size_, y_size_;
};

class PatchFromDiff {
 public:
  PatchFromDiff(const string& original, const string& patch_str);
  string GetPatchedString();

 private:
  std::vector<std::string_view> original_;
  std::vector<std::string_view> patch_str_;
};
}  // namespace md_parser
