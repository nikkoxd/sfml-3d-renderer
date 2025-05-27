#include "ScaleMatrix.h"

ScaleMatrix::ScaleMatrix(float kx, float ky, float kz) : Matrix({
  std::array<float, 4> {kx, 0, 0, 0},
  std::array<float, 4> {0, ky, 0, 0},
  std::array<float, 4> {0, 0, kz, 0},
  std::array<float, 4> {0, 0, 0, 1}
}) {};
