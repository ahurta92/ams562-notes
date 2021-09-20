
#include <iostream>

struct ComplexNumber {
  double real;
  double imag;
};

ComplexNumber getDefaultComplexNumber() {
  ComplexNumber a{0.0, 0.0};
  return a;
}

bool assign(const int len, const double value, double *array) {

  if (!array || len < 0) {
    return false;
  }
  for (int i = 0; i < len; ++i) {
    array[i] = value;
  }
  return true;
}
void print_array(const int len, double *array) {
  for (int i = 0; i != len; ++i) {
    std::cout << " " << array[i];
  }
  std::cout << std::endl;
}

int main() {

  ComplexNumber a = getDefaultComplexNumber();

  int sz = 5;
  double *array = new double[sz];

  double val{0.0};

  if (!assign(sz, val, array)) {

    std::cerr << "invalid inputs \n";
  }

  print_array(sz, array);

  // change to selection e.g add a method
}
