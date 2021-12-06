//
// Created by adrianhurtado on 11/15/21.
//

#include "polynomial.h"

Polynomial f(double c0, double c1, double c2)
{
	Polynomial p1{c0, c1, c2};

	return p1;
}

int main()
{

	try
	{
		Polynomial p1{0, 1, 1}; // 0x^0+1 x^1 +1x^2
		std::cout << p1 << std::endl;
		//p1 = f(2, 1, 1);
		//std::cout << p1;
		std::cout << polyval(p1, 0) << std::endl;
		std::cout << polyval(p1, 1) << std::endl;
		std::cout << polyval(p1, 2) << std::endl;
	}
	catch(std::out_of_range& e)
	{
		std::cerr << "out of range: " << e.what() << std::endl;
	}
	catch(...)
	{
		std::cerr << "unknown error" << std::endl;
	}
}
