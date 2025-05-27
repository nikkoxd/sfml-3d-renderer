#include "LookAtMatrix.h"

LookAtMatrix::LookAtMatrix(sf::Vector3f right, sf::Vector3f top,
                           sf::Vector3f back, sf::Vector3f cameraPos)
    : Matrix({std::array<float, 4>{right.x, right.y, right.z, -cameraPos.x},
              std::array<float, 4>{top.x, top.y, top.z, -cameraPos.y},
              std::array<float, 4>{back.x, back.y, back.z, -cameraPos.z},
              std::array<float, 4>{0, 0, 0, 1}}) {};
