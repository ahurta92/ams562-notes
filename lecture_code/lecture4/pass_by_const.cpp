#include <chrono>
#include <iostream>
// This code can demonstrate the performance difference
// between passing by value and passing by reference
// To test this code make sure you compile while
// turing off compiler optimizations.
// To do this we can compile using -O0 flag
//
// g++ -O0 pass_by_const.cpp

void print1(std::string msg) { std::cout << msg << std::endl; }
void print2(const std::string &msg) { std::cout << msg << std::endl; }

int main() {

  std::string msg = "Hello World asdfasdfasdf asdffffffssssssfasdfa!";
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 100000; ++i) {
    print1(msg);
  }
  auto stop = std::chrono::high_resolution_clock::now();

  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

  std::cerr << duration.count() << std::endl;
  start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 10000; ++i) {
    // print1(msg);
    print2(msg);
  }
  stop = std::chrono::high_resolution_clock::now();

  duration =
      std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cerr << duration.count() << std::endl;
}
