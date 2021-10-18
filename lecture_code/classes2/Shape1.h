struct Point {
  double xp, yp;
  Point(double x, double y) : xp(x), yp(y) {} // default constructor
};

class Shape {
public:
  virtual Point center() const = 0; // pure virtual
  virtual void move(Point to) = 0;

  virtual void draw() const = 0; // draw on "Canvas"
  virtual void rotate(int angle) = 0;

  virtual ~Shape() {} // destructor
  //
};
