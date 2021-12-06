#include <cmath>
#include <complex>
#include <functional>
#include <iostream>
#include <type_traits>

using namespace std;

template <typename T>
void print(T x, std::function<T(T)> f, string fx)
{
	cout << "f(" << x << ") = " << f(x) << " : " << fx << endl;
}
using complex_double = complex<double>;
template <>
void print<complex_double>(complex_double x,
						   std::function<complex_double(complex_double)> f,
						   string fx)
{
	cout << "f" << x << " = " << f(x) << " : " << fx << endl;
}

int main()
{
	function<double(double)> f = [](double y) { return sin(y); };
	function<complex<double>(complex<double>)> f2 = [](complex<double> y) { return sin(y); };
	double x = 2;
	print(x, f, "sin(x)");
	print({2, 3}, f2, "sin(x)");
}
