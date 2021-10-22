#include "Vector.h"
#include <cstdio>

class Bector {
private:
  double *elem;
  int sz;

public:
  explicit Bector(int s) : elem{new double[s]}, sz{s} {
    for (int i = 0; i < sz; ++i) {
      elem[i] = 0;
    }
  }
};

int main() {
  // now this is not okay
  Bector v(5.0); //  implicit conversion of double to int
  Bector z{8};   // explicit constructor
  Bector s{8.0}; //  does not compile
                 // Bector v = 5;  // a weird looking implicit conversion
  // Bector z = 8;  // This is okay. Bector has 8 zeros here
}
