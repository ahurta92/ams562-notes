#include "Month_enum.h"
#include <iostream>
// class (controls acc)
class Date {

public:
  Date(int y, Month m,
       int d); // constructor: check for valid date and intialize
  // accesss functions:
private:
  int y;   // year
  Month m; // month enum
  int d;   // day
};

int main() {
  // Date my_birthday{1992, 11, 24};// error no mathching constructor
  Date my_birthday{1992, Month::nov, 24};
}
