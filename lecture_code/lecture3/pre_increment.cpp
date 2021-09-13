#include <iostream>

int main() {
  // truncation after division
  //
  //
  int a = 0;
  int b = --a;

  int c = 0;
  c = --a;

  // What will each operator print out?
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;
}
