

#include <iostream>

int *allocate_array_doubles();

int *allocate_int() {

  int *a = new int(3);

  return a;
}

int main() {

  int *a = allocate_int();

  std::cout << a << std::endl;
  std::cout << *a << std::endl;
}

double *allocate_array_doubles(int sz) { return new double[sz]; }
