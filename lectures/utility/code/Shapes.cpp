#include "Shapes.h"
#include "examples.h"

// function to vector of pointers to shape passed by reference
// no matter the type of shape we can call rotate
void rotate_all(std::vector<Shape*>& v,
				int angle) // rotate v's elements by angle degrees
{
	for(auto p : v)
		p->rotate(angle);
}
Circle::Circle(Point p, int rad)
	: x{p}
	, r{rad}
{}
void Circle::draw() const
{
	cout << "drawing circle" << std::endl;
}
void Triangle::draw() const
{
	cout << "drawing triangle" << std::endl;
}
Triangle::Triangle(Point p, int rad)
	: x{p}
	, r{rad}
{}
void Square::draw() const
{
	cout << "drawing square" << std::endl;
}
Square::Square(Point p, int rad)
	: x{p}
	, r{rad}
{}

void Smiley::draw() const
{
	Circle::draw();
	for(const auto& p : eyes)
		p->draw();
	mouth->draw();
}

enum class Kind
{
	circle,
	triangle,
	smiley
};
