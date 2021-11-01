#include <list>
#include "../Vector/string_to_array.h"
#include "Less_than.h"

template <typename C, typename P>
int count(const C& c, P pred)
{
	int cnt = 0;
	for(const auto& x : c)
		if(pred(x))
			++cnt;
	return cnt;
}

void f(const Vector<int>& vec, const Vector<std::string> vs, int x, const std::string& s)
{
	std::cout << "number of values less than" << x << ":"
			  << count(vec, [&](const int& a) { return a < x; }) << "\n";
	std::cout << "number of values less than" << s << ":"
			  << count(vs, [&](const std::string& a) { return a < s; }) << "\n";
}
// [&] is caputure list
// all local names used in scope like x and s
// capture by reference
//

int main()
{

	auto s = string_to_array("Hi my name is adrian");
	Vector<int> x = {1, 23, 2, 242, 55, 6, 223, 2};

	f(x, s, 3, std::string(" 23"));

	//
	//
}
