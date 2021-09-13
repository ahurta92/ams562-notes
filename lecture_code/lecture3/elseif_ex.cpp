#include <iostream>

int main() {
  unsigned n;
  std::cout << "enter a non-negative whole number:";
  std::cin >> n;
  std::string odd_or_even;
  if (n % 2) {
    odd_or_even = "odd";
  } else {
    odd_or_even = "even";
  }
  std::cout << "you just entered an " << odd_or_even << " number\n";
}
