#include <iostream>

// However, a single vector object always has the same size.
class Vector {
public:
  Vector(int s) : elem{new double[s]}, sz{s} {} // construct a Vector
  double &operator[](int i) { return elem[i]; }
  int size() { return sz; }

private:
  double *elem; // pointer to elements
  int sz;       // the nubmer of elements
};
