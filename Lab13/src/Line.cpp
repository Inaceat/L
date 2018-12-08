#include "stdafx.h"

#include "Geometry.hpp"



geometry2D::Line::Line() :
	_A(0),
	_B(0),
	_C(0)
{}

geometry2D::Line::Line(Point point, Vector directionVector) :
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