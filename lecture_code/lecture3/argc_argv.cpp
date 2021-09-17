#include <iostream>

int main(int argc, char **argv) {

  std::cout << "Number of arguments " << argc << std::endl;

  for (int i = 0; i < argc; ++i) {
    std::cout << "argv["
              << "]=" << argv[i] << std::endl;
  }
}
