
#include <iostream>

void swap1(int a, int b) {
  // swap
  int temp = b;
  b = a;
  a = temp;
}

int main() {

  int a = 1;
  int b = 2;

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;

  std::cout << "-------------SWAP----------" << std::endl;
  swap1(a, b);

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
}
