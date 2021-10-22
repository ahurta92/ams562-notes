#include <cstdio>
class X {
public:
  X() { puts("X()"); }
  X(const X &) { puts("A copy was made. "); }
};

X f() { return X(); }

X g() {
  X x;
  return x;
}

int main() {
  puts("Calling f ");
  X x = f();
  puts("Calling g ");
  X y = g();
}
