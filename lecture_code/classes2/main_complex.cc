#include "complex.h"

void f(complex z) {
  complex a{2.3};
  complex b{1 / a};
  complex c{a + z * complex{1, 2.3}};
  if (c != b) {
    c = -(b / a) + 2 * b;
  }
}

int main() {
  f({3, 2});
  f({1});
  f(0);
  f({});

  complex c1;       //  by default 0
  complex c2{2, 4}; // intialize
  complex c3{2};
}
