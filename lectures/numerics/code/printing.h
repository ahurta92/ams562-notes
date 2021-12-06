#include <iostream>
#include <vector>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for(const auto& e : v)
	{

		os << e << " ";
	}
	return os;
}
