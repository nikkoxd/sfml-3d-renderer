#ifndef ORTOGONALMATRIX_H
#define ORTOGONALMATRIX_H

#include <array>

class OrtogonalMatrix
{
  float l, r, b, t, n, f;
  std::array<std::array<float, 4>, 4> values;

public:
  OrtogonalMatrix(float l, float r, float b, float t, float n, float f);
  std::array<float, 4> operator[](int i);
};

#endif
