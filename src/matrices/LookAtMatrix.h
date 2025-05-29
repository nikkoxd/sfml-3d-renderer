#ifndef LOOKATMATRIX_H
#define LOOKATMATRIX_H

#include "Matrix.h"

class LookAtMatrix : public Matrix
{
  Vector right, top, back, cameraPos;

public:
  LookAtMatrix(Vector right, Vector top, Vector back, Vector cameraPos);
};

#endif
