#include "stdafx.h"


#include "DumbGeometry.hpp"


dumb_geometry::Trapeze::Trapeze(Point a, Point b, Point c, Point d)
{
	double geometryDoubleEpsilon = 0.0001;

	//BC || AD when vectors are parallel
	double bcX = b.X() - c.X();
	double bcY = b.Y() - c.Y();

	double adX = a.X() - d.X();
	double adY = a.Y() - d.Y();

	if (bcX / adX - bcY / adY < geometryDoubleEpsilon)//**** this double comparison!
	{
		_a = a;
		_b = b;
		_c = c;
		_d = d;
	}
}


dumb_geometry::Point dumb_geometry::Trapeze::A() const
{
	return _a;
}

dumb_geometry::Point dumb_geometry::Trapeze::B() const
{
	return _b;
}

dumb_geometry::Point dumb_geometry::Trapeze::C() const
{
	return _c;
}

dumb_geometry::Point dumb_geometry::Trapeze::D() const
{
	return _d;
}

double dumb_geometry::Trapeze::Area()
{
	return 0.0;
}
