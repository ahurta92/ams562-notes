#include <algorithm>
#include <functional>
#include "Shapes.h"

void draw_all(vector<Shape*>& v)
{
	for_each(v.begin(), v.end(), [](Shape* p) { p->draw(); });
}
struct f
{
	auto operator()(Shape* p)
	{
		p->draw();
	};
};
int main()
{
	auto lp = [](Shape* p) { p->draw(); };

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
	auto p = f();
	function<void(Shape*)> p2 = p;
	function<void(Shape*)> lp2 = lp;
	cout << "  p  " << std::endl;
	for_each(v.begin(), v.end(), p);
}
