#include "Window.h"
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Vertex.hpp>

Window::Window(sf::VideoMode videoMode, std::string title,
               std::string object_filename)
    : window(videoMode, title), object(object_filename)
{
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
        sf::Vector3f vertex = object.vertices[group[0] + 1];
        sf::Vector2f tex_coords = object.tex_coords[group[1] + 1];
        sf::Vector3f normals = object.normals[group[2] + 1];
      }
    }

    window.display();
  }
}
