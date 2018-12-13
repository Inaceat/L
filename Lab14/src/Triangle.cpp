#include "stdafx.h"


#include "DumbGeometry.hpp"


dumb_geometry::Triangle::Triangle(Point a, Point b, Point c) : 
	_a(a),
	_b(b),
	_c(c)
{
	_abLength = sqrt((a.X() - b.X()) * (a.X() - b.X()) + () * ());
	_bcLength = 0;
	_adLength = 0;
}


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
	double halfPerimeter = 

	return 
}
