#include "Vector3f.h"

Vector3f::Vector3f() : sf::Vector3f() {}
Vector3f::Vector3f(float x, float y, float z) : sf::Vector3f(x, y, z) {}
Vector3f::Vector3f(sf::Vector3f other) : sf::Vector3f(other) {}

float Vector3f::scalarMultiply(sf::Vector3f other)
{
  return x * other.x + y * other.y + z * other.z;
};

Vector3f Vector3f::vectorMultiply(sf::Vector3f other)
{
  return Vector3f(y * other.z - z * other.y, z * other.x - x * other.z,
                  x * other.y - y * other.x);
}
