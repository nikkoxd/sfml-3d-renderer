#include "Window.h"
#include "matrices/LookAtMatrix.h"
#include "matrices/ProjectionMatrix.h"
#include "matrices/ScaleMatrix.h"
#include "matrices/ViewportMatrix.h"
#include "matrices/YSpinMatrix.h"
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector3.hpp>

Window::Window(sf::VideoMode videoMode, std::string title,
               std::string object_filename)
    : window(videoMode, title), object(object_filename)
{
  ViewportMatrix viewportMatrix(0, -200, videoMode.size.x, videoMode.size.y,
                                object.max_z - object.min_z);
  ProjectionMatrix projectionMatrix(object.min_x, object.max_x, object.min_y,
                                    object.max_y, object.max_z, object.min_z);

  Vector3f cameraPosition(0.5, 0.3, 0.5);
  Vector3f center(0, 0, 0);

  Vector3f zAxis = cameraPosition - center;
  Vector3f xAxis = Vector3f(1, 0, 0).vectorMul(zAxis);
  Vector3f yAxis = zAxis.vectorMul(xAxis);

  LookAtMatrix lookAt(xAxis, yAxis, zAxis, cameraPosition);
  ScaleMatrix scale(0.3, 0.3, 0.3);

  transformationMatrix = viewportMatrix * projectionMatrix * lookAt * scale;
}

void Window::transformPolygons()
{
    for (const auto &polygon : object.polygons)
    {
      YSpinMatrix rotation(rotationAngle);
      std::array<Vertex, 3> transformedPolygon;
      for (int i = 0; i < 3; i++)
      {
        transformedPolygon[i] = {transformationMatrix * rotation * polygon[i].value, polygon[i].normal};
      };
      transformedPolygons.push_back(transformedPolygon);
    };
};

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
