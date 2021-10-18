
#include "Shape1.h"
#include <vector>
// function to vector of pointers to shape passed by reference
// no matter the type of shape we can call rotate
void rotate_all(std::vector<Shape *> &v,
                int angle) // rotate v's elements by angle degrees
{
  for (auto p : v)
    p->rotate(angle);
}
