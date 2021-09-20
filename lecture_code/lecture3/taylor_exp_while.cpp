#include <cassert>
#include <cmath>
#include <iostream>

// Code computes the taylor series of exp(x)
// Takes two inputs
//
// x: point
// eps: error
int main(int argc, char **argv) {

  if (argc == 3) {

    double x{atof(argv[1])};
    double eps{atof(argv[2])};

    double exact_exp_x = std::exp(x);
    // fill with  with argv
    double xn = 1.0;       // x^n
    double exp_x = 1.0;    // first term =1
    unsigned long fac = 1; // fact(n)
                           //	longs include same number of bits as double

    int N = 1;
    while (std::abs(exp_x - exact_exp_x) > eps) { // while abs error > eps

      xn *= x;
      fac *= N;
      exp_x += xn / fac;
      N++;
      std::cout << "i: " << N << " e^x is " << exp_x << std::endl;
    }
    std::cout << "abs(exp_x - exp(x)) = " << std::abs(exp(x) - exp_x)
              << " with N = " << N << std::endl;

  } else {
    std::cout << " Not enough arguments " << std::endl;
    std::cout << "Expecting x value and eps" << std::endl;
  }
}
