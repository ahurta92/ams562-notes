#include "complex.h"

int main() {

  complex c1;           //  by default 0
  complex c2{2, 4};     // intialize
  c2 = c1;              // assignment
  complex c3 = c1 + c2; // addition
  complex c4 = c1 - c2; // subtraction
  // behave just like ints but have their own rules for each operation
  int i1;
  int i2{2};

  i2 = i1;
  int i3 = i1 + i2; // addition
  int i4 = i1 - i2; // subtraction
}
