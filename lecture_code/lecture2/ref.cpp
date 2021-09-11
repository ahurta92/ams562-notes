
#include <iostream>

void print(int i) { std::cout << i << std::endl; }

int main() {

  int a = 2;
  int a_copy = a; // copys value of a
  int &b = a;     // ref to value of a at location of a

  print(a);      // 2
  print(a_copy); // 2
  print(b);      // 2
  std::cout << "initial values above" << std::endl;

  a = 3;
  print(a_copy); // 3
  print(b);      // 3
  std::cout << "first change" << std::endl;

  b = 100;       // ref to a
  print(a);      // unchanged 3
  print(a_copy); //
  std::cout << "second change" << std::endl;
}
