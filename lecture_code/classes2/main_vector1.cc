#include "Vector.h"

void fct(int n) {
  Vector v(n);
  // use v
  {
    Vector v2(2 * n);
    for (int i = 0; i < v2.size(); i++) {
      std::cout << v2[i];
    }
    // use v and v2...
  } // v2 is destroyed here
    // use v ..
} // v is destoryed here

int main() {
  fct(2);
  int N;
  std::cin >> N;
  fct(N);
  return 0;
}
