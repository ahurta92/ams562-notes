#include "Vector.h"
#include <cstdio>

class Bector {
private:
  double *elem;
  int sz;

public:
  Bector(int s) : elem{new double[s]}, sz{s} {
    for (int i = 0; i < sz; ++i) {
      elem[i] = 0;
    }
  }
};

int main() {
  Bector v = 5; // a weird looking implicit conversion
  Bector z = 8; // This is okay. Bector has 8 zeros here
}
