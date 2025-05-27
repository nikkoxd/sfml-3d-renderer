#ifndef YSPINMATRIX_H
#define YSPINMATRIX_H

#include "Matrix.h"

class YSpinMatrix : public Matrix
{
  float angleDeg;

public:
  YSpinMatrix(float angleDeg);
};

#endif
