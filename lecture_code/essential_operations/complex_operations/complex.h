class complex {
private:
  double re, im; // respresentation: two doubles
public:
  // construct complex from two scalars
  complex(double r, double i) : re{r}, im{i} {}
  // construct complex from one scalar
  complex(double r) : re{r}, im{0} {}
  // default complex:{0,0}
  complex() : re{0}, im{0} {}

  // default constructor
  // we elimate the possiblility of uninitialied variables of type complex

  double real() const { return re; }
  void real(double d) { re = d; }
  double imag() const { return im; }
  void imag(double d) { im = d; }

  // return a reference to this
  // a+=c
  complex &operator+=(complex z) {
    re += z.re;
    im += z.im;
    return *this;
  }

  complex &operator-=(complex z) {
    re -= z.re;
    im -= z.im;
    return *this;
  }
  // On your own time write the implementation of these member
  complex &operator*=(complex z) {
    re = (re * z.re - im * z.im);
    im = (re * z.im - im * z.re);
    return *this;
  };
  complex &operator/=(complex z);
};
// c=a+b
complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a -= b; }
complex operator-(complex a) { return {-a.real(), -a.imag()}; }
complex operator*(complex a, complex b) { return a *= b; }
complex operator/(complex a, complex b) { return a /= b; }

bool operator==(const complex a, const complex b) {
  return a.real() == b.real() && a.imag() == b.imag();
}
bool operator!=(complex a, complex b) { return !(a == b); }
