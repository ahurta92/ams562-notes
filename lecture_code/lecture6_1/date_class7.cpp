#include "Month_enum.h"
// class (controls acc)
class Date {

public:
  int day() const;       // const member: can't modify object
  Month month() const;   // const member can't modify object
  int year() const;      // const member can't modify object
  void add_day(int n);   // non-const member: can modify
  void add_month(int n); // non-const member: can modify
  void add_year(int n);  // non-const member: can modify

private:
  // default values
  int y{2001};
  Month m{Month::jan};
  int d{1};
};

int main() {
  Date d;
  const Date cd = d;

  d.day();
  d.add_day(2);
  cd.day();
  cd.add_day(2); // error const
}

int Date::day() const {
  ++d; // error attempt to change object from const member function
  return d;
}
