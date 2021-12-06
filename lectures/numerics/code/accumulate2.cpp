#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#include "printing.h"

using namespace std;
template <typename T>
vector<T> linspace(T a, T b, int N)
{
	vector<T> v(N);
	v[0] = a;
	T increment = (b - a) / (N - 1);
	generate(v.begin(), v.end(), [a, &increment]() mutable {
		a = a + increment;
		return a - increment;
	});
	return v;
}

int main()
{
	auto N_pts = 100;
	// uniform mesh
	auto x = linspace(-M_PI / 2, M_PI / 2, N_pts);

	//cout << "x: " << x << endl;
	//
	std::function<double(double)> f = [](double x) { return x * x * x * x; };
	auto f_piecewise = [](double x) { return (x > 0) ? x : -x; };
	auto h = x[1] - x[0];
	// Riemann sum of f
	cout << "integrate f(x): " << accumulate(x.begin(), x.end(), 0.0, [&f, h](auto sum, auto x) {
		return sum + f(x) * (h);
	})<<endl;
	cout << "integrate f1(x): " << accumulate(x.begin(), x.end(), 0.0, [&f_piecewise, h](auto sum, auto x) {
		return sum + f_piecewise(x) * (h);
	})<<endl;
}
