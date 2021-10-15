#include "Vector.h"
Vector read(std::istream &is) {
  Vector v;
  for (double d; is >> d;) // read floating point values into d
    v.push_back(d);
  return v;
}
