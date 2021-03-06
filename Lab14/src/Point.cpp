#include "stdafx.h"

#include <ostream>
#include <istream>

#include "DumbGeometry.hpp"
#include <valarray>


dumb_geometry::Point::Point() :
	_x(0),
	_y(0)
{}

dumb_geometry::Point::Point(double x, double y) :
	_x(x),
	_y(y)
{}


double dumb_geometry::Point::X() const
{
	return _x;
}

double dumb_geometry::Point::Y() const
{
	return _y;
}


std::istream& dumb_geometry::operator>>(std::istream& stream, Point& point)
{
	stream >> point._x >> point._y;

	return stream;
}

std::ostream& dumb_geometry::operator<<(std::ostream& stream, Point& point)
{
	stream << "Point(" << point._x << ", " << point._y << ")";

	return stream;
}


double dumb_geometry::Distance(Point left, Point right)
{
	return std::sqrt((left.X() - right.X()) * (left.X() - right.X()) + (left.Y() - right.Y()) * (left.Y() - right.Y()));
}