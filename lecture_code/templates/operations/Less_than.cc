#include "../complex/complex.h"
bool operator<(const complex a, const complex b)
{
	return true;
}
template <typename T>
class Less_than
{
	const T val; // value to compare against
public:
	Less_than(const T& v)
		: val{v}
	{}
	bool operator()(const T& x) const // the call operator
	{
		return x < val;
	}
};

int main()
{
	auto ltInt = Less_than<int>{2};
	auto ltDouble = Less_than<double>{2.0};
	auto ltc = Less_than<complex>{2.0};
	auto lts = Less_than<std::string>{"Adrian"};

	std::cout << ltInt(4) << std::endl;
	std::cout << ltDouble(4) << std::endl;
	std::cout << ltc(4) << std::endl;
	std::cout << lts("vd") << std::endl;
}
