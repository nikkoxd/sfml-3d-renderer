#ifndef WINDOW_H
#define WINDOW_H

#include "Object.h"
#include "matrices/Matrix.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>

class Window
{
  sf::RenderWindow window;
  Object object;

  float min_x = 1000000, max_x = -1000000, min_y = 1000000, max_y = -1000000,
        min_z = 1000000, max_z = -1000000;
  Matrix transformationMatrix;

public:
  Window(sf::VideoMode videoMode, std::string title,
         std::string object_filename);

  void loop();
};

#endif
