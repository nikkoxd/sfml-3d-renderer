#include "ViewportMatrix.h"

ViewportMatrix::ViewportMatrix(float w, float h, float x, float y, float depth)
    : values({
          std::array<float, 4>{w / 2.0f, 0, 0, x + w / 2.0f},
          std::array<float, 4>{0, h / 2.0f, 0, y + h / 2.0f},
          std::array<float, 4>{0, 0, depth / 2.0f, depth / 2.0f},
          std::array<float, 4>{0, 0, 0, 0},
      }) {};

std::array<float, 4> ViewportMatrix::operator[](int i) { return values[i]; };
