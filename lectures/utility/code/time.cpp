#include "examples.h"

int main()
{
	using namespace std::chrono;
	auto t0 = chrono::high_resolution_clock::now();
	do_work();
	auto t1 = chrono::high_resolution_clock::now();
	cout << chrono::duration_cast<milliseconds>(t1 - t0).count() << "msec\n";
}
