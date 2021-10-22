
class Shape {
public:
  Shape(const Shape &) = delete; // no copy operations
  Shape &operator=(const Shape &) = delete;
};

void copy(Shape &s1, const Shape &s2) { s1 = s2; }
// Shapes do not carry the representation
// Should not copy a triangle into a square
// memberwise copy does not make sense here
