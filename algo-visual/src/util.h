#include <Magick++.h>
#include <iostream>
#include <string>

namespace algo_visual {

double GetStringSize(const std::string& s) {
  Magick::Image image(Magick::Geometry(1000, 1000), Magick::Color("white"));
  auto text = Magick::DrawableText(0, 0, s);

  Magick::TypeMetric metric;
  image.draw(Magick::DrawableFont("NanumBarunGothic", Magick::NormalStyle, 400,
                                  Magick::NormalStretch));
  image.fontTypeMetrics(s, &metric);

  std::cout << "textHeight : " << metric.textHeight() << std::endl;
  std::cout << "textWidth : " << metric.textWidth() << std::endl;

  return metric.textWidth();
}

}  // namespace algo_visual
