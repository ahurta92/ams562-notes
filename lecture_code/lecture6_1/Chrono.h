#include <iostream>
namespace Chrono {

enum class Month {
  jan = 1,
  feb,
  mar,
  apr,
  may,
  jun,
  jul,
  aug,
  sep,
  oct,
  nov,
  dec
};

class Date {

public:
  class Invalid {};
  Date(int y, Month m, int d);
  Date();
  // the default copy operations are fine
  //
  // non modifying operations:
  int day() const { return d; };     // const member: can't modify object
  Month month() const { return m; }; // const member can't modify object
  int year() const { return y; };    // const member can't modify object

  // modifying operations:
  void add_day(int n);   // non-const member: can modify
  void add_month(int n); // non-const member: can modify
  void add_year(int n);  // non-const member: can modify

private:
  // default values
  int y;
  Month m;
  int d;
};

// helper functions
bool is_date(int y, Month m, int d); // true for valid date
bool leapyear(int y);                // true if y is a leap year

// binary operators
bool operator==(const Date &a, const Date &b);
bool operator!=(const Date &a, const Date &b);

std::ostream &operator<<(std::ostream &os, const Date &d); // cout<<Date
std::istream &operator>>(std::istream &is, Date &dd);      // cin>>Date

Day day_of_week(const Date &d);   // day of week of d
Date next_Sunday(const Date d);   // next Sunday after d
Date next_weekday(const Date &d); // next weekday after d

} // namespace Chrono
