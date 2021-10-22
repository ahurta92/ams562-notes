
#include "Vector_copy.h"
#include <exception>
#include <iostream>

Vector::Vector() : elem{nullptr}, sz{0} {}
// copy constructor
Vector::Vector(const Vector &a) : elem{new double[a.sz]}, sz{a.sz} {
  std::cout << "called copy constructor" << std::endl;
  for (int i = 0; i != sz; ++i)
    elem[i] = a.elem[i];
}
// copy assignment: clean up target and copy
Vector &Vector::operator=(const Vector &a) {
  std::cout << "called copy assignment" << std::endl;

  double *p = new double[a.sz];
  for (int i = 0; i != a.sz; ++i) {
    p[i] = a.elem[i];
  }

  delete[] elem; // delete resource this is pointing to
  elem = p;
  sz = a.sz;
  return *this; // predefined in a member function
                // points to the object for which the member function is called
}

Vector::Vector(int s)
    : elem{new double[s]}, sz{s} // constructor: acquire resources
{
  for (int i = 0; i != s; ++i)
    elem[i] = i;
}
