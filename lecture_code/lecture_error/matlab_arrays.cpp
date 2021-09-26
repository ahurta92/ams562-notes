
#include <exception>
#include <iostream>

// Task is to create exception that will
// catch errors when using these functions.
//
//
// The task to is to write a function
// that adds two heap allocated arrays of doubles
//
// The function should return a new array
// write exceptions that will tess if the sizes
// of the arrays match
//
//
//
//
//

class Size_error {};
class NullPtr_except {};
// returns pointer to heap allocated array
double *allocate_doubles(int n) {
  if (n <= 0) {
    throw Size_error{};
  }
  return new double[n];
}
// fill array with value
void fill_array(int n, double val, double *my_array) {

  if (my_array) {
    for (int i = 0; i != n; ++i) {
      my_array[i] = val;
    }
  } else {
    throw NullPtr_except{};
  }
}
// print_array
void print_array(int n, double *const my_array) {

  for (int i = 0; i != n; ++i) {
    std::cout << my_array[i] << " ";
  }
  std::cout << std::endl;
}

double *zeros(int n) {
  double *a = allocate_doubles(n);
  fill_array(n, 0, a);
  return a;
}
double *ones(int n) {
  double *a = allocate_doubles(n);
  fill_array(n, 1, a);
  return a;
}
double *linspace(int n, double n1, double n2) {
  double *a = allocate_doubles(n);
  double range_vals = n2 - n1;
  double increment = range_vals / (n - 1); // break in n-1 sections

  for (int i = 0; i != n; ++i) {
    a[i] = n1;
    n1 += increment;
  }
  return a;
}
void swap_array(double *&a, double *&b) {
  double *tmp = b;
  b = a;
  a = tmp;
}
// implement tests
void array_tests() {

  int size{0};
  double *ptr1 = nullptr;

  fill_array(3, 0, ptr1);
  double *ptr = zeros(-4);

  std::cout << "Enter a size for your array" << std::endl;
}

int main() {

  bool keep_trying = true;
  int size;
  do
    try {
      array_tests();
      keep_trying = false;
    } catch (Size_error &e1) {
      std::cerr << "bad size allocation" << std::endl;
      std::exit(EXIT_FAILURE);
    } catch (NullPtr_except &e1) {
      std::cerr << "access null ptr" << std::endl;
      std::exit(EXIT_FAILURE);
    } catch (...) {
    }
  while (keep_trying);
}
