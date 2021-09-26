#include "Vector2.h"
template <typename T>
Vector<T>::Vector(std::initializer_list<T> lst)
    : elem{new T[lst.size()]}, sz{static_cast<int>(lst.size())} {

  std::cout << "initializer_list constructor using std::copy" << std::endl;
  std::copy(lst.begin(), lst.end(), elem);
}

int main() {

  auto v1 = {1, 2, 3, 4, 5}; // just a list
  Vector<int> v3(v1);
  v3.print();

  Vector<int> v2(v1.begin(), v1.end());
  v2.print();
}
