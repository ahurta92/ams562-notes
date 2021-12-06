#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#include "printing.h"
#include <iomanip>

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
	auto N_pts = 10000;

	auto x = linspace(-M_PI / 2, M_PI / 2, N_pts);
	auto cos_x = vector<double>(x.size());
	auto sin_x = vector<double>(x.size());
	auto sin_x2=vector<double>(x.size());
	auto cos_x2=vector<double>(x.size());

	// define functions y=sin(x) and y=cos(x)
	std::function<double(double)> f = [](auto a) { return sin(a); };
	auto f1 = [](auto a) { return cos(a); };
	// compute vectors
	transform(x.begin(), x.end(), cos_x.begin(), f);
	transform(x.begin(), x.end(), sin_x.begin(), f1);
	transform(sin_x.begin(),sin_x.end(),sin_x.begin(),sin_x2.begin(),std::multiplies());//compute sin(x)^2
	transform(cos_x.begin(),cos_x.end(),cos_x.begin(),cos_x2.begin(),std::multiplies());// compute cos(x)^2

	auto h = x[1] - x[0];
	auto self = [](double x) { return x; };
	auto riemann_addition = [self, h](auto sum, auto x) { return sum + self(x) * h; };
	cout<<setw(30);
	cout << " integral sin(x)*cos(x): -pi/2 to pi/2 : "
		 << inner_product(
				cos_x.begin(),
				cos_x.end(),
				sin_x.begin(),
				0.0,
				riemann_addition,
				std::multiplies())
		 << endl;
	cout << " integral sin(x)^2: -pi/2 to pi/2 :  "
		 << inner_product(
				sin_x.begin(),
				sin_x.end(),
				sin_x.begin(),
				0.0,
				riemann_addition,
				std::multiplies())
		 << endl;
	cout << " integral sin(x)^2+cos(x)^2 : -pi/2 to pi/2 :  "
		 << inner_product(
			 sin_x2.begin(),
			 sin_x2.end(),
			 cos_x2.begin(),
			 0.0,
			 riemann_addition,
			 std::plus())
		 << endl;
}
