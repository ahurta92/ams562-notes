#include <iostream>

int main() {

  int flag;
  std::string method;
  // do something with flag
  std::cout << " Which method would you like?" << std::endl;
  std::cin >> flag;
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

  std::cout << " You selected " << method << std::endl;

  std::cout << " Which method would you like?" << std::endl;
  std::cin >> flag;
  // then run different statements with differ
  // do something with method
  //
  // Perhaps you need to select another method later
  // on in the code  we then have to copy and paste
  // the code from above
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

  std::cout << " You selected " << method << " the second time " << std::endl;
  // Now we copy and pasted... but what if we need to
  // change to selection e.g add a method
}
