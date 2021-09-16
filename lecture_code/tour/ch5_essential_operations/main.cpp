#include "Vector.h"

void f() {

  int sz = 4;
  Vector x(sz);
  for (int i = 0; i != sz; ++i) {
    x[i] = 0;
  }
  Vector y(x);
  x.print();
  y.print();
  Vector z(sz + 1);
  z = x;
  z.print();
  x.print();
}
void test_add(const Vector &x, const Vector &y, const Vector &z) {

  x.print();
  y.print();
  z.print();
  Vector r;
  r = x + y;
  r = r + z;
  r.print();
}

Vector m() {
  Vector x(1000);
  Vector y(2000);
  Vector z(3000);

  z = x; // copy x into z delete previous z elem            // we get a copy(x
         // might be used later in m())
  y = std::move(x); // we get a move assignment
  // better not use x here
  return z; // we get a move
}
int main() {

  int sz = 4;
  Vector x(sz);
  Vector y(sz);
  Vector z(sz);
  for (int i = 0; i != sz; ++i) {
    x[i] = i;
    y[i] = 2 * i;
    z[i] = 3 * i;
  }

  //
  //
  //
  try {
    //   f();

    // test_add(x, y, z);
    Vector vvv;
    vvv = m();

  } catch (std::exception &e) {
    std::cout << e.what() << "\n";
  }
  return 0;
}
