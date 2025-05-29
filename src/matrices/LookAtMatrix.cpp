#include "LookAtMatrix.h"

LookAtMatrix::LookAtMatrix(Vector right, Vector top,
                           Vector back, Vector cameraPos)
    : Matrix({std::array<float, 4>{right.x, right.y, right.z, -cameraPos.x},
              std::array<float, 4>{top.x, top.y, top.z, -cameraPos.y},
              std::array<float, 4>{back.x, back.y, back.z, -cameraPos.z},
              std::array<float, 4>{0, 0, 0, 1}}) {};
