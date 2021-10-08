#include <iostream>
// class (controls acc)
class Date {

public:
  Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} {}
  // accesss functions:
  void add_day(int n) {} // defintion
  int month() { return m; }
  int day() { return d; }
  int year() { return y; }

private:
  int y, m, d; // year, month, day
};

int main() {
  Date my_birthday{1992, 11, 24};
  std::cout << my_birthday.month() << std::endl;
}
