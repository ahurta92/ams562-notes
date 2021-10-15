#include "complex.h"

inline complex operator+(complex a, complex b) { return a += b; }
inline complex operator-(complex a, complex b) { return a -= b; }
inline complex operator-(complex a) { return {-a.real(), -a.imag()}; }
inline complex operator*(complex a, complex b) { return a *= b; }
inline complex operator/(complex a, complex b) { return a /= b; }
// *= +- return ref to this... here we return complex so does that become a
// copy of ref?
// Since the argument is passed by value
// the value is copied and we can modify the argument
// without affecting the caller's copy and use the result as a return value!
inline bool operator==(complex a, complex b) {
  return a.real() == b.real() && a.imag() == b.imag();
}
inline bool operator!=(complex a, complex b) { return !(a == b); }
inline complex sqrt(complex); // definitino is elsewhere
