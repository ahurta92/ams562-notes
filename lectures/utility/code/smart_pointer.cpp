#include <type_traits>
#include "examples.h"

template <typename T>
class Smart_pointer
{
	//...
	T& operator*();
	std::enable_if<is_class<T>::value, T&> operator->(); // -> should only work if T is a class
};

class X
{};

int main()
{

	Smart_pointer<X> sX;
	Smart_pointer<int> si;
	Smart_pointer<vector<double>> svd;
}
