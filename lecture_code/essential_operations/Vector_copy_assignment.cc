
#include "Vector_copy.h"
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
