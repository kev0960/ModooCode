#include <iostream>
#include <tuple>
#include <string>

int main() {
  std::tuple<int, double, std::string> tp;
  tp = std::make_tuple(1, 3.14, "hi");

  std::cout << std::get<0>(tp) << std::get<1>(tp) << std::get<2>(tp) << std::endl;
}