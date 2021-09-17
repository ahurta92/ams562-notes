#include <iostream>

int main(int argc, char **argv) {

  std::cout << "Number of arguments " << argc << std::endl;

  double *data = new double[argc - 1]; // pointer to double array
                                       // heap allocation

  // fill with  with argv
  for (int i = 0; i < argc; ++i) {
    data[i] = atof(argv[i]);
  }

  for (int i = 1; i < argc; ++i) {
    std::cout << data[i] << std::endl;
  }
  double sum = 0;
  for (int i = 1; i < argc; ++i) {
    sum += data[i];
  }
  std::cout << "sum of data   " << sum << std::endl;

  delete[] data;
}
