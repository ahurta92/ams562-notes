#include <list>
#include "../complex/complex.h"
#include "VectorT.h"

int main()
{

	int sz = 6;
	Vector<int> i(sz);
	Vector<double> d(sz);
	Vector<double> dd;
	Vector<complex> c(sz);
	// Vector<std::list<int>> l(sz);
	// Here we will use our new Vector class
	print(i);
	print(d);
	print(c);
	//
	//
}
