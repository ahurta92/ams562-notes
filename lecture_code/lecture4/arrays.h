
#include <iostream>

// returns pointer to heap allocated array
double *allocate_doubles(int n) { return new double[n]; }

// fill array with value
void fill_array(int n, double val, double *my_array) {

  for (int i = 0; i != n; ++i) {
    my_array[i] = val;
  }
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

  int *ones(int len) {
    int *a = new int[len];
    for (int i = 0; i < len; ++i) {
      a[i] = 1;
    }
    return a;
  }

  void print_array(int len, const int *a) {
    for (int i = 0; i < len; ++i) {
      std::cout << " " << a[i];
    }
    std::cout << std::endl;
  }

  void swap_array(int *&a, int *&b) {

    int *tmp = b;
    b = a;
    a = tmp;
  }

  int main() {

    int *a = zeros(5);
    int *b = ones(5);

    print_array(5, a);
    print_array(5, b);

    swap_array(a, b);

    std::cout << "-------------SWAP----------" << std::endl;

    print_array(5, a);
    print_array(5, b);
  }
