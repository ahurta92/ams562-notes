#include <iostream>

int main() {
  int i1 = 1;
  int i2 = ++i1;
  int i3 = ++++i1;
  int i4 = i1++;
  // we cannot do i1++ ++
  std::cout << "i1 = " << i1 << "\n"
            << "i2 = " << i2 << "\n"
            << "i3 = " << i3 << "\n"
            << "i4 = " << i4 << "\n";
}
