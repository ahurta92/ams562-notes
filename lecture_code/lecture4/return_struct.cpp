
#include <iostream>

struct ComplexNumber {
  double real;
  double imag;
};

ComplexNumber getDefaultComplexNumber() {
  ComplexNumber a{0.0, 0.0};
  return a;
}

int main() {

  ComplexNumber a = getDefaultComplexNumber();

  // change to selection e.g add a method
}
