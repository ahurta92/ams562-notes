#include "complex.h"

int main() {
  complex *carray = new complex[10]; // allocate
  int *iarray = new int[10];
  double *darray = new double[10];

  delete[] carray; // free mem
  delete[] iarray;
  delete[] darray;
}
