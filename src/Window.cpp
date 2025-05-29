#include "Window.h"
#include "matrices/LookAtMatrix.h"
#include "matrices/ProjectionMatrix.h"
#include "matrices/ScaleMatrix.h"
#include "matrices/ViewportMatrix.h"
#include "matrices/YSpinMatrix.h"
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector3.hpp>
#include <iostream>
#include <limits>

Window::Window(sf::VideoMode videoMode, std::string title,
               std::string object_filename)
    : window(videoMode, title), object(object_filename)
{
  ViewportMatrix viewportMatrix(0, -200, videoMode.size.x, videoMode.size.y,
                                object.max_z - object.min_z);
  ProjectionMatrix projectionMatrix(object.min_x, object.max_x, object.min_y,
                                    object.max_y, object.max_z, object.min_z);

  Vector cameraPosition(0.5, 0.3, 0.5);
  Vector center(0, 0, 0);

  Vector zAxis = cameraPosition - center;
  Vector xAxis = Vector(1, 0, 0).vectorMul(zAxis);
  Vector yAxis = zAxis.vectorMul(xAxis);

  LookAtMatrix lookAt(xAxis, yAxis, zAxis, cameraPosition);
  ScaleMatrix scale(0.3, 0.3, 0.3);

  transformationMatrix = viewportMatrix * projectionMatrix * lookAt * scale;
}

void Window::transformPolygons()
{
  for (auto polygon : object.polygons)
  {
    YSpinMatrix rotation(rotationAngle);
    std::array<Vertex, 3> transformedPolygon;
    for (int i = 0; i < 3; i++)
    {
      transformedPolygon[i] = {transformationMatrix * rotation *
                                   polygon[i].value,
                               polygon[i].normal};
    };
    transformedPolygons.push_back(transformedPolygon);
  };
};

void Window::processEvents()
{
  while (const std::optional event = window.pollEvent())
  {
    if (event->is<sf::Event::Closed>())
    {
      window.close();
    }
    else if (const auto *keyReleased = event->getIf<sf::Event::KeyReleased>())
    {
      if (keyReleased->code == sf::Keyboard::Key::Left)
      {
        rotationAngle -= 5;
        std::cout << rotationAngle << std::endl;
      }
      else if (keyReleased->code == sf::Keyboard::Key::Right)
      {
        rotationAngle += 5;
        std::cout << rotationAngle << std::endl;
      }
    }
  }
}

void Window::renderModel() { initializeZBuffer(); };

void Window::initializeZBuffer() 
{
  zBuffer.clear();
  for (int i = 0; i < window.getSize().x; i++)
  {
    std::vector<float> row;
    for (int j = 0; j < window.getSize().y; j++)
    {
      row.push_back(std::numeric_limits<float>::min());
    };
    zBuffer.push_back(row);
  };
};

void Window::loop()
{
  while (window.isOpen())
  {
    processEvents();

    window.clear(sf::Color::White);

    window.display();
  }
}
