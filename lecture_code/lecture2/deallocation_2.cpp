

#include <iostream>

int *allocate_int() {

  int a = 3; // stack
  int *ptr_a;
  ptr_a = new int{a}; // heap allocated
  return ptr_a;
}

int main() {

  int *b, c;

  c = nullptr;

  int *a = allocate_int();

  //
  *ptr = zeros(5);

  // free the memory

  std::cout << a << std::endl;
  std::cout << *a << std::endl;
}
