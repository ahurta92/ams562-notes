#include "Circle1.h"
#include <vector>

class Smiley : public Circle {
public:
  Smiley(Point p, int rad) : Circle{p, rad}, mouth{nullptr} {}
  // Circle with p center and radius r
  ~Smiley() {
    delete mouth;
    for (auto p : eyes)
      delete p;
  }
  void move(Point to) override;
  void draw() const override;
  void rotate(int) override;
  void add_eye(Shape *s) { eyes.push_back(s); }
  void set_mouth(Shape *s);
  virtual void wink(int i);

private:
  std::vector<Shape *> eyes;
  Shape *mouth;
};

void Smiley::draw() const {
  Circle::draw();
  for (auto p : eyes)
    p->draw();
  mouth->draw();
}
