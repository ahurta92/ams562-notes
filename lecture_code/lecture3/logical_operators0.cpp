
#include <iostream>

int main() {
  std::cout << "1<2 and 2<3 is: " << (1 < 2 && 2 < 3);
  std::cout << "3==4 || 3==6/2 is: " << (3 == 4 || 3 == 6 / 2);
  std::cout << "not 1.0<0.0 is: " << (!(1.0 < 0.0));
  std::cout << "either 10>2 or 5>2 but not both: " << ((10 > 2) ^ (5 > 2));
}
