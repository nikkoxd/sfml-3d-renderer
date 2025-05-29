#include "Object.h"
#include "Vertex.h"
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
    std::vector<Vector> vertices;
    std::vector<Vector> normals;
    while (std::getline(file, line))
    {
      std::stringstream ss(line);
      std::string prefix;

      ss >> prefix;
      if (prefix == "v")
      {
        Vector vertex;
        ss >> vertex.x >> vertex.y >> vertex.z;

        vertices.push_back(vertex);

        if (vertex.x < min_x) min_x = vertex.x;
        if (vertex.x > max_x) max_x = vertex.x;
        if (vertex.y < min_y) min_y = vertex.y;
        if (vertex.y > max_y) max_y = vertex.y;
        if (vertex.z < min_z) min_z = vertex.z;
        if (vertex.z > max_z) max_z = vertex.z;
      }
      else if (prefix == "vn")
      {
        Vector normal;
        ss >> normal.x >> normal.y >> normal.z;

        normals.push_back(normal);
      }
      else if (prefix == "f")
      {
        std::array<std::string, 3> string_groups;
        std::array<Vertex, 3> polygon;
        ss >> string_groups[0] >> string_groups[1] >> string_groups[2];

        for (int i = 0; i < 3; i++)
        {
          std::string string_group = string_groups[i];
          std::stringstream group_ss(string_group);

          std::array<int, 3> values;
          char slash;

          group_ss >> values[0] >> slash >> values[1] >> slash >> values[2];
          polygon[i] = (Vertex(vertices[values[0]], normals[values[2]]));
        }

        polygons.push_back(polygon);
      }
    }
  }
}
