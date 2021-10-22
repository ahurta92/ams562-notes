#include "Vector_copy.h"

Vector::Vector(const Vector &a) // copy constructor
    : elem{new double[a.sz]}    // allocate space for elements
      ,
      sz{a.sz} {
  for (int i = 0; i != sz; ++i)
    elem[i] = a.elem[i]; // copy each element
}
