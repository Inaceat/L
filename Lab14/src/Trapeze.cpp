#include "stdafx.h"


#include "DumbGeometry.hpp"
#include <valarray>


dumb_geometry::Trapeze::Trapeze(Point a, Point b, Point c, Point d)
{
	double geometryDoubleEpsilon = 0.0001;

	//BC || AD when vectors are parallel
	double bcX = b.X() - c.X();
	double bcY = b.Y() - c.Y();

	double adX = a.X() - d.X();
	double adY = a.Y() - d.Y();

	// bcX    bcY
	// --- == ---
	// adX	  adY
	if (bcX * adY - bcY * adX < geometryDoubleEpsilon)//**** this double comparison!
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
	double ab = Distance(_a, _b);
	double bc = Distance(_b, _c);//top, || da
	double cd = Distance(_c, _d);
	double da = Distance(_d, _a);//bottom, || bc

	//SemiPerimeter of trapeze
	double s = (ab + bc + cd + da) / 2;


	return std::sqrt((s - bc) * (s - da) * (s - da - ab) * (s - da - cd)) * (bc + da) / std::abs(bc - da);
}