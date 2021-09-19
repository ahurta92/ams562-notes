#include <iostream>

int main(int argc, char **argv) {

  std::cout << "Number of arguments " << argc << std::endl;

  double *data = new double[argc - 1]; // pointer to double array
                                       // heap allocation
                                       //

  // fill with  with argv
  for (int i = 0; i < argc; ++i) {
    data[i] = atof(argv[i + 1]);
  }
  int i = 1;
  for (; i < argc;) {
    std::cout << data[i] << std::endl;
    ++i
  }
  std::cout << i << std::endl;

  double sum = 0;
  for (int i = 0; i < argc - 1; ++i) {
    sum += data[i];
  }
  std::cout << "sum of data   " << sum << std::endl;

  delete[] data;
}
