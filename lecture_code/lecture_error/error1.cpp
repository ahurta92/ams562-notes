#include "../std_lib_facilities.h"

// use global error code

int area(int length, int width) {
  if (length <= 0 || width <= 0) {
    errno = 7;
  }
  return length * width;
}

int main() {
  int x = 8;
  int y = -1;

  int z = area(x, y);
  if (errno == 7) { // errno is defined in <cerrno>
    // wrapper around throw runtime_error(const string&)
    error("bad area computation");
  }
}
