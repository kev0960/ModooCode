#ifndef VIS_VECTOR_H
#define VIS_VECTOR_H

#include <utility>
#include <vector>
#include <unordered_set>
#include "util.h"
#include "world.h"

namespace algo_visual {

struct DecoratedCell {
  string color;
  int index;

  bool operator==(const DecoratedCell& other) const {
    return index == other.index;
  }
};

template<>
struct std::hash<DecoratedCell> {
  size_t operator()(const DecoratedCell& c) const {
    return std::hash<int>(index);
  }
};

template <class T>
class VisVector : public std::vector<T>, public Entity {
 public:
  // Forward arguments to the vector.
  template <typename... Args>
  VisVector(Args&&... args)
      : std::vector<T>(std::forward<Args>(args)...),
        padding_top_(10),
        padding_bottom_(10),
        padding_left_(10),
        padding_right_(10) {}

  const std::pair<double, double> GetSize() override {
    // First we need to calculate the size of string.
    double total_width = 0;
    double total_height = 0;

    for (const auto& element : (*this)) {
      std::string s = std::to_string(element);
      auto s_w_h = GetStringSize(s);
      total_width += padding_left_ + s_w_h.first + padding_right_;
      total_height =
          std::max(total_height, padding_top_ + s_w_h.second + padding_bottom_);
    }
    return std::make_pair(total_width, total_height);
  }

  std::list<Magick::Drawable> Draw() override {
    std::list<Magick::Drawable> draws;
  }

 private:
  double padding_top_;
  double padding_bottom_;
  double padding_left_;
  double padding_right_;

  unordered_set<DecoratedCell> color_info_;
};

}  // namespace algo_visual

#endif
