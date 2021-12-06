#include <iterator>
#include <type_traits>
#include "examples.h"

using namespace std;

//helper functions
template <typename Ran> //this function is for random-access iterators
void sort_helper(Ran beg, Ran end, random_access_iterator_tag)
{
	sort(beg, end); // just sort it
}

template <typename C>
using Value_type = typename C::value_type; // C's value type;

template <typename For>
void sort_helper(For beg, For end, forward_iterator_tag)
{
	vector<Value_type<For>> v{beg, end}; //initialize a vector from [beg:end]
	sort(v.begin(), v.end());
	copy(v.begin(), v.end(), beg);
}

template <typename C>
using Iterator_type = typename C::iterator;

template <typename Iter>
using Iterator_category = typename std::iterator_traits<Iter>::iterator_category; //Iter's catergory

template <typename C>
void sort(C& c)
{
	using Iter = Iterator_type<C>;
	sort_helper(c.begin(), c.end(), Iterator_category<Iter>{});
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

	cout << avec << endl;
	cout << alist << endl;
}
