#include "Vector.h"

void good_copy(Vector v1) {

  Vector v2 = v1;
  v1[0] = 2;
  print(v1);
  print(v2);
  v2[1] = 3;
  print(v1);
  print(v2);
}

int main() {
  Vector c1(3);
  good_copy(c1);
}
