#include "VectorInt.h"

VectorI::VectorI() : elem{nullptr}, sz{0} {}
// copy constructor
VectorI::VectorI(const VectorI &a) : elem{new int[a.sz]}, sz{a.sz} {
  for (int i = 0; i != sz; ++i)
    elem[i] = a.elem[i];
}
// copy assignment: clean up target and copy
VectorI &VectorI::operator=(const VectorI &a) {
  int *p = new int[a.sz];
  for (int i = 0; i != a.sz; ++i) {
    p[i] = a.elem[i];
  }
  delete[] elem; // delete resource this is pointing to
  elem = p;
  sz = a.sz;
  return *this; // predefined in a member function
                // points to the object for which the member function is called
}
VectorI::VectorI(VectorI &&a) : elem{a.elem}, sz{a.sz} {
  std::cout << "called move constructor" << std::endl;
  a.elem = nullptr;
  a.sz = 0;
}
VectorI &VectorI::operator=(VectorI &&a) {
  std::cout << "called move assignment" << std::endl;

  delete[] elem; // delete current mem
  elem = a.elem; // copy pointer from r-v ref which contains mem
  sz = a.sz;     // copy size
  a.elem = nullptr;
  a.sz = 0;
  return *this;

} // move assignment

VectorI::VectorI(int s)
    : elem{new int[s]}, sz{s} // constructor: acquire resources
{
  for (int i = 0; i != s; ++i)
    elem[i] = 0;
}

VectorI::VectorI(std::initializer_list<int> l)
    : elem{new int[l.size()]}, sz{static_cast<int>(l.size())} {
  std::copy(l.begin(), l.end(), elem);
}

void VectorI::push_back(int d) {
  int *new_elem;
  // allocate sz+1 doubles in heap
  new_elem = new int[sz + 1];
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

VectorI operator+(const VectorI &a, const VectorI &b) {
  if (a.size() != b.size())
    throw VectorI{};
  VectorI res(a.size());
  for (int i = 0; i != a.size(); ++i) {
    res[i] = a[i] + b[i];
  }
  return res;
}
// Helper Function
void print(VectorI &a) {
  std::cout << "v: ";
  for (int i = 0; i != a.size(); ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}
