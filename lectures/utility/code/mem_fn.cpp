#include <algorithm>
#include "Shapes.h"

void draw_all(vector<Shape*>& v)
{
	for_each(v.begin(), v.end(), mem_fun(&Shape::draw));
}

int main()
{

	vector<Shape*> v;
	v.push_back(new Circle({0, 0}, 3));
	v.push_back(new Triangle({0, 0}, 3));
	v.push_back(new Triangle({0, 0}, 3));
	v.push_back(new Square({0, 0}, 3));
	v.push_back(new Square({0, 0}, 3));
	v.push_back(new Circle({0, 0}, 3));
	v.push_back(new Square({0, 0}, 3));
	v.push_back(new Triangle({0, 0}, 3));
	v.push_back(new Circle({0, 0}, 3));
	v.push_back(new Triangle({0, 0}, 3));
	v.push_back(new Square({0, 0}, 3));
	v.push_back(new Circle({0, 0}, 3));
	v.push_back(new Square({0, 0}, 3));
	draw_all(v);
}
