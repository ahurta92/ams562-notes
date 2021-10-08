#include "Month_enum.h"
Month operator++(Month &m) {
  m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
  return m;
}
int main() {

  Month m = Month::sep;
  ++m; // becomes oct
  ++m; // becomes nov
  ++m; // becomes dec
  ++m; // becomes jan
}
