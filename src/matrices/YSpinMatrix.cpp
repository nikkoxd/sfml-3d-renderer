#include "YSpinMatrix.h"
#include <cmath>

YSpinMatrix::YSpinMatrix(float angleDeg)
    : Matrix({std::array<float, 4>{cos(angleDeg), 0, sin(angleDeg), 0},
              std::array<float, 4>{0, 1, 0, 0},
              std::array<float, 4>{-sin(angleDeg), 0, cos(angleDeg), 0},
              std::array<float, 4>{0, 0, 0, 1}}) {};
