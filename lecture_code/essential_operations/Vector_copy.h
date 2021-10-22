
#include <exception>
#include <iostream>

class Vector {

public:
  // allocates mem on free store
  Vector();
  Vector(int s);
  ~Vector() { delete[] elem; }

  Vector(const Vector &a);            // copy constructor X x(v);
  Vector &operator=(const Vector &a); // copy assignment  x=v;

  double &operator[](int i) { return elem[i]; }
  const double &operator[](int i) const { return elem[i]; }

  int size() const { return sz; };

private:
  double *elem;
  int sz;
};
