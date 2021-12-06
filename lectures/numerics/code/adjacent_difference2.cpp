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

	auto x = linspace(0.0 , 1.0, N_pts);
	auto dx=vector<double>(x.size());
	cout<<"x: "<<x<<endl;
 	adjacent_difference(x.begin(),x.end(),dx.begin());
	cout<<"adjacent_difference(x): "<<x<<endl;


}
