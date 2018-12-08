#include "stdafx.h"

#include "Geometry.hpp"



geometry2D::Vector::Vector() :
	_a1(0),
	_a2(0)
{}

geometry2D::Vector::Vector(const double a1, const double a2) :
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

geometry2D::Vector geometry2D::Vector::operator+(const Vector & right) const
{
	return Vector(_a1 + right._a1, _a2 + right._a2);
}