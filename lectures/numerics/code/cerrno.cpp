#include <cerrno>
#include <cmath>
#include <iostream>
#include <limits>
using namespace std;

void f()
{
	errno = 0; // clear old error state
	sqrt(-1);
	if(errno == EDOM)
		cerr << "sqrt() not defined for negative argument"<<endl;
	errno = 0; // clear old error state
	pow(numeric_limits<double>::max(), 2);
	if(errno == ERANGE)
		cerr << "result of pow() too large to represent as a double";
}

int main()
{
	f();
}
