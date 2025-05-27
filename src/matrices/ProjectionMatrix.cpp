#include "ProjectionMatrix.h"

ProjectionMatrix::ProjectionMatrix(float left, float right, float bottom,
                                 float top, float near, float far)
    : Matrix({
          std::array<float, 4>{2.0f / (right - left), 0, 0,
                               -(right + left) / (right - left)},
          std::array<float, 4>{0, 2.0f / (top - bottom), 0,
                               -(top + bottom) / (top - bottom)},
          std::array<float, 4>{0, 0, -2.0f / (far - near),
                               -(far + near) / (far - near)},
          std::array<float, 4>{0, 0, 0, 1},
      }) {};
