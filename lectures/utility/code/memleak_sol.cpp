#include <memory>
#include "iostream"
using namespace std;

unique_ptr<int> getArray(int s)
{
	// int a[s]; // local variable
	int* a = new int[s];
	int* b = new int[s];
	for(int i = 0; i < s; i++)
	{
		a[i] = i;
		std::cout << &a[i] << std::endl;
	}
	unique_ptr<int> ptr_a = static_cast<unique_ptr<int>>(a);
	auto ptr_b = static_cast<unique_ptr<int>>(b);
	//delete[] a;
	return ptr_a;
}

int main()
{
	int size = 6;
	auto ptr = getArray(size);
	cout << "main" << endl;

	auto ptrx=ptr.get();
	for(int i = 0; i < size; i++)
	{
		std::cout << ptrx[i] << std::endl;
	}
}
