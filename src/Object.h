#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <fstream>

class Object
{
  std::ifstream file;

public:
  std::vector<sf::Vector3f> vertices;
  std::vector<sf::Vector3f> normals;
  std::vector<sf::Vector2f> tex_coords;
  std::vector<std::array<sf::Vector3i, 3>> faces;

  Object(std::string filename);
};

#endif
