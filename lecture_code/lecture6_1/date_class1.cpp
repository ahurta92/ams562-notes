#include <iostream>
// class (controls acc)
class Date {

public:
  Date(int y, int m, int d); // constructor: check for valid date and intialize
  // accesss functions:
  void add_day(int n);
  int month() { return m; }
  int day() { return d; }
  int year() { return y; }

private:
  int y, m, d; // year, month, day
};

// defintion; note :: "member of" scope resolution operator
Date::Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} {
  // note the member intializers
}

void Date::add_day(int n) {} // defintion

int main() {
  Date my_birthday{1992, 11, 24};
  std::cout << my_birthday.month() << std::endl;
}
