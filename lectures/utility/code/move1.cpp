#include <memory>
#include "examples.h"

void f1()
{
	auto p = make_unique<int>(2);
	auto q = move(p); // error: we can't copy a unique_ptr
	if(p)
	{
		cout << "not null?" << endl;
	}
	else
	{
		cout << "null" << endl;
	}
}

int main()
{
	f1();
}
