#ifndef VERTEX_H
#define VERTEX_H

#include "Vector3f.h"

class Vertex
{
public:
  Vector3f value;
  Vector3f normal;

  Vertex();
  Vertex(Vector3f value, Vector3f normal);
};

#endif
