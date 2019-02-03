#include "../src/hash.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace md_parser {
TEST(HashTest, HashEmpty) {
  SHAHash hash;
  EXPECT_THAT(
      hash.GenerateSha256Hash(""),
      testing::Optional(std::string(
          "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855")));
}

TEST(HashTest, SimpleHash) {
  SHAHash hash;
  EXPECT_THAT(
      hash.GenerateSha256Hash("Jaebum"),
      testing::Optional(std::string(
          "369a6aa337ab52b24f585938b07b5b2f24b8eaee413a84bb776ee1e51f904359")));
}

TEST(HashTest, HashKorean) {
  SHAHash hash;
  EXPECT_THAT(
      hash.GenerateSha256Hash("안녕하세요"),
      testing::Optional(std::string(
          "2c68318e352971113645cbc72861e1ec23f48d5baa5f9b405fed9dddca893eb4")));
}
}  // namespace md_parser
