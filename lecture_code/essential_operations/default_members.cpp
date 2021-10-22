#include <cstdio>
class X {
public:
  X(double);
  X();
  X(const X &) = default;
  X(X &&) = default;
};
