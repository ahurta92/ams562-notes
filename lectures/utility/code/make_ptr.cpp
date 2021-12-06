#include <memory>
#include "examples.h"

struct S
{
	int i;
	string s;
	double d;
	//
};

int main()
{
	auto p1 = make_shared<S>(2, "Apple", 4.23); // pointing to free-store allocated object of type S
	auto p2 = make_unique<S>(1, "Apple", 4.23); // C++ 20 feature
}
