
#include <iostream>

void swap_ptr(int *a, int *b) {
  // swap
  int temp = *b;
  *b = *a;
  *a = temp;
}

int main() {

  int a = 1;
  int b = 2;

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;

  std::cout << "-------------SWAP----------" << std::endl;
  swap_ptr(&a, &b);

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
}
