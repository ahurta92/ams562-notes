#include "Month_enum.h"

class Date {
public:
  Date(); // default constructor
private:
  int y;
  Month m;
  int d;
};
Date::Date() : y{2001}, m{Month::jan}, d{1} {}
