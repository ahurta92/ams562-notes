
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

public:
	// allocates mem on free store
	Vector();
	Vector(int s);
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
	int size() const
	{
		return sz;
	};
	void push_back(T);

private:
	T* elem; // pointing to array of type of T... complex double int
	int sz; //
};

template <typename T>
void print(const Vector<T>& a);
