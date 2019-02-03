#pragma once
#include <string>
#include <optional>

namespace md_parser {
class SHAHash {
  public:
  SHAHash() = default;
  std::optional<std::string> GenerateSha256Hash(const std::string& s);
};
}  // namespace md_parser
