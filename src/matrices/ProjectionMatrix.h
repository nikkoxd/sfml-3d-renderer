#ifndef PROJECTIONMATRIX_H
#define PROJECTIONMATRIX_H

#include "Matrix.h"

class ProjectionMatrix : Matrix
{
  float left, right, bottom, top, near, far;

public:
  ProjectionMatrix(float left, float right, float bottom, float top, float near,
                  float far);
};

#endif
