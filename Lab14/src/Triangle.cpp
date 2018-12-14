#include "stdafx.h"


#include "DumbGeometry.hpp"


dumb_geometry::Triangle::Triangle(Point a, Point b, Point c) : 
	_a(a),
	_b(b),
	_c(c)
{}


std::list<dumb_geometry::Point> dumb_geometry::Triangle::GetPoints() const
{
	return {_a, _b, _c};
}

dumb_geometry::Point dumb_geometry::Triangle::A() const
{
	return _a;
}

dumb_geometry::Point dumb_geometry::Triangle::B() const
{
	return _b;
}

dumb_geometry::Point dumb_geometry::Triangle::C() const
{
	return _c;
}


double dumb_geometry::Triangle::Area()
{
	double abLength = Distance(_a, _b);
	double bcLength = Distance(_b, _c);
	double acLength = Distance(_a, _c);

	double semiPerimeter = (abLength + bcLength + acLength) / 2;

	return std::sqrt(semiPerimeter * (semiPerimeter - abLength) * (semiPerimeter - bcLength) * (semiPerimeter - acLength));
}