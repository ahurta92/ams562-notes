#include <algorithm>
#include <cmath>

// code that sorts floats using std::sort
void abssort(float* x, unsigned n)
{
	std::sort(
		x,
		x + n,
		// Lambda expression begins
		[](float a, float b) { return (std::abs(a) < std::abs(b)); } // end of lambda expression
	);
}
