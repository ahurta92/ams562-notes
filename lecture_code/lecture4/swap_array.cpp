
#include <iostream>

int *zeros(int len) {
  int *a = new int[len];
  for (int i = 0; i < len; ++i) {
    a[i] = 0;
  }
  return a;
}
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
