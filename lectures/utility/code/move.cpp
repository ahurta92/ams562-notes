#include <memory>
#include "examples.h"

void f1()
{
	auto p = make_unique<int>(2);
	auto q = p; // error: we can't copy a unique_ptr
}
