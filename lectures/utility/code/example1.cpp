#include "examples.h"

class Z : public std::exception
{};
class X
{};

void f(int i, int j) // X* vs unique_ptr<X>
{
	X* p = new X[1000];

	unique_ptr<X> sp{new X};
	// we do not delete p if i<99 or j < 77
	if(i < 99)
		throw Z{};
	if(j < 77)
		return;
	// use p and sp;
	delete[] p; //
}

int main()
{
	try
	{
		X* ptr_x = new X;
		delete ptr_x;

		f(20, 20);
	}
	catch(Z& z)
	{
		cerr << z.what() << endl;
	}
}
