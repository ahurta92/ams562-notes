
#include <iostream>

// returns pointer to heap allocated array
double *allocate_doubles(int n) { return new double[n]; }

// fill array with value
void fill_array(int n, double val, double *my_array) {

  for (int i = 0; i != n; ++i) {
    my_array[i] = val;
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

int main() {

  double *a = zeros(5);
  double *b = ones(5);
  double *c = linspace(5, 2.4, 10);

  print_array(5, a);
  print_array(5, b);
  print_array(5, c);

  std::cout << "-------------SWAP----------" << std::endl;

  print_array(5, a);
  print_array(5, b);
}
