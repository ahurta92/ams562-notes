#include "../std_lib_facilities.h"

// use global error code
class Bad_area {}; // class is a user defined type

int area(int length, int width) {
  if (length <= 0 || width <= 0) {
    throw Bad_area{};
  }
  return length * width;
}

int main() {
  int x = 8;
  int y = -1;
  try {

    int z = area(x, y);
  } catch (Bad_area) {
    cerr << "opps! Bad area calcluation - fix programming" << endl;
    // exit(EXIT_FAILURE);
  }
}
