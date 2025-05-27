#include "ViewportMatrix.h"

ViewportMatrix::ViewportMatrix(float width, float height, float x, float y,
                               float depth)
    : Matrix({
          std::array<float, 4>{width / 2.0f, 0, 0, x + width / 2.0f},
          std::array<float, 4>{0, -height / 2.0f, 0, y + height / 2.0f},
          std::array<float, 4>{0, 0, depth / 2.0f, depth / 2.0f},
          std::array<float, 4>{0, 0, 0, 0},
      }) {};
