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
  int x;
  int y;
  bool keep_trying = true;
  do {
    cout << "Please enter a length " << endl;
    cin >> x;
    cout << "Please enter a width " << endl;
    cin >> y;

    try {

      int z = area(x, y);
      keep_trying = false;
      cout << "The area is equal to " << z << endl;
    } catch (Bad_area) {
      cerr << "opps! Bad area calcluation - fix programming" << endl;
    }
  } while (keep_trying);
}
