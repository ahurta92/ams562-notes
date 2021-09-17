#include <cassert>
#include <cmath>
#include <iostream>

int main(int argc, char **argv) {

  if (argc == 3) {

    int N = atoi(argv[2]);
    double x{atof(argv[1])};
    assert(N > 1);

    // fill with  with argv
    double xn = 1.0;
    double exp_x = 1.0;
    unsigned long fac = 1; // same size as double...precision
    for (int i = 1; i <= N; ++i) {
      xn *= x;
      fac *= i;
      exp_x += xn / fac;
      std::cout << "i: " << i << " e^x is " << exp_x << std::endl;
    }
    std::cout << "abs(exp_x - exp(x)) = " << std::abs(exp(x) - exp_x)
              << " with N = " << N << std::endl;
  } else {

    std::cout << " Not enough arguments " << std::endl;
    std::cout << "Expecting x and N" << std::endl;
  }
}
