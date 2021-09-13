

#include <iostream>

int *allocate_int() {

  int a = 3;

  return &a;
}

int main() {

  int *a = allocate_int();

  std::cout << a << std::endl;
  std::cout << *a << std::endl;
}
