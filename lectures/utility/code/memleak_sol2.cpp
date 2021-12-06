#include <memory>
#include "iostream"
using namespace std;

unique_ptr<int[]> getArray(int s)
{
	// int a[s]; // local variable
	unique_ptr<int[]> a{ new int[s]};
	unique_ptr<int[]> b{ new int[s]};
	for(int i = 0; i < s; i++)
	{
		a[i] = i;
		std::cout << &a[i] << std::endl;
	}
	return a;
}

int main()
{
	int size = 6;
	auto ptr = getArray(size);
	cout<<"main"<<endl;
	for(int i = 0; i < size; i++)
	{
		std::cout << ptr[i] << std::endl;
	}
}
