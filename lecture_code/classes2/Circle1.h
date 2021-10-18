#include "Shape1.h"

class Circle : Shape {
public:
  Circle(Point p, int rad); // Constructor

  Point center() const override { return x; }
  void move(Point to) override { x = to; }
  void draw() const override;
  void rotate(int) override {}

private:
  Point x; // center
  int r;   // radius
};
