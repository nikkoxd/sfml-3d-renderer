#ifndef VECTOR3F_H
#define VECTOR3F_H

#include <SFML/System/Vector3.hpp>

class Vector3f : public sf::Vector3f
{
public:
  Vector3f();
  Vector3f(float x, float y, float z);
  Vector3f(sf::Vector3f other);

  float scalarMultiply(sf::Vector3f other);
  Vector3f vectorMultiply(sf::Vector3f other);
};

#endif
