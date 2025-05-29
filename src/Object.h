#ifndef OBJECT_H
#define OBJECT_H

#include "Vertex.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <fstream>

class Object
{
  std::ifstream file;

public:
  std::vector<std::array<Vertex, 3>> polygons;
  float min_x = 1000000, max_x = -1000000, min_y = 1000000, max_y = -1000000,
        min_z = 1000000, max_z = -1000000;

  Object(std::string filename);
};

#endif
