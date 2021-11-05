#include <array>
#include <deque>
#include <list>
#include <map>
#include <vector>
#include "marble.h"

int main()
{

	std::vector<int> a{5};
	auto it = a.begin();
	std::advance(it, 3);
	std::next(it);
	for(it = a.begin(); it != a.end(); it++)
	{
		*it = 2;
	}

	std::vector<Marble> marbles{5};
	for(auto it = marbles.begin(); it != marbles.end(); it++)
	{
		std::cout << it->get_color() << std::endl;
		std::cout << it->get_weight() << std::endl;
	}

	a.push_back(0);
	a.pop_back();
	std::array<int, 5> array;
	array.fill(5);

	std::list<double> dl;
	std::deque<double> deq;
}
