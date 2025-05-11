#ifndef VIEWPORTMATRIX_H
#define VIEWPORTMATRIX_H

#include <array>

class ViewportMatrix
{
  float w, h, x, y, depth;
  std::array<std::array<float, 4>, 4> values;

public:
  ViewportMatrix(float w, float h, float x, float y, float depth);
  std::array<float, 4> operator[](int i);
};

#endif
