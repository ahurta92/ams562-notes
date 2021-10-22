#include "complex1.h"

void test(complex z1) {

  complex z2{z1}; // copy initialization
  complex z3;
  z3 = z2; // copy assignment
}

int main() {
  test(32);
  test(2.4);
}
