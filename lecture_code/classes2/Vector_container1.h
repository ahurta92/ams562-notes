#include "Container1.h"
#include "Vector.h"

class Vector_container : public Container { // implements Container
public:
  Vector_container(int s) : v(s) {} // Vector of s elements
  ~Vector_container() {}

  double &operator[](int i) override { return v[i]; }
  int size() const override { return v.size(); }

private:
  // representation is a vector V
  Vector v;
};
