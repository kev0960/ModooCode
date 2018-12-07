#include <Magick++.h>
#include <iostream>
#include "util.h"
#include "vis_vector.h"

using namespace std;
using namespace Magick;

int main(int argc, char **argv) {
  InitializeMagick(*argv);

  Image image(Geometry(500, 400), Color("white"));

  //image.draw(DrawableCircle(100, 100, 50, 100));
  //image.draw(DrawableRectangle(200, 200, 270, 170));
  image.fontPointsize(20);
  std::vector<Drawable> text_draw_list;
  text_draw_list.push_back(
      DrawableFont("NanumBarunGothic", NormalStyle, 400, NormalStretch));
  text_draw_list.push_back(DrawableText(101, 50, "English about same l"));
  text_draw_list.push_back(DrawableText(201, 150, "안녕하세요!", "UTF-8"));
  text_draw_list.push_back(
      DrawableText(301, 100, "이글은 조금 더 깁니다", "UTF-8"));
  image.draw(text_draw_list);

  algo_visual::GetStringSize("안녕하세요!");
  algo_visual::GetStringSize("이글은 조금 더 깁니다");
  algo_visual::GetStringSize("English about same l");

  algo_visual::VisVector<int> vec = std::initializer_list<int>{1,2,3,4,5};
  cout << vec.GetSize().first << " ," << vec.GetSize().second;
  return 0;
}
