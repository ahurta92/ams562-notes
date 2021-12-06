#include "examples.h"

template <typename Scalar>
class complex
{
	Scalar re, im;

public:
	static_assert(is_arithmetic<Scalar>(), "Sorry, I only support complex of arithmetic types");

	//.
};

int main()
{

	complex<string> a;
	complex<int> b;
	complex<double> c;
}
