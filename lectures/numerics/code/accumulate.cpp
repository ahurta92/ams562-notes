#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
#include "printing.h"

using namespace std;
template <typename T>
vector<T> linspace(T& a, T b, int N)
{
	vector<T> v(N);
	v[0] = a;
	T increment = (b - a) / (N - 1);
	auto g = [ a, increment]()mutable  {
		a = a + increment;
		return a - increment;
	};
	// Ret = g();  necessary signature of g()
	std::generate(v.begin(), v.end(), g);
	return v;
}

int main()
{
	double a=-M_PI/2;
	auto x = linspace(a, M_PI / 2, 100);
	cout<<a<<endl;

	cout << "x: " << x << endl;
	cout << " sum x: " << accumulate(x.begin(), x.end(), 0.0);
}
