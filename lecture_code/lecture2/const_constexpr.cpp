#include <iostream>

// constexpr function
constexpr double square(double x) { return x * x; }
double time2(double x) { return 2 * x; }
int main() {
  constexpr int var = 17;

  const double d = 3;
  double nonconstd = 3;

  constexpr double cons_d = square_(d);

  constexpr double m1 = 1.4 * square(17);
  constexpr double m2 = 1.4 * square(var);
  const d2 = time2(d);
  d2 = time2(d);

  float f = exp(3, 2);
}
