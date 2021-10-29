#include "VectorT.h"

template <typename T>
Vector<T>::Vector()
	: elem{nullptr}
	, sz{0}
{}

template <typename T>
Vector<T>::Vector(int s)
	: elem{new T[sz]}
	, sz{s}
{}
// copy constructor

template <typename T>
Vector<T>::Vector(const Vector& a)
	: elem{new T[a.sz]}
	, sz{a.sz}
{
	for(int i = 0; i != sz; ++i)
		elem[i] = a.elem[i];
}
// copy assignment: clean up target and copy
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& a)
{
	T* p = new T[a.sz];
	for(int i = 0; i != a.sz; ++i)
	{
		p[i] = a.elem[i];
	}
	delete[] elem; // delete resource this is pointing to
	elem = p;
	sz = a.sz;
	return *this; // predefined in a member function
}

template <typename T>
Vector<T>::Vector(Vector&& a)
	: elem{a.elem}
	, sz{a.sz}
{
	std::cout << "called move constructor" << std::endl;
	a.elem = nullptr;
	a.sz = 0;
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& a)
{
	std::cout << "called move assignment" << std::endl;

	delete[] elem; // delete current mem
	elem = a.elem; // copy pointer from r-v ref which contains mem
	sz = a.sz; // copy size
	a.elem = nullptr;
	a.sz = 0;
	return *this;

} // move assignment

template <typename T>
Vector<T>::Vector(std::initializer_list<T> l)
	: elem{new T[l.size()]}
	, sz{static_cast<int>(l.size())}
{
	std::copy(l.begin(), l.end(), elem);
}

template <typename T>
void Vector<T>::push_back(T d)
{
	T* new_elem;
	// allocate sz+1 doubles in heap
	new_elem = new T[sz + 1];
	// copy current doubles into mem
	for(int i = 0; i != sz; ++i)
	{
		new_elem[i] = elem[i];
	}
	new_elem[sz] = d;
	delete[] elem;
	elem = new_elem;
	// add one to sz
	sz += 1;
}; // add element at end increase size by one

template <typename T>
Vector<T> operator+(const Vector<T>& a, const Vector<T>& b)
{
	if(a.size() != b.size())
		throw Vector_size_mismatch{};
	Vector<T> res(a.size());
	for(int i = 0; i != a.size(); ++i)
	{
		res[i] = a[i] + b[i];
	}
	return res;
}
// Helper Function
template <typename T>
void print(const Vector<T>& a)
{
	std::cout << "v: ";
	for(int i = 0; i != a.size(); ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}
