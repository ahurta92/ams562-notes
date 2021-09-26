
#include <algorithm>
#include <exception>
#include <initializer_list>
#include <iostream>
#include <stdexcept>

class Vector_size_mismatch : public std::exception {
  virtual const char *what() const throw() {
    return "Vector sizes do not match";
  }
};
class Negative_size : public std::exception {
  virtual const char *what() const throw() {
    return "Vectors cannot have negative size";
  }
};

template <typename T> class Vector {
private:
  T *elem; // elem points to an array of sz elements of type T
  int sz;

public:
  using value_type = T;
  // new stuff
  Vector(std::initializer_list<T>);
  template <typename Iter>
  Vector(Iter b, Iter e)
      : elem{new T[static_cast<int>(e - b)]}, sz{static_cast<int>(e - b)} {
    std::copy(b, e, elem);
  }
  Vector();
  explicit Vector(int s); // constructor: establish invariant, acquire resources
  ~Vector() { delete[] elem; }        // destructor: release resources
  Vector(const Vector &a);            // copy constructor X x(v);
  Vector &operator=(const Vector &a); // copy assignment  x=v;
  Vector(Vector &&a);                 // move constructor
  Vector &operator=(Vector &&a);      // move assignment
  void push_back(T);
  void print() const;

  T *end();
  T *begin();
  T *end() const;
  T *begin() const;
  // .... copy and move operations
  //
  //
  T &operator[](int i);             // accessor for non const vectors
  const T &operator[](int i) const; // for const Vectors
  int size() const { return sz; }
};

template <typename T> Vector<T>::Vector() : elem{nullptr}, sz{0} {} // default
// copy constructor
template <typename T>
Vector<T>::Vector(const Vector<T> &a) : elem{new T[a.sz]}, sz{a.sz} {

  std::cout << "called copy constructor" << std::endl;
  for (int i = 0; i != sz; ++i)
    elem[i] = a.elem[i];

} // default
// Copy assignment: clean up target and copy
template <typename T> Vector<T> &Vector<T>::operator=(const Vector<T> &a) {
  // clean up target...aka lhs
  double *p = new T[a.sz]; // create new heap allocated mem
  for (int i = 0; i != sz; ++i)
    p[i] = a.elem[i];
  delete[] elem;
  elem = p;
  sz = a.sz;
  return *this;
}
// Move constructor
template <typename T>
Vector<T>::Vector(Vector<T> &&a) : elem{a.elem}, sz{a.sz} {
  // set lhs pointer to pointer on rhs
  // make rhs pointer null...we can delete now
  std::cout << "called move constructor" << std::endl;
  // make rhs in deleteable state
  a.elem = nullptr;
  a.sz = 0;
}

// move assignment ... move rhs value to lhs
template <typename T> Vector<T> &Vector<T>::operator=(Vector<T> &&a) {

  // in move assignment we are assuming
  // that lhs is already declared...maybe initialized
  // therefore we clean left handsize by delete and
  // point to new elem on rhs
  std::cout << "called move assignment" << std::endl;
  delete[] elem;
  elem = a.elem;
  sz = a.sz;
  a.elem = nullptr;
  a.sz = 0;
  return *this;
}

// Constructor
template <typename T> Vector<T>::Vector(int s) {
  if (s < 0)
    throw Negative_size{};
  elem = new T[s];
  sz = s;
}

template <typename T> const T &Vector<T>::operator[](int i) const {
  if (i < 0 || size() <= i) {
    throw std::out_of_range{"Vector::operator[]"};
  }
  return elem[i];
}

// begin returns pointer to first element unless empty and therefore nullptr
template <typename T> T *Vector<T>::begin() {
  return size() ? &elem[0] : nullptr;
}
template <typename T> T *Vector<T>::begin() const {
  return size() ? &elem[0] : nullptr;
}

// end returns pointer to one past last element unless empty and therefore
// nullptr end=1+last=0+size()
template <typename T> T *Vector<T>::end() {
  return size() ? &elem[0] + size() : nullptr;
}
template <typename T> T *Vector<T>::end() const {
  return size() ? &elem[0] + size() : nullptr;
}
void write(const Vector<std::string> &vs) {
  for (auto &s : vs)
    std::cout << s << std::endl;
}
// deduction guide
/*
template <typename Iter>
Vector(Iter b, Iter e)
    -> Vector<typename std::iterator_traits<Iter>::value_type>;
                */

template <typename T>
Vector<T>::Vector(std::initializer_list<T> lst)
    : elem{new T[lst.size()]}, sz{static_cast<int>(lst.size())} {

  std::cout << "initializer_list constructor using std::copy" << std::endl;
  std::copy(lst.begin(), lst.end(), elem);
}
template <typename T> void Vector<T>::print() const {

  for (auto &v : *this) {

    std::cout << v << std::endl;
  }
}
