
// simple Data structure (just data)

struct Date {
  int y, m, d;               // year, month, day
  Date(int y, int m, int d); // constructor: check for valid date and initialize
  void add_day(int n);       // increase the Date by n days
};

// initialize

int main() {

  // Date my_birthday; // error because data is not initialized
  int a{3};
  Date my_birthday{11, 24, 1992};  // should be runtime error
  Date my_birthday1{1992, 11, 24}; // ok
  Date today{2021, 10, 6};         // okay
  Date tomorrow = {2021, 10, 7};   // slightly verbose
  Date Friday = Date{2021, 11, 8}; // ok verbose

  my_birthday.d = 2021;

  Date my_day = my_birthday; // copy constructor
  my_birthday.d = 1950;      // notice that nothing prevents
                             // a user from creating an invalid date because
                             // the members are public

  my_day.add_day(2);
}
