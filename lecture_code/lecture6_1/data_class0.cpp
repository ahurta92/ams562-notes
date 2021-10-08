class Date {
  int y, m, d; // year, month, day
public:
  Date(int y, int m, int d); // constructor: check for valid date and intialize
  // accesss functions:
  void add_day(int n); // increase the Date by n days
  int month() { return m; }
  int day() { return d; }
  int year() { return y; }
};
int main() {
  Date my_birthday{1992, 11, 24};
  my_birthday.add_day(4);
  my_birthday.m = 14; // error: Date::m is private
  std::cout << my_birthday.month() << std::endl;
}
