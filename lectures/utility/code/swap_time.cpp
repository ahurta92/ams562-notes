#include <chrono>
#include "examples.h"
template <typename T>
void swap_copy(T& a, T& b)
{
	T tmp{a};
	a = b;
	b = tmp;
}

template <typename T>
void swap_move(T& a, T& b)
{
	T tmp{move(a)};
	a = move(b);
	b = move(tmp);
}

int main()
{
	using namespace std::chrono;

	int size = 100;
	for(int i = i; i < 5; i++)
	{
		vector<int> a(size);
		vector<int> b(size * 10);

		auto t0 = high_resolution_clock::now();
		swap_move(a, b);
		auto t1 = high_resolution_clock::now();
		cout << "swap_move(): size :  " << size << " : ";
		cout << duration_cast<nanoseconds>(t1 - t0).count() << " ns \n";
		swap_copy(a, b);
		auto t2 = high_resolution_clock::now();
		cout << "swap_copy(): size : " << size << " : ";
		cout << duration_cast<nanoseconds>(t2 - t1).count() << " ns \n";
		size *= 10;
	}
}
