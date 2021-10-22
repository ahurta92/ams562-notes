#include "Vector.h"

Vector f() {

  Vector x(1000);
  Vector y(2000);
  Vector z(3000);

  z = x;            // we get a copy ( x may be used later)
  y = std::move(x); // we get a move( move assignemnt)
  return z;
}

int main() { Vector v = f(); }
