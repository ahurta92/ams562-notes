#include "examples.h"

struct Point
{
	double xp, yp;
	Point(double x, double y)
		: xp(x)
		, yp(y)
	{} // default constructor
};

class Shape
{
public:
	virtual Point center() const = 0; // pure virtual
	virtual void move(Point to) = 0;

	virtual void draw() const = 0; // draw on "Canvas"
	virtual void rotate(int angle) = 0;

	virtual ~Shape() {} // destructor
	//
};

// function to vector of pointers to shape passed by reference
// no matter the type of shape we can call rotate
void rotate_all(std::vector<Shape*>& v,
				int angle); // rotate v's elements by angle degrees

class Triangle : public Shape
{
public:
	Triangle(Point p, int rad); // Constructor

	Point center() const override
	{
		return x;
	}
	void move(Point to) override
	{
		x = to;
	}
	void draw() const override;
	void rotate(int) override {}

private:
	Point x; // center
	int r; // radius
};
class Square : public Shape
{
public:
	Square(Point p, int rad); // Constructor

	Point center() const override
	{
		return x;
	}
	void move(Point to) override
	{
		x = to;
	}
	void draw() const override;
	void rotate(int) override {}

private:
	Point x; // center
	int r; // radius
};
class Circle : public Shape
{
public:
	Circle(Point p, int rad); // Constructor

	Point center() const override
	{
		return x;
	}
	void move(Point to) override
	{
		x = to;
	}
	void draw() const override;
	void rotate(int) override {}

private:
	Point x; // center
	int r; // radius
};

class Smiley : public Circle
{
public:
	Smiley(Point p, int rad)
		: Circle{p, rad}
		, mouth{nullptr}
	{}
	// Circle with p center and radius r
	~Smiley() {}
	void move(Point to) override;

	void draw() const override;
	void rotate(int) override;
	void add_eye(Shape* s)
	{
		eyes.push_back(static_cast<unique_ptr<Shape>>(s));
	}
	void set_mouth(Shape* s);
	virtual void wink(int i);

private:
	std::vector<unique_ptr<Shape>> eyes;
	unique_ptr<Shape> mouth;
};
