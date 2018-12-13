#include "stdafx.h"

#include <ostream>
#include <istream>

#include "Geometry.hpp"



geometry2D::Point::Point() :
	_x(0),
	_y(0)
{}

geometry2D::Point::Point(double x, double y) :
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


std::istream& geometry2D::operator>>(std::istream& stream, Point& point)
{
	stream >> point._x >> point._y;

	return stream;
}

std::ostream& geometry2D::operator<<(std::ostream& stream, Point& point)
{
	stream << "Point(" << point._x << ", " << point._y << ")";

	return stream;
}