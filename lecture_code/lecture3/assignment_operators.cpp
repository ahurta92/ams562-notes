#include <iostream>

int main() {
  // truncation after division
  //
  //
  int a = 0;
  int b = 2;

  int c = a + b;
  c *= b; // c=c*2
  c -= b; // c=c-2
  c /= b; // c=c/2
  std::cout << "c = " << c << std::endl;
  // What will each operator print out?
  std::cout << "a = " << a << std::endl;
  std::cout << "a = " << a++ << std::endl;
  std::cout << "a = " << ++a << std::endl;
}
