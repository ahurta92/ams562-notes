
// simple Data structure (just data)

struct Date {
  int y, m, d; // year, month, day
};

int main() {

  Date my_birthday;
  // access using .
  // can be very error prone
  my_birthday.y = 11;
  my_birthday.m = 24;
  my_birthday.d = 1992; // should be an error
}
