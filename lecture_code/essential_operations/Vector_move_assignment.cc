
#include "Vector_assignment.h"

Vector::Vector(const Vector &a) // copy constructor
    : elem{new double[a.sz]}    // allocate space for elements
      ,
      sz{a.sz} {
  for (int i = 0; i != sz; ++i)
    elem[i] = a.elem[i]; // copy each element
}

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

Vector::Vector(Vector &&a) : elem{a.elem}, sz{a.sz} { // grab the elements
  std::cout << "called move constructor" << std::endl;
  a.elem = nullptr; // no a has no elements
  a.sz = 0;
}

Vector &Vector::operator=(Vector &&a) {} // move assignment
