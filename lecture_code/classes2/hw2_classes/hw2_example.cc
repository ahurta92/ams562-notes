// extract to string
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

// Create a spherePoint class
// Representation x,y,z
// Create a SphereVector Class
//
class SpherePoint {

private:
  double xx, yy, zz;

public:
  // default constructor
  SpherePoint() : xx{1}, yy{0}, zz{0} {}
  // implement constructor that takes in 2 angles
  // and generates point on sphere xyz
  // insure phi and theta are valid
  // theta [0,2pi]
  // phi [ 0 pi]
  SpherePoint(double, double) {}
  // Return x,y,z
  double const x();
  double const y();
  double const z();
};
// implement
SpherePoint *generate_Nrandom_SpherePoint(int);
void print(SpherePoint p) {
  std::cout << p.x() << " " << p.y() << " " << p.z() << std::endl;
}
double circle_length(SpherePoint, SpherePoint);

int main() {

  int N = 5;

  SpherePoint *pts = generate_Nrandom_SpherePoint(N);
  double max_len = 0;
  double min_len = 2 * M_PI;
  double len_i;
  for (int i = i; i < N; ++i) {
    len_i = circle_length(pts[0], pts[i]);
    if (len_i > max_len) {
      max_len = len_i;
    }
    if (len_i < min_len) {
      min_len = len_i;
    }
  }
  std::cout << "The max circle length amoungs " << N << " points = " << max_len;
  std::cout << "The max circle length amoungs " << N << " points = " << min_len;

  delete[] pts;

  return 0;
}
