// extract to string
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include "VectorT.h"

// Create a spherePoint class
// Representation x,y,z
// Create a SphereVector Class
//
class SpherePoint
{
private:
	double xx, yy, zz;

public:
	// default constructor
	SpherePoint()
		: xx{1}
		, yy{0}
		, zz{0}
	{}
	// phi [ 0 pi]
	SpherePoint(double theta, double phi)
		: xx{cos(theta) * sin(phi)}
		, yy{sin(theta) * sin(phi)}
		, zz{cos(phi)}
	{}
	// Return x,y,z
	double x() const
	{
		return xx;
	};
	double y() const
	{
		return yy;
	};
	double z() const
	{
		return zz;
	};
};
// implement
// Change this function to take in a template specialization
SpherePoint* generate_Nrandom_SpherePoint(int N)
{

	SpherePoint* pts = new SpherePoint[N];

	srand(time(NULL));
	for(int i = 0; i < N; i++)
	{
		double theta = ((double)rand() / (double)RAND_MAX) * (2 * M_PI);
		double phi = ((double)rand() / (double)RAND_MAX) * (M_PI);
		pts[i] = SpherePoint(theta, phi);
	}
	return pts;
}

void print(SpherePoint p)
{
	std::cout << p.x() << " " << p.y() << " " << p.z() << std::endl;
}

double circle_length(SpherePoint a, SpherePoint b)
{
	double arc_len{0};
	double l12 = a.x() + b.x() + a.y() + b.y() + a.z() + b.z();
	return acos(l12);
}

int main()
{

	int N = 10000;

	Vector<SpherePoint> pts(N);
	double max_len = 0;
	double min_len = 2 * M_PI;
	double len_i;
	for(int i = 1; i < N; ++i)
	{
		// print(pts[i]);
		len_i = circle_length(pts[0], pts[i]);
		if(len_i > max_len)
		{
			max_len = len_i;
		}
		if(len_i < min_len)
		{
			min_len = len_i;
		}
	}
	std::cout << "The max circle length amoungs " << N << " points = " << max_len << std::endl;
	std::cout << "The max circle length amoungs " << N << " points = " << min_len;

	return 0;
}
