#include "parser_environment.h"

namespace md_parser {
namespace {

int IndentSize(std::pair<int, int> space_and_tab) {
  return space_and_tab.first + 2 * space_and_tab.second;
}
}

EnumListManager::EnumListManager() {}

void EnumListManager::AddNextList(const std::pair<int, int>& space_and_tab) {
  int indent_size = IndentSize(space_and_tab);

  // 2 spaces ==> One indent.
  int depth = indent_size / spaces_per_indent;

  while (!state_.empty()) {
    auto& depth_and_enum = state_.top();
    if (depth_and_enum.first == depth) {
      depth_and_enum.second += 1;
      return;
    } else if (depth_and_enum.first > depth) {
      state_.push(std::make_pair(depth, 0));
    }

    state_.pop();
  }
  state_.push(std::make_pair(depth, 0));
}

std::pair<int, int> EnumListManager::GetCurrentEnum() const {
  return state_.top();
}

ParserEnvironment::ParserEnvironment() {}

std::pair<int, int> ParserEnvironment::GetCurrentListInfo(
    const TokenTypes type) const {
  switch (type) {
    case LIST_ENUM:
      return enum_list_manager_.GetCurrentEnum();
    case LIST_UNORDER:
      return unordered_list_manager_.GetCurrentEnum();
    default:
      break;
  }
  return std::make_pair(0, 0);
}

void ParserEnvironment::AddNextList(
    const TokenTypes type, const std::pair<int, int>& space_and_tab) {
  switch (type) {
    case LIST_ENUM:
      enum_list_manager_.AddNextList(space_and_tab);
      break;
    case LIST_UNORDER:
      unordered_list_manager_.AddNextList(space_and_tab);
      break;
    default:
      break;
  }
}

}
