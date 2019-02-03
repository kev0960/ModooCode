#include "hash.h"

#include <openssl/sha.h>

#include <iomanip>
#include <sstream>

namespace md_parser {
namespace {
std::string char_to_hex(int c) {
  std::stringstream stream;
  stream << std::setfill('0') << std::setw(2) << std::hex << c;
  return stream.str();
}
}  // namespace

std::optional<std::string> SHAHash::GenerateSha256Hash(const std::string& s) {
  unsigned char hash_arr[32];

  SHA256_CTX context;
  if (!SHA256_Init(&context)) {
    return std::nullopt;
  }
  if (!SHA256_Update(&context, s.c_str(), s.size())) {
    return std::nullopt;
  }
  if (!SHA256_Final(hash_arr, &context)) {
    return std::nullopt;
  }

  std::string hash_str;
  hash_str.reserve(64);

  for (int c : hash_arr) {
    hash_str.append(char_to_hex(c));
  }
  return hash_str;
}
};  // namespace md_parser
