
#include <exception>
#include <iostream>

class Vector_size_mismatch : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Vector sizes do not match";
	}
};

template <typename T>
class Vector
{
private:
	T* elem; // pointing to array of type of T... complex double int
	T* space; // pointing to first unused( and uninitialized) slot
	T* last; // pointer to the last slot

public:
	int size() const
	{
		return space - elem;
	}; //(space-elem)
	int capacity() const
	{
		return last - elem;
	}; //

	void reserve(int newsz);

	void push_back(const T& t);
	void push_back(T&& t);
	// allocates mem on free store
	Vector();
	Vector(int n);
	~Vector()
	{
		delete[] elem;
	}
	Vector(const Vector& a); // copy constructor X x(v);
	Vector& operator=(const Vector& a); // copy assignment  x=v;

	Vector(Vector&& a); // move constructor
	Vector& operator=(Vector&& a); // move assignment

	Vector(std::initializer_list<T> l);
	T& operator[](int i)
	{
		return elem[i];
	}
	const T& operator[](int i) const
	{
		return elem[i];
	}

	T* begin()
	{ // check size if 0 return null else return first elem
		return size() ? &elem[0] : nullptr;
	}

	T* end()
	{ // check size if 0 return null else return first elem+size()
		return size() ? &elem[0] + size() : nullptr;
	}
	T* begin() const
	{ // check size if 0 return null else return first elem
		return size() ? &elem[0] : nullptr;
	}

	T* end() const
	{ // check size if 0 return null else return first elem+size()
		return size() ? &elem[0] + size() : nullptr;
	}
};

template <typename T>
void print(const Vector<T>& a);

template <typename T>
Vector<T>::Vector()
	: elem{nullptr}
	, last{nullptr}
	, space{nullptr}
{}
// takes in an integer
// capacity array size capacity
//
template <typename T>
Vector<T>::Vector(int n)
	: elem{new T[2 * n]}
	, space{elem + n}
	, last{elem + (2 * n)}
{

	for(int i = 0; i != size(); ++i)
	{
		elem[i] = T();
	}
}
// copy constructor

template <typename T>
Vector<T>::Vector(const Vector& a)
	: elem{new T[a.capacity()]}
	, space{elem + a.size()}
	, last{elem + a.capacity()}
{
	for(int i = 0; i != size(); ++i)
		elem[i] = a.elem[i];
}

// copy assignment: clean up target and copy
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& a)
{
	T* p = new T[a.capacity()];
	for(int i = 0; i != a.size(); ++i)
	{
		p[i] = a.elem[i];
	}
	delete[] elem; // delete resource this is pointing to
	elem = p;
	space = elem + size();
	last = elem + capacity();
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
void Vector<T>::push_back(const T& t)
{
	if(capacity() < size() + 1) // make sure we have enough space
		reserve(size() == 0 ? 8 : 2 * size()); //double the capacity

	new(space) T{};
	++space;
}

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
