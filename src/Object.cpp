#include "Object.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <iostream>
#include <sstream>
#include <string>

Object::Object(std::string filename)
{
  file = std::ifstream(filename);
  std::string line;

  if (file.fail())
  {
    throw std::runtime_error("Failed to open file");
  }

  if (file.is_open())
  {
    while (std::getline(file, line))
    {
      std::stringstream ss(line);
      std::string prefix;

      ss >> prefix;
      if (prefix == "v")
      {
        sf::Vector3f vertex;
        ss >> vertex.x >> vertex.y >> vertex.z;

        vertices.push_back(vertex);
      }
      else if (prefix == "vn")
      {
        sf::Vector3f normal;
        ss >> normal.x >> normal.y >> normal.z;

        normals.push_back(normal);
      }
      else if (prefix == "vt")
      {
        sf::Vector2f tex_coord;
        ss >> tex_coord.x >> tex_coord.y;

        tex_coords.push_back(tex_coord);
      }
      else if (prefix == "f")
      {
        std::array<std::string, 3> string_groups;
        std::array<sf::Vector3i, 3> face;
        ss >> string_groups[0] >> string_groups[1] >> string_groups[2];

        for (int i = 0; i < 3; i++)
        {
          std::string string_group = string_groups[i];
          std::stringstream group_ss(string_group);

          sf::Vector3i values;
          char slash;

          group_ss >> values.x >> slash >> values.y >> slash >> values.z;
          face[i] = values;
        }

        faces.push_back(face);
      }
    }
  }
}
