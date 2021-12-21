#include <cmath>
#include <complex>
#include <functional>
#include <iostream>
#include <type_traits>

using namespace std;

struct f1
{
	double operator()(double x)
	{
		return sin(x);
	};
};

template <typename T, class F>
void print(T x, F f, string fx)
{
	cout << "f(" << x << ") = " << f(x) << " : " << fx << endl;
}

int main()
{
	function<double(double)> f = [](double y) { return sin(y); };
	function<complex<double>(complex<double>)> f2 = [](complex<double> y) { return sin(y); };
	// a little trick inorder to set the type of the math functions
	// the cmath functions take in a value of type T and return a value
	// of type T.  If you would like to pass in a a cmath function you
	// need to give the cmath function a type by wrapping it in another function
	//function<double(double)> f1 = sin;
	double x = 2;
	auto a = f1();
	print(x, f, "sin(x)");
	print(complex<double>{2, 3}, f2, "sin(x)");
	print(3.0, a, "sin(x)");
	// at compile time we need to know the type of our funciton
}
