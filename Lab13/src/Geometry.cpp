#include "stdafx.h"
#include "Geometry.hpp"
#include <utility>
#include <vector>


//////////////////////////////////////////////////////////////////////
geometry2D::Point::Point(): 
	_x(0),
	_y(0)
{}

geometry2D::Point::Point(double x, double y):
	_x(x), 
	_y(y)
{}


double geometry2D::Point::X() const
{
	return _x;
}

double geometry2D::Point::Y() const
{
	return _y;
}



//////////////////////////////////////////////////////////////////////
geometry2D::Circle::Circle(const Point center, const double radius):
	_center(center),
	_radius(radius)
{}

std::vector<geometry2D::Point> geometry2D::Circle::IntersectWith(Line line) const
{
	//Quadratic equation here
	double a = line.A() * line.A() + line.B() * line.B();

	double b = 2 * (line.B() * (line.PointOnLine().X() - _center.X()) - line.A() * (line.PointOnLine().Y() - _center.Y()));//TODO check typecasting

	double c =
		(line.PointOnLine().X() - _center.X()) * (line.PointOnLine().X() - _center.X()) +
		(line.PointOnLine().Y() - _center.Y()) * (line.PointOnLine().Y() - _center.Y()) -
		_radius * _radius;


	double discriminant = b * b - 4 * a*c;

	std::vector<Point> intersection;

	if (discriminant  == 0)//TODO double comparison
	{
		double x = b / (-2 * a);//TODO casting

		intersection.push_back(Point(line.PointOnLine().X() + line.B() * x, line.PointOnLine().Y() - line.A() * x));
	}
	else if(discriminant > 0)
	{
		double x1 = (b + sqrt(discriminant)) / (-2 * a);
		double x2 = (b - sqrt(discriminant)) / (-2 * a);

		intersection.push_back(Point(line.PointOnLine().X() + line.B() * x1, line.PointOnLine().Y() - line.A() * x1));
		intersection.push_back(Point(line.PointOnLine().X() + line.B() * x2, line.PointOnLine().Y() - line.A() * x2));
	}

	return intersection;
}


geometry2D::Point geometry2D::Circle::Center() const
{
	return _center;
}

double geometry2D::Circle::Radius() const
{
	return _radius;
}



//////////////////////////////////////////////////////////////////////
geometry2D::Vector::Vector(): 
	_a1(0),
	_a2(0)
{
}

geometry2D::Vector::Vector(const double a1, const double a2):
	_a1(a1),
	_a2(a2)
{}

geometry2D::Vector::Vector(Point a, Point b)
{
	_a1 = b.X() - a.X();
	_a2 = b.Y() - a.Y();
}


geometry2D::Vector geometry2D::Vector::FindNormal() const
{
	Vector result(_a2, (-1) * _a1);

	return result;
}


double geometry2D::Vector::XComponent() const
{
	return _a1;
}

double geometry2D::Vector::YComponent() const
{
	return _a2;
}



//////////////////////////////////////////////////////////////////////
geometry2D::Line::Line():
	_A(0),
	_B(0),
	_C(0)
{}

geometry2D::Line::Line(Point point, Vector directionVector):
	_pointOnLine(point),
	_directionVector(directionVector)
{
	_A = directionVector.YComponent();
	_B = (-1) * directionVector.XComponent();
	_C = directionVector.XComponent() * point.Y() - directionVector.YComponent() * point.X();
}


double geometry2D::Line::A() const
{
	return _A;
}

double geometry2D::Line::B() const
{
	return _B;
}

double geometry2D::Line::C() const
{
	return _C;
}


geometry2D::Point geometry2D::Line::PointOnLine() const
{
	return _pointOnLine;
}

geometry2D::Vector geometry2D::Line::DirectionVector() const
{
	return _directionVector;
}



//////////////////////////////////////////////////////////////////////
geometry2D::Point geometry2D::Middle(Point left, Point right)
{
	Point middlePoint(
		(left.X() + right.X()) / 2, 
		(left.Y() + right.Y()) / 2
	);

	return middlePoint;
}

double geometry2D::Distance(Point left, Point right)
{
	return std::sqrt((left.X() - right.X()) * (left.X() - right.X()) + (left.Y() - right.Y()) * (left.Y() - right.Y()));
}