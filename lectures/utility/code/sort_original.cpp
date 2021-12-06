#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;
// we wrap sort algorithm to just take a container
// Calls c.begin() and c.end()
template <typename C>
void sort(C& c)
{
	sort(c.begin(), c.end());
}
// This version takes a predicate to sort by
template <typename C, typename Pred>
void sort(C& c, Pred p)
{
	sort(c.begin(), c.end(), p);
}

void test(vector<double>& v, forward_list<int>& lst)
{

	sort(v);
	sort(lst);
}

int main()
{
	vector<double> avec = {1, 23, 1212, 42, 242, 924};
	forward_list<int> alist = {1, 23, 1212, 42, 242, 924};
	test(avec, alist);
}
