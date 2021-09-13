
#include <iostream>

int main() {

  double obj[3] = {0, 1, 2};

  double *ptr = obj; // equivalent to ptr = &obj[0]

  double *ptr_next = ptr + 1; // point to next location sizeof(int)
  double *ptr_orig = ptr_next - 1;

  double a = ptr_next - ptr_orig;

  std::cout << *ptr << std::endl;
  std::cout << *ptr_next << std::endl;
  std::cout << *ptr_orig << std::endl;

  std::cout << (ptr) << std::endl;      // 2c =16 12
  std::cout << (ptr_next) << std::endl; // 30
}
