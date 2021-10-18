#include "ListContainer1.h"

void use(Container &c) {

  const int sz = c.size();

  for (int i = 0; i != sz; ++i) {
    std::cout << c[i] << "\n";
  }
}

void f() {
  List_container lc = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  use(lc);
}

int main() { f(); }
