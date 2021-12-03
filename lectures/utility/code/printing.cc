#include "examples.h"

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v)
{
	for(const auto& e : v)
	{
		os << e << " ";
	}
	return os;
}
template <typename T>
ostream& operator<<(ostream& os, forward_list<T>& v)
{
	for(const auto& e : v)
	{
		os << e << " ";
	}
	return os;
}
