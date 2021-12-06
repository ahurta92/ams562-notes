#include <algorithm>
#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "polynomial.h"

unsigned int Factorial(unsigned int number)
{
	return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Factorials are computed", "[factorial]")
{
	REQUIRE(Factorial(1) == 1);
	REQUIRE(Factorial(2) == 2);
	REQUIRE(Factorial(3) == 6);
	REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE("Polyval x ")
{

	Polynomial p1{0, 1, 1}; // 0x^0+1 x^1 +1x^2
	REQUIRE(polyval(p1, 0) == 0);
	REQUIRE(polyval(p1, 1) == 2);
	REQUIRE(polyval(p1, 2) == 2);
}
TEST_CASE("Polyval vector x ")
{

	Polynomial p1{0, 0, 1}; // 0x^0+1 x^1 +1x^2
	std::vector<double> x(11);
	std::iota(x.begin(), x.end(), 0);
	std::vector<double> v(11);

	for(int i = 0; i < x.size(); i++)
	{
		v[i] = x[i] * x[i];
	}
	REQUIRE(polyval(p1, x) == v);
}
