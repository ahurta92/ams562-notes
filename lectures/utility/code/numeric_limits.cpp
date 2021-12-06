#include <iostream>
#include <limits>

using namespace std;
int main()
{

	constexpr float min = std::numeric_limits<float>::min(); // smallest positive float
	constexpr double epsilon = numeric_limits<double>::epsilon();
	constexpr double dd = numeric_limits<double>::digits;
	constexpr double df = numeric_limits<float>::digits;
	constexpr double di = numeric_limits<int>::digits;
	constexpr double dll = numeric_limits<long long>::digits;
	constexpr double udll = numeric_limits<unsigned long long>::digits;

	cout << "numeric_limits<float>::min()= " << min << endl;
	cout << "numeric_limits<double>::epsilon()= " << min << endl;
	cout << "numeric_limits<double>::digits= " << dd << endl;
	cout << "numeric_limits<float>::digits= " << df << endl;
	cout << "numeric_limits<int>::digits= " << di << endl;
	cout << "numeric_limits<long long>::digits= " << dll << endl;
	cout << "numeric_limits<unsigned long long>::digits= " << udll << endl;
}
