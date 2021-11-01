#include "string_to_array.h"

template <typename T>
const T* begin(const Vector<T>& x)
{ // check size if 0 return null else return first elem
	return x.size() ? &x[0] : nullptr;
}

template <typename T>
const T* end(const Vector<T>& x)
{ // check size if 0 return null else return first elem+size()
	return x.size() ? &x[0] + x.size() : nullptr;
}
template <typename T>
T* begin(Vector<T>& x)
{ // check size if 0 return null else return first elem
	return x.size() ? &x[0] : nullptr;
}

template <typename T>
T* end(Vector<T>& x)
{ // check size if 0 return null else return first elem+size()
	return x.size() ? &x[0] + x.size() : nullptr;
}

void write1(const Vector<std::string>& vs)
{
	for(auto& s : vs)
	{
		std::cout << s << "\n";
	}
}

void write2(Vector<std::string>& vs, std::string name)
{
	for(auto& s : vs)
	{
		s = name;
	}
}

int main()
{
	std::string s = "Hi my name is Adrian";
	Vector<std::string> vs = string_to_array(s);
	write(vs);
	write2(vs, "Adrian");
	write(vs);
}
