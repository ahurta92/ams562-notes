#include <iostream>

int main(int argc, char **argv) {

  int i = 1;
  std::cout << "i = " << i << std::endl;
  // We start with i=1

  switch (i) {

  case 1:
    // i==1 ;add 1 to i ;continue
    ++i;
    std::cout << "case 1" << std::endl;
  case 2:
    // i==2 ;add 1 to i ;continue
    ++i;
    std::cout << "case 2" << std::endl;
  case 3:
    // i==2 ;add 1 to i ;continue
    ++i;
    std::cout << "case 3" << std::endl;
  default:
    std::cout << "default case" << std::endl;
  }

  std::cout << "i = " << i << std::endl;
}
