

#include <iostream>

int main() {

  int obj[3] = {0, 1, 2};

  int *ptr = obj; // equivalent to ptr = &obj[0]

  int *ptr_next = ptr + 1; // point to next location sizeof(int)
  int *ptr_orig = ptr_next - 1;

  int a = ptr_next - ptr_orig;

  std::cout << *ptr << std::endl;
  std::cout << *ptr_next << std::endl;
  std::cout << *ptr_orig << std::endl;

  std::cout << (ptr) << std::endl;      // 2c =16 12
  std::cout << (ptr_next) << std::endl; // 30

  int s = 0x2c;
  int sp = 0x30;
  std::cout << s << std::endl;      // 2c =16 12
  std::cout << sp << std::endl;     // 2c =16 12
  std::cout << sp - s << std::endl; // 2c =16 12
}
