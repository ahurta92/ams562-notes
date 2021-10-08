#include <iostream>
// class (controls acc)
class Date {

public:
  class Invalid {};          // to be used as exception
  Date(int y, int m, int d); // constructor: check for valid date and intialize
  // accesss functions:
  void add_day(int n);
  int month() { return m; }
  int day() { return d; }
  int year() { return y; }

private:
  int y, m, d; // year, month, day
  bool is_valid();
};

// defintion; note :: "member of" scope resolution operator
Date::Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} {
  // note the member intializers
  if (!is_valid())
    throw Invalid{};
}

bool Date::is_valid() {
  if (m < 1 || 12 < m) // check months
    return false;
  return true;
}

void Date::add_day(int n) {} // defintion

int main() {
  Date my_birthday{1992, 11, 24};
  std::cout << my_birthday.month() << std::endl;
}
