#ifndef MATRIX_H
#define MATRIX_H

#include "../Vector.h"
#include <array>

class Matrix
{
protected:
  std::array<std::array<float, 4>, 4> values;

public:
  Matrix();
  Matrix(std::array<std::array<float, 4>, 4> values);

  std::array<float, 4> operator[](int i);
  Matrix operator*(Matrix other);
  Vector operator*(Vector other);
};

#endif
