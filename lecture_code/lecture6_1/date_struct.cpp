
// simple Data structure (just data)

struct Date {
  int y, m, d; // year, month, day
};

// some helper functions
void init_day(Date &dd, int y, int m,
              int d); // check for valid date and initialize

void add_day(Date &dd, int n); // increase the Date by n days

// initialize

int main() {

  Date my_birthday;

  init_day(my_birthday, 11, 24, 1992);
}
