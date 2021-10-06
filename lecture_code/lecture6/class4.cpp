#include <iostream>

// we only declare the member functions
// inside the class definition
class MyClass {
public:
  // explicit constructor
  explicit MyClass(int a);

  // set value
  void set_value(int a);

  // get value
  int get_value() const;

private:
  int _a;
};

MyClass::MyClass(int a) { _a = a; }

void MyClass::set_value(int a) { _a = a; }

int MyClass::get_value() const { return _a; }

int main() { return 0; }
