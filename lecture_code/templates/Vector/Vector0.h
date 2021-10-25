
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

Vector::Vector() : elem{nullptr}, sz{0} {}
// copy constructor
Vector::Vector(const Vector &a) : elem{new double[a.sz]}, sz{a.sz} {
  for (int i = 0; i != sz; ++i)
    elem[i] = a.elem[i];
}
// copy assignment: clean up target and copy
Vector &Vector::operator=(const Vector &a) {
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
Vector::Vector(Vector &&a) : elem{a.elem}, sz{a.sz} {
  std::cout << "called move constructor" << std::endl;
  a.elem = nullptr;
  a.sz = 0;
}
Vector &Vector::operator=(Vector &&a) {
  std::cout << "called move assignment" << std::endl;

  delete[] elem; // delete current mem
  elem = a.elem; // copy pointer from r-v ref which contains mem
  sz = a.sz;     // copy size
  a.elem = nullptr;
  a.sz = 0;
  return *this;

} // move assignment

Vector::Vector(int s)
    : elem{new double[s]}, sz{s} // constructor: acquire resources
{
  for (int i = 0; i != s; ++i)
    elem[i] = 0;
}

Vector::Vector(std::initializer_list<double> l)
    : elem{new double[l.size()]}, sz{static_cast<int>(l.size())} {
  std::copy(l.begin(), l.end(), elem);
}

void Vector::push_back(double d) {
  double *new_elem;
  // allocate sz+1 doubles in heap
  new_elem = new double[sz + 1];
  // copy current doubles into mem
  for (int i = 0; i != sz; ++i) {
    new_elem[i] = elem[i];
  }
  new_elem[sz] = d;
  delete[] elem;
  elem = new_elem;
  // add one to sz
  sz += 1;
}; // add element at end increase size by one

Vector operator+(const Vector &a, const Vector &b) {
  if (a.size() != b.size())
    throw Vector_size_mismatch{};
  Vector res(a.size());
  for (int i = 0; i != a.size(); ++i) {
    res[i] = a[i] + b[i];
  }
  return res;
}
// Helper Function
void print(Vector &a) {
  std::cout << "v: ";
  for (int i = 0; i != a.size(); ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}
