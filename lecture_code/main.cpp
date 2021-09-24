#include "hello.h"
#include <iostream>

int main() {

  extern int a;

  std::cout << a << std::endl;
}
