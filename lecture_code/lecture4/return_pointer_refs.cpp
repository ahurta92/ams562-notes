
#include <iostream>

int *getPointer() {

  int a = 1;
  int *ptr = &a;

  return ptr;
}

int *getPointer1() {

  int *ptr = new int{0};

  return ptr;
}

double *allocArray(unsigned int size) { return new double[size]; }

int &getRef() {

  int a;
  return a;
}

int main() {
  //
  int *ptr = getPointer();
  int *ptr1 = getPointer1();
  //
  //
  std::cout << *ptr << std::endl;
  std::cout << *ptr1 << std::endl;

  double *my_array = allocArray(5u);

  delete[] my_array;
}
