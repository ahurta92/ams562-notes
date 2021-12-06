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

int main()
{
	double x = 2;
	// I try to fix the error by creating a std::function of the necessary type
	function<double(double)> f = sin; // no viable  conversion from overload function type
	// still doesn't work
	print(x, sin, "sin(x)");
	print({2, 3}, cos, "sin(x)");
}
