#include <iostream>

int main() {
  std::string dep;
  std::cout << "enter the department:";
  std::cin >> dep;
  if (dep == "ams") {
    std::string course;
    std::cout << "enter the class number:";
    std::cin >> course;
    std::cout << "welcome to ams" << course << std::endl;
  }
}
