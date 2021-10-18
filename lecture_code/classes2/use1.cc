#include "Vector_container1.h"

void use(Container &c) {

  const int sz = c.size();

  for (int i = 0; i != sz; ++i) {
    std::cout << c[i] << "\n";
  }
}

void g() {
  Vector_container vc(10);
  use(vc);
}
int main() { g(); }
