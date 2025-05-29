#ifndef VERTEX_H
#define VERTEX_H

#include "Vector.h"

class Vertex
{
public:
  Vector value;
  Vector normal;

  Vertex();
  Vertex(Vector value, Vector normal);
};

#endif
