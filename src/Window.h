#ifndef WINDOW_H
#define WINDOW_H

#include "Object.h"
#include "ViewportMatrix.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>

class Window
{
  sf::RenderWindow window;
  Object object;
  ViewportMatrix viewport;

public:
  Window(sf::VideoMode videoMode, std::string title,
         std::string object_filename);
  void loop();
};

#endif
