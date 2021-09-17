#include <cassert>
#include <cmath>
#include <iostream>

int main(int argc, char **argv) {

  if (argc == 3) {

    double x{atof(argv[1])};
    double eps = atof(argv[2]);

    double exact_exp_x = std::exp(x);
    // fill with  with argv
    double xn = 1.0;
    double exp_x = 1.0;
    unsigned long fac = 1; // same size as double...precision

    int N = 1;
    while (std::abs(exp_x - exact_exp_x) > eps) {

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
