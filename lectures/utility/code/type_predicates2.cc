#include <type_traits>
#include "examples.h"

template <typename T>
constexpr bool is_arithmetic_v = std::is_arithmetic<T>();

template <typename Scalar>
class complex
{
	Scalar re, im;

public:
	static_assert(is_arithmetic_v<Scalar>, "Sorry, I only support complex of arithmetic types");

	//.
};

int main()
{

	complex<int> a;
	//complex<string> a;
}
