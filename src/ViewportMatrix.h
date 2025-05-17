#ifndef VIEWPORTMATRIX_H
#define VIEWPORTMATRIX_H

#include "Matrix.h"

class ViewportMatrix : Matrix
{
  float width, height, x, y, depth;

public:
  ViewportMatrix(float width, float height, float x, float y, float depth);
};

#endif
