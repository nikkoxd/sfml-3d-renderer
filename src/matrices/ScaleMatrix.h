#ifndef SCALEMATRIX_H
#define SCALEMATRIX_H

#include "Matrix.h"

class ScaleMatrix : Matrix
{
  float kx, ky, kz;

public:
  ScaleMatrix(float kx, float ky, float kz);
};

#endif
