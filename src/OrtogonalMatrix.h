#ifndef ORTOGONALMATRIX_H
#define ORTOGONALMATRIX_H

#include "Matrix.h"

class OrtogonalMatrix : Matrix
{
  float left, right, bottom, top, near, far;

public:
  OrtogonalMatrix(float left, float right, float bottom, float top, float near,
                  float far);
};

#endif
