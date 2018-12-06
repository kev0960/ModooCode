#include <Magick++.h>
#include <iostream>
#include "vis_vector.h"

using namespace std;
using namespace Magick;

int main(int argc, char **argv) {
  InitializeMagick(*argv);

  Image image(Geometry(500, 400), Color("white"));

  image.strokeColor("red");
  image.fillColor("green");
  image.strokeWidth(5);

  image.draw(DrawableCircle(100, 100, 50, 100));
  image.draw(DrawableRectangle(200, 200, 270, 170));

  image.display();

  return 0;
}
