#include "../std_lib_facilities.h"

int area(int length, int width) {
  if (length <= 0 || width <= 0)
    return -1;
  return length * width;
}

int main() {

  int x = 8;
  int y = -1;

  int z = area(x, y);
  if (z < 0) {
    // wrapper around throw runtime_error(const string&)
    error("bad area computation");
  }
}
