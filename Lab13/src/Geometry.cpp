#include "stdafx.h"
#include "Geometry.hpp"


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

geometry2D::Line::Line(Point point, Vector directionVector)
{
	_A = directionVector.YComponent();
	_B = (-1) * directionVector.XComponent();
	_C = directionVector.XComponent() * point.Y() - directionVector.YComponent() * point.X();
}


geometry2D::Vector geometry2D::Line::DirectionalVector() const
{

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