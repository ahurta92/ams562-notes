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
	auto dx=vector<double>(x.size());
	// compute sin(x)
	auto f=[](auto x){ return sin(x);};
	transform(x.begin(),x.end(),sin_x.begin(),f);

	cout<<"sin_x: "<<sin_x<<endl;
	adjacent_difference(sin_x.begin(),sin_x.end(),dx.begin());
	cout<<"adjacent_difference(sin(x)): "<<dx<<endl;
}
