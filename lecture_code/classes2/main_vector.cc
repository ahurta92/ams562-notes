#include "Vector.h"

int main() {

  int a[10];
  Vector v(10);

  for (int i = 0; i < 10; ++i) {
    a[i] = 2;
    v[i] = 2;
  }
  for (int i = 0; i < 10; ++i) {
    std::cout << a[i];
  }
  v.print();

  return 0;
}
