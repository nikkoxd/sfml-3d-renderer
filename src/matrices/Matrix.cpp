#include "Matrix.h"

Matrix::Matrix() {
  values = std::array<std::array<float, 4>, 4>{0, 0, 0, 0};
}

Matrix::Matrix(std::array<std::array<float, 4>, 4> values) : values(values) {}

std::array<float, 4> Matrix::operator[](int i) { return values[i]; };

Matrix Matrix::operator*(Matrix other)
{
  Matrix result;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      result[i][j] = 0;
      for (int k = 0; k < 4; k++)
      {
        result[i][j] += values[i][k] * other[k][j];
      }
    }
  }

  return result;
}
