#include <iostream>

std::string choose_method(int flag) {
  std::string method{};
  switch (flag) {
  case 0:
    method = "method1";
    break; // don't forget break the switch
  case 1:
    method = "method2";
    break;
  case 2:
    method = "method3";
    break;
  case 3:
    method = "method4";
    break;
  default:
    method = "default";
    break;
  }
  return method;
}

int main() {

  int flag;
  std::string method;
  // do something with flag
  std::cout << " Which method would you like?" << std::endl;
  std::cin >> flag;
  method = choose_method(flag);
  std::cout << " You selected " << method << std::endl;
  std::cout << " Which method would you like?" << std::endl;
  std::cin >> flag;
  method = choose_method(flag);
  std::cout << " You selected " << method << " the second time " << std::endl;
  // Now we copy and pasted... but what if we need to
  // change to selection e.g add a method
}
