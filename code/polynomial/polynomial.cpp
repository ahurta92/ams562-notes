//
// Created by adrianhurtado on 11/15/21.
//

#include "polynomial.h"

Polynomial::Polynomial(std::initializer_list<double> l)
	: order{static_cast<int>(l.size())}
	, coeffs{std::vector<double>(order)}
{
	std::cout << "list constructor<<" << std::endl;
	std::copy(l.begin(), l.end(), coeffs.begin());
}
std::ostream& operator<<(std::ostream& os, const Polynomial& p1)
{
	os << "[ ";
	for(const auto& e : p1)
	{
		os << e << " ";
	}
	os << "]";
	return os;
}

double polyval(Polynomial p, double x)
{
	double val = 0;
	double prev = 1;
	for(int i = 0; i < p.size(); i++)
	{
		val += p[i] * prev;
		prev *= x;
	}
	return val;
}
std::vector<double> polyval(Polynomial p, const std::vector<double>& x)
{
	std::vector<double> result(x.size());
	double px;
	auto ri = result.begin();
	for(auto& xi : x)
	{
		px = polyval(p, xi);
		*ri = px;
		ri++;
	}
	return result;

	// hold
}
