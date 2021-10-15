class complex {
  double re, im; // respresentation: two doubles
public:
  double real() const { return re; }
  void real(double d) { re = d; }
  double imag() const { return im; }
  void imag(double d) { im = d; }
  // return a reference to *this
  complex &operator+=(complex z);
  complex &operator-=(complex z);
  complex &operator*=(complex);
  complex &operator/=(complex);
};
inline complex &complex::operator+=(complex z) {
  re += z.re;
  im += z.re;
  return *this;
}
inline complex &complex::operator-=(complex z) {
  re -= z.re;
  im -= z.re;
  return *this;
}
