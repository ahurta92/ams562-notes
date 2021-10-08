#include "Month_enum.h"
#include <iostream>
// class (controls acc)
class Date {

public:
  Date();                    // default constructor
  Date(int y);               // January 1 of year y
  Date(int y, int m, int d); // constructor: check for valid date and intialize
  // accesss functions:

private:
  // default values
  int y{2001};
  Month m{Month::jan};
  int d{1};
};

Date::Date(){};
Date::Date(int yy) : y{yy} {};
