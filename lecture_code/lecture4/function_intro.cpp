#include <iostream>

void print_hello_world() {
  std::cout << "Hello World \n";
  return;
}

void doWork(double *data) {

  // protects against nullptr
  if (data) {
    *data = 1.0;
  }
}

int main() {

  double a = 3.0;

  std::cout << a << std::endl;

  double *ptr_a = &a;
  double *ptr_n = nullptr;

  doWork(ptr_a);
  doWork(ptr_n);

  std::cout << a << std::endl;

  // change to selection e.g add a method
}
