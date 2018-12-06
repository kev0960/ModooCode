#include <utility>
#include <vector>
#include "world.h"

namespace algo_visual {
template <class T>
class VisVector : public std::vector<T>, public Entity {
 public:
  // Inherit vector constructors.
  using std::vector<T>::vector;

  const std::pair<int, int> GetSize() override {
    // First we need to calculate the size of string.
    return std::make_pair(0, 0);
  }
};

}  // namespace algo_visual
