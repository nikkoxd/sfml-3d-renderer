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

  int rotationAngle = 0;

  std::vector<std::vector<float>> zBuffer;

  Matrix transformationMatrix;
  std::vector<std::array<Vertex, 3>> transformedPolygons;

  void processEvents();
  void transformPolygons();
  void renderModel();
  void initializeZBuffer();

public:
  Window(sf::VideoMode videoMode, std::string title,
         std::string object_filename);

  void loop();
};

#endif
