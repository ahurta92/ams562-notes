#include <chrono>
#include <iostream>

extern int a; // separate defining
// from declaration using keyword extern
//
// defined externaly
extern const int b;

int main() {
  std::cout << "a =" << a;
  return 0;
}

int a = 1; // define here
const int b = 2;

// To build this code we can
// build and link the definitions from multiple files
//
// e.g
//
// g++ extern_keyword.cpp a.cpp
