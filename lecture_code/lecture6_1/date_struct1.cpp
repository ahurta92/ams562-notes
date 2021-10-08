struct Date {
  int y, m, d; // year, month, day
};
// some helper functions
// pass Date type by reference to change
void init_date(Date &dd, int y, int m, int d);
// check for valid date and initialize
void add_day(Date &dd, int n); // increase the Date by n days
// initialize
int main() {
  Date my_birthday;
  // format (year,month,day)
  init_date(my_birthday, 11, 24, 1992); // should be a runtime error
  add_day(my_birthday, 3);              // add 3 days
}
