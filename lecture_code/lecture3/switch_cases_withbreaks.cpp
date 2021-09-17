#include <iostream>

int main(int argc, char **argv) {

  int i = 1;
  std::cout << "i = " << i << std::endl;

  switch (i) {

  case 1:
    ++i;
    std::cout << "case 1" << std::endl;
    break; // we break and leave the switch statement
  case 2:
    ++i;
    std::cout << "case 2" << std::endl;
    break;
  case 3:
    ++i;
    std::cout << "case 3" << std::endl;
    break;
  default:
    std::cout << "default case" << std::endl;
  }
  std::cout << "i = " << i << std::endl;
}
