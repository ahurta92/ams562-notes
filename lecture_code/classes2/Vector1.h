
#include <iostream>
class Vector {
public:
  // allocates mem on free store // constructor: acquire resources
  Vector(int s) : elem{new double[s]}, sz{s} {
    for (int i = 0; i != s; ++i)
      elem[i] = 0;
  }
  // destructor free mem
  ~Vector() { delete[] elem; }
  // accessor []
  double &operator[](int i) { return elem[i]; }
  int size() const { return sz; };

private:
  double *elem;
  int sz;
};
