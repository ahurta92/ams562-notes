
#include <iostream>

int main() {

  int a = 1;
  int b = 2;

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;

  // swap
  //
  int temp = b;
  b = a;
  a = temp;

  std::cout << "-------------SWAP----------" << std::endl;

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
}
