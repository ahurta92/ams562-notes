#include <algorithm>
#include <cmath>
#include <complex>
#include <functional>
#include <iostream>
#include <numeric>
#include <type_traits>
#include <vector>
#include "printing.h"

using namespace std;
template <typename T>
vector<T> linspace(T a, T b, int N)
{
	vector<T> v(N);
	v[0] = a;
	T increment = (b - a) / (N - 1);
	std::generate(v.begin(), v.end(), [a, &increment]() mutable {
		a = a + increment;
		return a - increment;
	});
	return v;
}

template <typename C>
using Value_type = typename C::value_type;

template <typename C>
C forward_difference(const C& x, const std::function<Value_type<C>(Value_type<C>)>& f)
{
	typedef typename C::value_type value_t;
	C result(x.size());
	auto fd = [&f](const value_t& a, const value_t& b) {
		value_t v = (f(b) - f(a)) / (b - a);
		return v;
	};
	adjacent_difference(x.begin(), x.end(), result.begin(), fd);

	return C(result.begin() + 1, result.end());
}

int main()
{
	function<double(double)> sind = [](double y) { return sin(y); };
	function<double(double)> cosd = [](double y) { return cos(y); };
	auto x = linspace(-M_PI / 2, M_PI / 2, 100);
	// compute sin(x)
	auto f_x = x;
	auto fdv_exact = x;

	transform(x.begin(), x.end(), f_x.begin(), sind); //sin(x)
	transform(x.begin(), x.end(), fdv_exact.begin(), cosd); //sin(x)

	auto fdv = forward_difference(x, sind); // forward difference on sin(x)
	cout << "x: " << x << endl;
	cout << "f(x): " << f_x << endl;
	cout << "f'(x) exact: " << fdv_exact << endl;
	cout << "f'(x): " << fdv << endl;
	cout << "f'(x).size() :  " << fdv.size();
}
