

#include <iostream>

struct StructName {
  // any attributes

}; //<-- don't forget teh semicolon

struct ComplexNumber {

  double real;
  double imag;
};

int main() {

  ComplexNumber a, b;

  // a.real using accessing operator
  a.real = 1.0;
  a.imag = -1.0;
  b.real = 2.0;
  b.imag = 1.0;

  std::cout << sizeof(double) << std::endl;
  std::cout << sizeof(ComplexNumber) << std::endl;

  ComplexNumber *ptr_a = &a;
  ComplexNumber *ptr_b = &b;

  std::cout << "complex a=(" << ptr_a->real << ',' << ptr_a->imag << ")\n";
  std::cout << "complex b=(" << ptr_b->real << ',' << ptr_b->imag << ")\n";

  ComplexNumber *ptr_array = new ComplexNumber[10];

  for (int i = 0; i != 10; ++i) {
    ptr_array[i].real = 1.0;
    ptr_array[i].imag = 1.0;
  }

  for (int i = 0; i != 10; ++i) {
    std::cout << "(" << ptr_array[i].real << "," << ptr_array[i].imag << ")"
              << std::endl;
  }

  for (int i = 0; i != 10; ++i) {
    (i + ptr_array)->real = 2.0;
    (i + ptr_array)->imag = 2.0;
  }

  for (int i = 0; i != 10; ++i) {
    std::cout << "(" << ptr_array[i].real << "," << ptr_array[i].imag << ")"
              << std::endl;
  }
  // access members through pointers using ->
}
