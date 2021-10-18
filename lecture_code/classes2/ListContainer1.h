#include "Container1.h"
#include <iostream>
#include <list>

class List_container : public Container {
public:
  List_container() {} // empty List
  List_container(std::initializer_list<double> il) : ld{il} {}
  ~List_container() {}

  double &operator[](int i) override;
  int size() const override { return ld.size(); }

private:
  std::list<double> ld;
};

double &List_container::operator[](int i) {
  for (auto &x : ld) {
    if (i == 0)
      return x; // keep moving till you get to zero
    --i;
  }
  throw std::out_of_range{"List container"};
}
