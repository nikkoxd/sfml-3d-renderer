#ifndef LOOKATMATRIX_H
#define LOOKATMATRIX_H

#include "Matrix.h"
#include <SFML/System/Vector3.hpp>

class LookAtMatrix : public Matrix
{
  Vector3f right, top, back, cameraPos;

public:
  LookAtMatrix(Vector3f right, Vector3f top, Vector3f back, Vector3f cameraPos);
};

#endif
