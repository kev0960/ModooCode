#ifndef UTIL_H
#define UTIL_H

#include <Magick++.h>
#include <iostream>
#include <string>
#include <utility>

namespace algo_visual {

std::pair<double, double> GetStringSize(const std::string& s) {
  Magick::Image image(Magick::Geometry(1000, 1000), Magick::Color("white"));
  auto text = Magick::DrawableText(0, 0, s);

  Magick::TypeMetric metric;
  image.draw(Magick::DrawableFont("NanumBarunGothic", Magick::NormalStyle, 400,
                                  Magick::NormalStretch));
  image.fontPointsize(20);
  image.fontTypeMetrics(s, &metric);

  std::cout << "textHeight : " << metric.textHeight() << std::endl;
  std::cout << "textWidth : " << metric.textWidth() << std::endl;

  return std::make_pair(metric.textWidth(), metric.textHeight());
}

}  // namespace algo_visual

#endif
