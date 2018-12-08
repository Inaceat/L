#include "stdafx.h"


#include "Geometry.hpp"



geometry2D::Circle::Circle(const Point center, const double radius) :
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

	if (discriminant == 0)//TODO double comparison
	{
		double x = b / (-2 * a);//TODO casting

		intersection.push_back(Point(line.PointOnLine().X() + line.B() * x, line.PointOnLine().Y() - line.A() * x));
	}
	else if (discriminant > 0)
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


std::ostream& geometry2D::operator<<(std::ostream& stream, Circle& circle)
{
	stream << "Circle with R = " << circle._radius << " and center in " << circle._center << ")";

	return stream;
}