#include <iostream>

class my_float {
private:
  float x;

public:
  my_float(float y) : x{y} {}
  // defined my own remainder function
  float operator%(my_float y) {
    double s_d_y = x / y.x;
    int s_d_y_int = (x) / (y.x);
    // std::cout << s_d_y << std::endl;
    //// std::cout << s_d_y_int << std::endl;
    return (std::abs(s_d_y - static_cast<float>(s_d_y_int)));
  }
};

int main() {

  int a = 5;
  std::cout << "mod(5,2) =" << 5 % 2 << std::endl;
  std::cout << "mod(5,2) =" << 5.2 % 2 << std::endl;

  my_float f1{5};
  my_float f2{2.5};
  // std::cout << "mod(5,2.5) =" << (f1 % f2) << std::endl;
  // std::cout << "mod(3,3.1) =" << 2.3f % 3.1f << std::endl;
  std::cout << "mod(3,3.1) =" << my_float{3} % my_float{3.1} << std::endl;
}
