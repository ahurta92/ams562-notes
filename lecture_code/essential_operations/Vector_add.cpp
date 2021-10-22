#include "Vector_assignment.h"

Vector operator+(const Vector &a, const Vector &b) {
  if (a.size() != b.size())
    throw Vector_size_mismatch{};
  Vector res(a.size());
  for (int i = 0; i != a.size(); ++i) {
    res[i] = a[i] + b[i];
  }
  return res;
}
void f(const Vector &x, const Vector &y, const Vector &z) {
  Vector r;
  r = x + y + z;
}

int main() {
  Vector a(1000);
  Vector b(1000);
  Vector c(1000);
  f(a, b, c);
}
