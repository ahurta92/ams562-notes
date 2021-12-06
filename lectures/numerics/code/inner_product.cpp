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
	auto N_pts = 10000;

	auto x = linspace(-M_PI / 2, M_PI / 2, N_pts);
	auto cos_x=vector<double>(x.size());
	auto sin_x=vector<double>(x.size());
	auto sin_x2=vector<double>(x.size());
	auto cos_x2=vector<double>(x.size());

	std::function<double(double)> f = [](auto a) { return sin(a); };
	std::function<double(double)> f1 = [](auto a) { return cos(a); };

	transform(x.begin(),x.end(),cos_x.begin(),f);
	transform(x.begin(),x.end(),sin_x.begin(),f1);
	transform(sin_x.begin(),sin_x.end(),sin_x.begin(),sin_x2.begin(),std::multiplies());//compute sin(x)^2
	transform(cos_x.begin(),cos_x.end(),cos_x.begin(),cos_x2.begin(),std::multiplies());// compute cos(x)^2
	// Riemann sum of f
	cout << " Inner product between sin(x) and cos(x): " << inner_product(cos_x.begin(), cos_x.end(),sin_x.begin(), 0.0)<<endl;
	cout << " Inner product between sin(x) and sin(x): " << inner_product(sin_x.begin(), sin_x.end(),sin_x.begin(), 0.0)<<endl;
	cout << " Inner product between sin^2(x) and cos^2(x): " << inner_product(sin_x2.begin(), sin_x2.end(),cos_x2.begin(), 0.0)<<endl;
}
