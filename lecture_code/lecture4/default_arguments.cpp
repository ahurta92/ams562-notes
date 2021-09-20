#include <chrono>
#include <cmath>
#include <iostream>

int Identity(int a) { return a; }

void print_hello() { std::cout << "Hello World" << std::endl; }

double forward_difference(double (*f)(double), double h, double x) {

  double fd = f(x + h) - f(x);
  return fd / h;
}

int (*fun_ptr)(int);

void call(void (*func)()) { func(); }

int call2(int (*func)(int)) { return func(2); }

int main() {

  // explicit
  fun_ptr = &Identity;

  // implicity
  //
  fun_ptr = Identity;

  // dereference evalates back to pointer
  fun_ptr = *Identity;

  void (*v_ptr)();
  v_ptr = &print_hello;

  call(v_ptr);
  std::cout << " calling call2 using pointer " << call2(fun_ptr) << std::endl;

  double fd1 = forward_difference(&std::exp, .2, 3);
  double fd2 = forward_difference(&std::sin, .2, 3);
  double fd3 = forward_difference(&std::cos, .2, 3);

  std::cout << fd1 << std::endl;
  std::cout << fd2 << std::endl;
  std::cout << fd3 << std::endl;
}
