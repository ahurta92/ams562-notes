#ifndef LECTURE_COMPLEX_H
#define LECTURE_COMPLEX_H

class complex {
private:
  double re, im; // representation: two doubles
public:
  // construct complex from two scalars
  complex(double r, double i) : re{r}, im{i} {}
  // construct complex from one scalar
  complex(double r) : re{r}, im{0} {}
  // default complex:{0,0}
  complex() : re{0}, im{0} {}

  // default constructor
  // we eliminate the possibility of uninitialized variables of type complex

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
  // On your own time write the implementation of this member
  complex &operator*=(complex);
  complex &operator/=(complex);
    complex conj()
    {
        return {re, -im};
    }
    double norm()
    {
        return re * re + im * im;
    }
    complex conj() const
    {
        return {re, -im};
    }
    double norm() const
    {
        return re * re + im * im;
    }
};

#endif
