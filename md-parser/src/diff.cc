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

bool Diff::CheckDiffFinished() {
  if (nodes_.back()->x == x_size_ && nodes_.back()->y == y_size_) {
    // Follow the trace.
    const Node* current = nodes_.back().get();
    while (current != nullptr) {
      found_diff_.push_back(*current);
      current = current->prev_node;
    }
    std::reverse(found_diff_.begin(), found_diff_.end());
    return true;
  }
  return false;
}

void Diff::MergeDiffResults() {
  if (found_diff_.size() <= 1) return;

  for (int i = 0; i < static_cast<int>(found_diff_.size()) - 1; i++) {
    int k_diff = (found_diff_[i + 1].x - found_diff_[i + 1].y) -
                 (found_diff_[i].x - found_diff_[i].y);
    if (k_diff == 1) {
      diff_info_list_.emplace_back(true, found_diff_[i].x, found_diff_[i].x);
    } else if (k_diff == -1) {
      diff_info_list_.emplace_back(false, found_diff_[i].y, found_diff_[i].y,
                                   found_diff_[i].x);
    } else {
      LOG << "Impossible move !" << k_diff;
      LOG << found_diff_[i].x << " " << found_diff_[i].y;
      LOG << found_diff_[i + 1].x << " " << found_diff_[i + 1].y << "\n";
    }
  }

  // Aggregate diff infos.
  for (int i = 0; i < static_cast<int>(diff_info_list_.size()); i++) {
    auto& current = diff_info_list_[i];
    if (i + 1 < static_cast<int>(diff_info_list_.size())) {
      auto& next = diff_info_list_[i + 1];
      if (current.is_delete && next.is_delete && current.to + 1 == next.from) {
        current.to = next.from;
        diff_info_list_.erase(diff_info_list_.begin() + i + 1);
        i--;
        continue;
      } else if (!current.is_delete && !next.is_delete &&
                 current.at == next.at && current.to + 1 == next.from) {
        current.to = next.from;
        diff_info_list_.erase(diff_info_list_.begin() + i + 1);
        i--;
        continue;
      }
    }
  }
}

string Diff::ParseDiffToString() {
  string diff_str;

  for (const auto& diff_info : diff_info_list_) {
    if (diff_info.is_delete) {
      diff_str.append(StrCat("D ", std::to_string(diff_info.from), " ",
                             std::to_string(diff_info.to), "\n"));
    } else {
      diff_str.append(StrCat("A ", std::to_string(diff_info.from), " ",
                             std::to_string(diff_info.to), " at ",
                             std::to_string(diff_info.at), "\n"));
    }
  }
  return diff_str;
}

void Diff::RunMeyerAlgorithm() {
  int max_row = Max(snippets_[0].size(), snippets_[1].size());

  // Front Lines.
  Table v(max_row + 1);

  // Set the initial node.
  nodes_.emplace_back(std::make_unique<Node>(0, 0, nullptr));
  FollowDiagonal(nodes_.back().get());
  v[0] = nodes_.back().get();

  for (int d = 0; d < 2 * max_row; d++) {
    for (int k = Min(d, max_row); k >= -Min(d, max_row); k--) {
      Node* current_node = v[k];
      if (current_node == nullptr) {
        continue;
      }

      int current_x = current_node->x;
      int current_y = current_node->y;

      // First try going right direction.
      if (k + 1 <= x_size_) {
        Node* right_node = v[k + 1];
        if (right_node == nullptr || right_node->x <= current_x) {
          if (current_x + 1 <= x_size_) {
            nodes_.emplace_back(
                std::make_unique<Node>(current_x + 1, current_y, current_node));
            v[k + 1] = nodes_.back().get();
            FollowDiagonal(v[k + 1]);
          }
        }
      }
      if (CheckDiffFinished()) {
        return;
      }

      // Now we can also try downward direction.
      if (k - 1 >= -y_size_) {
        Node* left_node = v[k - 1];
        if (left_node == nullptr || left_node->x + 1 < current_x) {
          if (current_y + 1 <= y_size_) {
            nodes_.emplace_back(
                std::make_unique<Node>(current_x, current_y + 1, current_node));
            v[k - 1] = nodes_.back().get();
            FollowDiagonal(v[k - 1]);
            k--;
          }
        }
      }

      if (CheckDiffFinished()) {
        return;
      }
    }
  }
}

string Diff::RunDiff() {
  RunMeyerAlgorithm();
  MergeDiffResults();
  return ParseDiffToString();
}

string Diff::CreatePatch() {
  RunMeyerAlgorithm();
  MergeDiffResults();

  // Create a patch string.
  string patch_str;

  for (const auto& diff_info : diff_info_list_) {
    if (diff_info.is_delete) {
      patch_str.append(StrCat("D ", std::to_string(diff_info.from), " ",
                              std::to_string(diff_info.to), "\n"));
    } else {
      patch_str.append(StrCat("A ",
                              std::to_string(diff_info.to - diff_info.from + 1),
                              " ", std::to_string(diff_info.at), "\n"));
      for (int i = diff_info.from; i <= diff_info.to; i++) {
        patch_str.append(snippets_[1][i].begin(), snippets_[1][i].end());
        patch_str.push_back('\n');
      }
    }
  }
  return patch_str;
}

PatchFromDiff::PatchFromDiff(const string& original, const string& patch_str) {
  original_ = SplitByEnter(original);
  patch_str_ = SplitByEnter(patch_str);
}

string PatchFromDiff::GetPatchedString() {
  std::vector<std::string_view> patched;
  int copy_cursor = 0;  // Points the row of the original.
  for (int i = 0; i < static_cast<int>(patch_str_.size()); i++) {
    std::vector<string> patch_info = Split(string(patch_str_[i]), ' ');
    if (patch_info[0] == "D") {
      int from = std::stoi(patch_info[1]);
      int to = std::stoi(patch_info[2]);

      for (; copy_cursor < from; copy_cursor++) {
        patched.push_back(original_[copy_cursor]);
      }
      copy_cursor = to + 1;
    } else {
      int num_row = std::stoi(patch_info[1]);
      int at = std::stoi(patch_info[2]);

      for (; copy_cursor < at; copy_cursor++) {
        patched.push_back(original_[copy_cursor]);
      }
      for (int j = 0; j < num_row; j++) {
        patched.push_back(patch_str_[i + 1 + j]);
      }
      i += num_row;

      copy_cursor = at;
    }
  }
  for (; copy_cursor < static_cast<int>(original_.size()); copy_cursor++) {
    patched.push_back(original_[copy_cursor]);
  }

  int total_len = 0;
  for (const auto& s : patched) {
    total_len += s.size();
  }
  string patched_str;
  patched_str.reserve(total_len + patched.size());

  for (const auto& s : patched) {
    patched_str.append(s.begin(), s.end());
    patched_str.push_back('\n');
  }

  return patched_str;
}

}  // namespace md_parser
