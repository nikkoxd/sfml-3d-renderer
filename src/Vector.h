#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
public:
  float x, y, z, length;

  Vector();
  Vector(float x, float y, float z);
  Vector(Vector const &other);

  Vector operator-(Vector const &other);
  Vector operator+(Vector const &other);
  Vector operator*(float num);
  Vector operator/(float num);
  float& operator[](int i);

  float scalarMul(Vector other);
  Vector vectorMul(Vector other);
};

#endif
