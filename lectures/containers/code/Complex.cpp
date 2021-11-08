//
// Created by adrian on 11/4/21.
//
#include "Complex.h"
bool operator==(const complex a, const complex b) {
    return a.real() == b.real() && a.imag() == b.imag();
}
bool operator!=(complex a, complex b) { return !(a == b); }
complex& complex::operator*=(complex a)
{
    re = re * a.re - im * a.im;
    im = re * a.im + im * a.re;
    return *this;
}
complex& complex::operator/=(complex a)
{
    double n = a.norm();
    re = re * a.re + im * a.im;
    im = re * a.im - im * a.re;
    re /= n;
    im /= n;
    return *this;
}
// c=a+b
complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a -= b; }
complex operator-(complex a) { return {-a.real(), -a.imag()}; }
complex operator*(complex a, complex b) { return a *= b; }
complex operator/(complex a, complex b) { return a /= b; }

