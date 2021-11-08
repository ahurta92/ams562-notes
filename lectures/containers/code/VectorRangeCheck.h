//
// Created by adrian on 11/4/21.
//

#ifndef LECTURE_VECTORRANGECHECK_H
#define LECTURE_VECTORRANGECHECK_H
#include <vector>
using namespace std;
template <typename T>
class Vec : public ::std::vector<T>
{
public:
	using vector<T>::vector; // use the constructors from vector(under name Vec)
	T& operator[](int i)
	{ // range check
		return vector<T>::at(i);
	}
	const T& operator[](int i) const
	{ // range check const objects
		return vector<T>::at(i);
	}
};

#endif //LECTURE_VECTORRANGECHECK_H
