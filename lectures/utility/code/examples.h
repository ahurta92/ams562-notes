#ifndef LECTURE_EXAMPLES_H
#define LECTURE_EXAMPLES_H

#include <algorithm>
#include <chrono>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

using namespace std;

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

#endif //LECTURE_EXAMPLES_H
