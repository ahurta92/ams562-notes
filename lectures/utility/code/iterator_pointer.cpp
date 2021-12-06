#include <iterator>
using namespace std;

template <class T>
struct iterator_traits<T*>
{
	using difference_type = ptrdiff_t;
	using value_type = T;
	using pointer = T*;
	using reference = T&;
	using iterator_category = random_access_iterator_tag;
};

template <typename Iter>
using Iterator_category = typename std::iterator_traits<Iter>::iterator_category;
