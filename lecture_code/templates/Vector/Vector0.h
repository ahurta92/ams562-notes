
#include <exception>
#include <iostream>

class Vector_size_mismatch : public std::exception {
  virtual const char *what() const throw() {
    return "Vector sizes do not match";
  }
};

class Vector {

public:
  // allocates mem on free store
  Vector();
  Vector(int s);
  ~Vector() { delete[] elem; }
  Vector(const Vector &a);            // copy constructor X x(v);
  Vector &operator=(const Vector &a); // copy assignment  x=v;

  Vector(Vector &&a);            // move constructor
  Vector &operator=(Vector &&a); // move assignment

  Vector(std::initializer_list<double> l);
  double &operator[](int i) { return elem[i]; }
  const double &operator[](int i) const { return elem[i]; }
  int size() const { return sz; };
  void push_back(double);

private:
  double *elem;
  int sz;
};
