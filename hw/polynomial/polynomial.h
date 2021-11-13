//
// Created by ahurt on 11/12/2021.
//

#ifndef LECTURE_POLYNOMIAL_H
#define LECTURE_POLYNOMIAL_H
#include <vector>
#include <iostream>

class Polynomial{
private:
	int order;
	 std::vector<double> coeffs;
 public:

	 explicit Polynomial(int o);
	 ~Polynomial() = default;
	 double operator[](int o) const{
		 //return coeffs[o];//.at(o);// no bounds checking
		 return coeffs.at(o);// with bound checking
	 }
	double& operator[](int o) {
		std::cout<<"this one";
		return coeffs.at(o);

	}
	Polynomial(std::initializer_list<double> l );

	int size() const {
		return order;
	}
	auto begin() const{
		return coeffs.begin();
	}
	auto end() const{
		return coeffs.end();
	}
	auto begin() {
		return coeffs.begin();
	}
	auto end() {
		return coeffs.end();
	}


};

std::ostream& operator<<(std::ostream& os,const Polynomial & p1);
#endif //LECTURE_POLYNOMIAL_H
