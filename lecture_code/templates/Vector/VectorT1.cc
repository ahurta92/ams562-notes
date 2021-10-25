#include "VectorT.h"

void write(const Vector<string> &vs) {

  for (int i = 0; i != vs.size(); ++i) {
    std::cout << vs[i] << "\n";
  }
}
