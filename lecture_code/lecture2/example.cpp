#include <iostream>

constexpr double square(double x) { return x * x; }
double square_(double x) { return x * x; }

int main() {

  constexpr int var = 17;

  const double d = 3;

  constexpr double cons_d = square_(d);

  constexpr double m1 = 1.4 * square(17);
  constexpr double m2 = 1.4 * square(var);
}
