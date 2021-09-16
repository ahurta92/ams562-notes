
#include <iostream>

int main() {

  int a = -0b1011;
  unsigned b = a;
  int c = 0b1000;

  std::cout << "a  = " << a << std::endl;
  std::cout << "b  = " << b << std::endl;
  std::cout << "c  = " << c << std::endl;

  // and
  std::cout << "(a && b) = " << (a && b) << std::endl;
  std::cout << "(a && c) = " << (a && c) << std::endl;

  // or
  std::cout << "(a || b) = " << (a || b) << std::endl;
  std::cout << "(a || c) = " << (a || c) << std::endl;

  // comparision
  std::cout << "(a == b) = " << (a == b) << std::endl;
  std::cout << "(a == c) = " << (a == c) << std::endl;
  // bitwise and
  std::cout << "(a & b) = " << (a & b) << std::endl;
  std::cout << "(a & c) = " << (a & c) << std::endl;
  // bitwise or
  std::cout << "(a | b) = " << (a | b) << std::endl;
  std::cout << "(a | c) = " << (a | c) << std::endl;
  // bitwise or
  std::cout << "(a | b) = " << static_cast<int>(a | b) << std::endl;
  std::cout << "(a | c) = " << static_cast<int>(a | c) << std::endl;
}
