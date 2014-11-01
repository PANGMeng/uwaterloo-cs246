#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <iostream>

class Vector {
  int x, y;

 public:
  explicit Vector(int x = 0, int y = 0);

  Vector operator+(const Vector &v) const;
  Vector operator*(const int k) const;

  friend std::ostream& operator<<(std::ostream &out, const Vector &v);
};

Vector operator*(const int k, const Vector &v);

#endif
