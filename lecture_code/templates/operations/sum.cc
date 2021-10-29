#include <list>
#include "../Vector/string_to_array.h"
#include "../complex/complex.h"
#include "Less_than.h"

template <typename Sequence, typename Value>
Value sum(const Sequence& s, Value v)
{

	for(auto x : s)
		v += x;
	return v;
}

int main()
{

	auto s = string_to_array("Hi my name is adrian");
	std::string ss{};
	Vector<int> vi = {1, 23, 2, 242, 55, 6, 223, 2};
	Vector<complex> vc = {1, 2, 3, 242, 55, 6, 223, 2};

	int x = sum(vi, 0.0);
	double d = sum(vi, 0.0);
	auto z = sum(vc, complex{0.0, 0.0});
	auto sum_string = sum(s, ss);

	//
	//
}
