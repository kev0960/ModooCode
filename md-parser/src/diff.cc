#include "diff.h"

#include <algorithm>
#include <iostream>

#include "util.h"

namespace md_parser {
namespace {
std::vector<std::string_view> SplitByEnter(const string& s) {
  std::vector<std::string_view> chunks;

  size_t start = 0;
  while (start < s.size()) {
    size_t next_enter = s.find('\n', start);
    if (next_enter == string::npos) {
      next_enter = s.size();
    }

    chunks.emplace_back(s.c_str() + start, next_enter - start);
    start = next_enter + 1;
  }

  return chunks;
}
}  // namespace

Diff::Diff(const string& content1, const string& content2) {
  snippets_[0] = SplitByEnter(content1);
  snippets_[1] = SplitByEnter(content2);
  x_size_ = snippets_[0].size();
  y_size_ = snippets_[1].size();
}

void Diff::FollowDiagonal(Node* const node) {
  // Follow the diagonal line if possible.
  int x = node->x;
  int y = node->y;

  while (x < x_size_ && y < y_size_) {
    if (snippets_[0][x] != snippets_[1][y]) {
      break;
    }
    x++;
    y++;
  }

  node->x = x;
  node->y = y;
}

bool Diff::CheckDiffFinished(const std::vector<std::unique_ptr<Node>>& nodes) {
  if (nodes.back()->x == x_size_ && nodes.back()->y == y_size_) {
    // Follow the trace.
    const Node* current = nodes.back().get();
    while (current != nullptr) {
      LOG << current->x << " , " << current->y;
      found_diff_.push_back(*current);
      current = current->prev_node;
    }
    std::reverse(found_diff_.begin(), found_diff_.end());
    return true;
  }
  return false;
}

string Diff::ParseDiffToString() {
  string diff_str;
  if (found_diff_.size() <= 1) {
    return "";
  }

  std::vector<DiffInfo> diff_info_list;
  for (int i = 0; i < static_cast<int>(found_diff_.size()) - 1; i++) {
    int k_diff = (found_diff_[i + 1].x - found_diff_[i + 1].y) -
                 (found_diff_[i].x - found_diff_[i].y);
    if (k_diff == 1) {
      diff_info_list.emplace_back(true, found_diff_[i].x, found_diff_[i].x);
      // Go right (Delete)
      diff_str.append(StrCat("D ", std::to_string(found_diff_[i].x), "\n"));
    } else if (k_diff == -1) {
      // Go down (Add)
      diff_info_list.emplace_back(false, found_diff_[i].y, found_diff_[i].x,
                                  found_diff_[i].x);
      diff_str.append(StrCat("A ", std::to_string(found_diff_[i].y), " at ",
                             std::to_string(found_diff_[i].x), "\n"));
    } else {
      LOG << "Impossible move !";
    }
  }

  // Aggregate diff infos.
  for (int i = 0; i < static_cast<int>(diff_info_list.size()); i++) {
    auto& current = diff_info_list[i];
    if (i + 1 < static_cast<int>(diff_info_list.size())) {
      auto& next = diff_info_list[i + 1];
      if (current.is_delete && next.is_delete && current.to + 1 == next.from) {
        current.to = next.from;
        diff_info_list.erase(diff_info_list.begin() + i + 1);
        i--;
        continue;
      } else if (!current.is_delete && !next.is_delete &&
                 current.at == next.at && current.to + 1 == next.from) {
        current.to = next.from;
        diff_info_list.erase(diff_info_list.begin() + i + 1);
        i--;
        continue;
      }
    }
  }
  return diff_str;
}

void Diff::RunMeyerAlgorithm() {
  int max_row = Max(snippets_[0].size(), snippets_[1].size());
  std::vector<std::unique_ptr<Node>> nodes;

  // Front Lines.
  Table v(max_row + 1);

  // Set the initial node.
  nodes.emplace_back(std::make_unique<Node>(0, 0, nullptr));
  FollowDiagonal(nodes.back().get());
  v[0] = nodes.back().get();

  for (int d = 0; d < 2 * max_row; d++) {
    for (int k = Min(d, max_row); k >= -Min(d, max_row); k--) {
      Node* current_node = v[k];
      if (current_node == nullptr) {
        continue;
      }

      int current_x = current_node->x;
      int current_y = current_node->y;

      LOG << "Current : " << current_x << "," << current_y << " k : " << k;
      // First try going right direction.
      if (k + 1 <= x_size_) {
        Node* right_node = v[k + 1];
        if (right_node != nullptr) {
          LOG << "Right node : " << right_node->x << " (k+1 : " << k + 1 << ")";
        }
        if (right_node == nullptr || right_node->x <= current_x) {
          if (current_x + 1 <= x_size_) {
            nodes.emplace_back(
                std::make_unique<Node>(current_x + 1, current_y, current_node));
            v[k + 1] = nodes.back().get();
            FollowDiagonal(v[k + 1]);
          }
        }
      }

      LOG << nodes.back()->x << " , " << nodes.back()->y << " (k " << k << " d "
          << d << ")";
      if (nodes.back()->prev_node != nullptr) LOG << nodes.back()->prev_node->x;
      if (CheckDiffFinished(nodes)) {
        return;
      }

      // Now we can also try downward direction.
      if (k - 1 >= -y_size_) {
        Node* left_node = v[k - 1];
        if (left_node == nullptr || left_node->x + 1 < current_x) {
          if (current_y + 1 <= y_size_) {
            nodes.emplace_back(
                std::make_unique<Node>(current_x, current_y + 1, current_node));
            v[k - 1] = nodes.back().get();
            FollowDiagonal(v[k - 1]);
            k--;
          }
        }
      }

      LOG << nodes.back()->x << " , " << nodes.back()->y << " (k " << k << " d "
          << d << ")";
      if (CheckDiffFinished(nodes)) {
        return;
      }
    }
    LOG << "---------------";
    for (int k = Min(max_row, d) + 1; k >= -Min(d, max_row) - 1; k--) {
      if (v[k] != nullptr && v[k]->prev_node != nullptr) {
        LOG << "k : " << k << " :: " << v[k]->x << " , " << v[k]->y << " from "
            << v[k]->prev_node->x << "," << v[k]->prev_node->y;
      } else if (v[k] != nullptr)
        LOG << "k : " << k << " :: " << v[k]->x << " , " << v[k]->y;
    }
    LOG << "---------------";
  }
}

string Diff::RunDiff() {
  RunMeyerAlgorithm();
  return ParseDiffToString();
}
}  // namespace md_parser
