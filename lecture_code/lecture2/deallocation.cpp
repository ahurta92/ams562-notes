
#include <iostream>

int main() {
  { // allocate int on the stack
    int a = 2;

    std::cout << *&a << std::endl;
  }

  int *ptr_main = nullptr;
  {
    int *ptr = nullptr;
    ptr = new int[4];
    // fill heap array
    // use data
    ptr_main = ptr;
  }
  // create new pointer and intialize to value 3
  std::cout << *ptr_main << std::endl;
  delete[] ptr_main;
}
