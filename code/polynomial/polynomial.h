//
// Created by ahurt on 11/12/2021.
//

#ifndef LECTURE_POLYNOMIAL_H
#define LECTURE_POLYNOMIAL_H
#include <cmath>
#include <iostream>
#include <vector>

class Polynomial
{
private:
	// representation is order and vector holding coeffs
	int order;
	std::vector<double> coeffs;

public:
	explicit Polynomial(int o);
	const double operator[](int o) const
	{
		//return coeffs[o];//.at(o);// no bounds checking
		return coeffs.at(o); // with bound checking
	}
	double& operator[](int o)
	{
		std::cout << "this one";
		return coeffs.at(o);
	}
	Polynomial(const Polynomial& p1)
		: order{p1.order}
		, coeffs{p1.coeffs}
	{
		std::cout << "copy constructor" << std::endl;
	}
	Polynomial& operator=(const Polynomial& p1)
	{ // this is default
		order = p1.order;
		coeffs = p1.coeffs;
		std::cout << "copy assignment" << std::endl;
		return *this;
	}

	Polynomial& operator=(Polynomial&& p1)
	{
		order = p1.size();
		coeffs = std::move(p1.coeffs);
		std::cout << "operator=(&&p)";
		return *this;
	}
	Polynomial(std::initializer_list<double> l);
	int size() const
	{
		return order;
	}
	auto begin() const
	{
		return coeffs.begin();
	}
	auto end() const
	{
		return coeffs.end();
	}
	auto begin()
	{
		return coeffs.begin();
	}
	auto end()
	{
		return coeffs.end();
	}
};

double polyval(Polynomial p, double x);
std::vector<double> polyval(Polynomial p, const std::vector<double>& x);

std::ostream& operator<<(std::ostream& os, const Polynomial& p1);
#endif //LECTURE_POLYNOMIAL_H
