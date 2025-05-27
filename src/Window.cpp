#include "Window.h"
#include "matrices/ViewportMatrix.h"
#include "matrices/ProjectionMatrix.h"
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector3.hpp>

Window::Window(sf::VideoMode videoMode, std::string title,
               std::string object_filename)
    : window(videoMode, title), object(object_filename)
{
  ViewportMatrix viewportMatrix(0, -200, videoMode.size.x, videoMode.size.y, max_z - min_z);
  ProjectionMatrix projectionMatrix(min_x, max_x, min_y, max_y, max_z, min_z);

  Vector3f cameraPosition(0.5, 0.3, 0.5);
  Vector3f center(0, 0, 0);

  Vector3f zAxis = cameraPosition - center;
  Vector3f xAxis = Vector3f(1, 0, 0).componentWiseMul(zAxis);
}

void Window::loop()
{
  while (window.isOpen())
  {
    while (const std::optional event = window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
      {
        window.close();
      }
    }

    window.clear(sf::Color::White);

    for (const auto &face : object.faces)
    {
      for (const auto &group : face)
      {
        Vector3f vertex = object.vertices[group[0] + 1];
        sf::Vector2f tex_coords = object.tex_coords[group[1] + 1];
        Vector3f normals = object.normals[group[2] + 1];
      }
    }

    window.display();
  }
}
