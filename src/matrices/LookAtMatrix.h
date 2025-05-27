#ifndef LOOKATMATRIX_H
#define LOOKATMATRIX_H

#include "Matrix.h"
#include <SFML/System/Vector3.hpp>

class LookAtMatrix : public Matrix
{
  sf::Vector3f right, top, back, cameraPos;

public:
  LookAtMatrix(sf::Vector3f right, sf::Vector3f top, sf::Vector3f back, sf::Vector3f cameraPos);
};

#endif
