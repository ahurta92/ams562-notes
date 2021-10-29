#include <algorithm>
#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, std::vector<std::vector<int>>& v2)
{
	for(auto& row : v2)
	{
		for(auto& col : row)
		{
			os << col << " ";
		}
		os << std::endl;
	}
	return os;
}

std::vector<std::vector<int>> squarePatch(int n)
{
	// lambda capture n
	std::vector<std::vector<int>> arr(n);
	for(auto& vec : arr)
	{
		vec = std::vector<int>(n);
		std::fill(vec.begin(), vec.end(), n);
	}

	return arr;
}

int main()
{

	auto v3 = squarePatch(3);
	auto v5 = squarePatch(5);
	auto v6 = squarePatch(6);

	std::cout << v3;
	std::cout << v5;
	std::cout << v6;
}
