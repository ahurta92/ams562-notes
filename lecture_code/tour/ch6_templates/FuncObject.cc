#include "Vector2.h"
#include <iostream>
#include <list>
#include <string>

template <typename T> class Less_than {
  const T val; // value to compare against
public:
  Less_than(const T &v) : val{v} {}
  bool operator()(const T &x) const { return x < val; } // call operator
};
// Used as arguments to algorithms
//
template <typename C, typename P>
// requires Sequence<c> && Callable<P,Value_type<P>>
int count(const C &c, P pred) {
  int cnt = 0;
  for (const auto &x : c)
    if (pred(x))
      ++cnt;
  return cnt;
}

void f(const Vector<int> &vec, const std::list<std::string> &lst, int x,
       const std::string &s) {

  std::cout << "number of values less than " << x << ":"
            << count(vec, Less_than<int>{x}) << "\n";
  std::cout << "number of values less than " << s << ":"
            << count(lst, Less_than<std::string>(s)) << "\n";
}
void f_lambda(const Vector<int> &vec, const std::list<std::string> &lst, int x,
              const std::string &s) {

  std::cout << "number of values less than " << x << ":"
            << count(vec, [&](int a) { return a < x; }) << "\n";
  std::cout << "number of values less than " << s << ":"
            << count(lst, [&](const std::string a) { return a < s; }) << "\n";
}

void fct(int n, const std::string &s) {
  Less_than<int> Iti{42};
  Less_than<std::string> Its{"Backus"};

  bool b1 = Iti(n);
  bool b2 = Its(s);
  std::cout << "b1: " << b1 << std::endl;
  std::cout << "b2: " << b2 << std::endl;
}
int main() {

  fct(23, "Adrian");

  Vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
  std::list<std::string> l = {"adrian", "Adrian", "hello", "okay"};

  f(a, l, 4, "my");
}
