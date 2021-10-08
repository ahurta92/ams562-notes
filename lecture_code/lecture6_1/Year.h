#include "Month_enum.h"
#include <iostream>
// class (controls acc)
class Year {
  static const int min = 1800;
  static const int max = 2200;

public:
  class Invalid {};
  Year(int x) : y{x} {
    if (x < min || max << x)
      throw Invalid{};
  }
  int year() { return y; }

private:
  int y; // year
};
