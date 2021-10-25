
#include <exception>
#include <iostream>

class Vector_size_mismatch : public std::exception {
  virtual const char *what() const throw() {
    return "Vector sizes do not match";
  }
};

class VectorI {

public:
  // allocates mem on free store
  VectorI();
  VectorI(int s);
  ~VectorI() { delete[] elem; }
  VectorI(const VectorI &a);            // copy constructor X x(v);
  VectorI &operator=(const VectorI &a); // copy assignment  x=v;

  VectorI(VectorI &&a);            // move constructor
  VectorI &operator=(VectorI &&a); // move assignment

  VectorI(std::initializer_list<int> l);
  int &operator[](int i) { return elem[i]; }
  const int &operator[](int i) const { return elem[i]; }
  int size() const { return sz; };
  void push_back(int);

private:
  int *elem;
  int sz;
};
