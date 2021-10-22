#include "Bector.h"

void bad_copy(Bector v1) {

  Bector v2 = v1;
  v1[0] = 2;
  print(v1);
  print(v2);
  v2[1] = 3;
  print(v1);
  print(v2);
}

int main() {
  Bector c1(3);
  bad_copy(c1);
}
