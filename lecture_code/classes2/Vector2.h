
#include <iostream>
class Vector {
public:
  // initialize with a list of doubles
  // default constructor
  Vector() : elem{}, sz{0} {};
  Vector(std::initializer_list<double>);
  // add elements at end
  // increase the size by one
  void push_back(double);

private:
  double *elem;
  int sz;
};

Vector read(std::istream &is) {
  Vector v;
  for (double d; is >> d;) // read floating point values into d
    v.push_back(d);
  return v;
}
