#include "OrtogonalMatrix.h"

OrtogonalMatrix::OrtogonalMatrix(float l, float r, float b, float t, float n,
                                 float f)
    : values({
          std::array<float, 4>{2.0f / (r - l), 0, 0, -(r + l) / (r - l)},
          std::array<float, 4>{0, 2.0f / (t - b), 0, -(t + b) / (t - b)},
          std::array<float, 4>{0, 0, -2.0f / (f - n), -(f + n) / (f - n)},
          std::array<float, 4>{0, 0, 0, 1},
      }) {};

std::array<float, 4> OrtogonalMatrix::operator[](int i) { return values[i]; };
