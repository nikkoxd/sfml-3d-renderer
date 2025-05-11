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

    window.display();
  }
}
