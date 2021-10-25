#include "Vector.h"
#include <cstdio>

class Bector {
private:
  double *elem;
  int sz;

public:
  Bector(int s) : elem{new double[s]}, sz{s} {
    for (int i = 0; i < sz; ++i) {
      elem[i] = 0;
    }
  }
  double &operator[](int i) { return elem[i]; };
  double &operator[](int i) const { return elem[i]; };
  int size() const { return sz; }
  ~Bector() { delete[] elem; }
};

void print(const Bector &a) {

  for (int i = 0; i < a.size(); ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

void f(Bector a) { print(a); }

int main() {
  Bector x(5);
  print(x);
  f(x);
  print(x);
  x = 8;
}
