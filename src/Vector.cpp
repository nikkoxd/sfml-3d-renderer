#include "Vector.h"
#include <cmath>
#include <stdexcept>

Vector::Vector() : x(0), y(0), z(0), length(0) {};
Vector::Vector(float x, float y, float z) : x(x), y(y), z(z)
{
  length = std::sqrt(x * x + y * y + z * z);
};
Vector::Vector(Vector const &other) : x(other.x), y(other.y), z(other.z), length(other.length) {};

Vector Vector::operator-(Vector const &other)
{
  return Vector(x - other.x, y - other.y, z - other.z);
};

Vector Vector::operator+(Vector const &other)
{
  return Vector(x + other.x, y + other.y, z + other.z);
};

Vector Vector::operator*(float num)
{
  return Vector(x * num, y * num, z * num);
};

Vector Vector::operator/(float num)
{
  return Vector(x / num, y / num, z / num);
};

float &Vector::operator[](int i)
{
  switch (i)
  {
  case 0:
    return x;
  case 1:
    return y;
  case 2:
    return z;
  case 3:
    return length;
  default:
    throw std::out_of_range("Vector index out of range");
  };
};

float Vector::scalarMul(Vector other)
{
  return x * other.x + y * other.y + z * other.z;
};

Vector Vector::vectorMul(Vector other)
{
  return Vector(y * other.z - z * other.y, z * other.x - x * other.z,
                x * other.y - y * other.x);
}
