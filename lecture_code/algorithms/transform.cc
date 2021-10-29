#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> evenOddTransform(std::vector<int> arr, int n)
{
	// lambda capture n
	const auto unary = [n](const int& x) { return x + ((x % 2 == 0) ? -2 * n : 2 * n); };

	std::transform(arr.begin(), arr.end(), arr.begin(), unary);
	return arr;
}
