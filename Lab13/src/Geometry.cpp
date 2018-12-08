#include "stdafx.h"

#include "Geometry.hpp"



geometry2D::Point geometry2D::Middle(Point left, Point right)
{
	Point middlePoint(
		(left.X() + right.X()) / 2, 
		(left.Y() + right.Y()) / 2
	);

	return middlePoint;
}

double geometry2D::Distance(Point left, Point right)
{
	return std::sqrt((left.X() - right.X()) * (left.X() - right.X()) + (left.Y() - right.Y()) * (left.Y() - right.Y()));
}