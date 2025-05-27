#ifndef OBJECT_H
#define OBJECT_H

#include "Vector3f.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <fstream>

class Object
{
  std::ifstream file;

public:
  std::vector<Vector3f> vertices;
  std::vector<Vector3f> normals;
  std::vector<sf::Vector2f> tex_coords;
  std::vector<std::array<std::array<int, 3>, 3>> faces;

  Object(std::string filename);
};

#endif
