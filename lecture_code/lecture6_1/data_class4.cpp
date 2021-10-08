#include "Month_enum.h"
#include <iostream>
// class (controls acc)
class Date {

public:
  Date(int y, int m, int d); // constructor: check for valid date and intialize
  // accesss functions:
private:
  int y;   // year
  Month m; // month enum
  int d;   // day
};

int main() { Date my_birthday{1992, 11, 24}; }
