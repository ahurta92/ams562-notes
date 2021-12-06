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
	auto N_pts = 10;

	auto x = linspace(0.0 , 2*M_PI, N_pts);
	auto sin_x=vector<double>(x.size());
	auto px=vector<double>(x.size());
	// compute sin(x)
	auto f=[](auto x){ return static_cast<int>(10*sin(x));};
	transform(x.begin(),x.end(),sin_x.begin(),f);

	cout<<"f(x): "<<sin_x<<endl;
	partial_sum(sin_x.begin(),sin_x.end(),px.begin());
	cout<<"partial_sum(f(x)): "<<px<<endl;
}
