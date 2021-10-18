#include "Container.h"

void use(Container &c) {

  const int sz = c.size();

  for (int i = 0; i != sz; ++i) {
    std::cout << c[i] << "\n";
  }
}
