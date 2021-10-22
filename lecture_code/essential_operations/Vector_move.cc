
#include "Vector_assignment.h"

Vector::Vector(Vector &&a) : elem{a.elem}, sz{a.sz} { // grab the elements
  std::cout << "called move constructor" << std::endl;
  a.elem = nullptr; // no a has no elements
  a.sz = 0;
}
