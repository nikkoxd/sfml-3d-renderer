#ifndef MATRIX_H
#define MATRIX_H

#include <array>

class Matrix
{
protected:
  std::array<std::array<float, 4>, 4> values;
  Matrix();
  Matrix(std::array<std::array<float, 4>, 4> values);

public:
  std::array<float, 4> operator[](int i);
  Matrix operator*(Matrix other);
};

#endif
