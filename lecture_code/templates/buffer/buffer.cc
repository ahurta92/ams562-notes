#include <iostream>

template <typename T, int N>
struct Buffer
{
	using value_type = T;
	constexpr int size()
	{
		return N;
	}
	T b[N];
};

void fct()
{
	Buffer<int, 10> buf;
}
template <typename Container>
typename Container::value_type sum(const Container& cont)
{
	typename Container::value_type total = 0;
	for(const auto& e : cont)
		total += e;
	return total;
}

int main()
{
	Buffer<char, 1024> glob;
	Buffer<char, 1025>::value_type aChar;
}
