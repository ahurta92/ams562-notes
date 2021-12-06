#include "examples.h"

template <typename T>
void swap(T& a, T& b)
{
	T tmp{move(a)};
	a = move(b);
	b = move(tmp);
}

int main()
{

	vector<int> a(10);
	vector<int> b(100);

	cout << "a.size() = " << a.size() << endl;
	cout << "b.size() = " << b.size() << endl;
	swap(a, b);
	cout << "a.size() = " << a.size() << endl;
	cout << "b.size() = " << b.size() << endl;
}
