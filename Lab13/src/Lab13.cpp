#include "stdafx.h"
#include "Geometry.hpp"
#include <iostream>


void TaskTheOnly()
{
	geometry2D::Point a,b;
	double radius = 2;

	std::cout << "Points:" << std::endl;
	//std::cin >> a >> b;

	std::cout << "Circle radius:" << std::endl;
	//std::cin >> radius;


	//1. Middle between a & b == m
	geometry2D::Point middlePoint = Middle(a, b);

	//2. Line through m, _|_ to ab
	geometry2D::Line middleLine(middlePoint, geometry2D::Vector(a, b).FindNormal());

	//3. r^2 - |a-b|^2 == d^2 -- distance to centers of circles
	double fromMiddleToInputPoints = Distance(a, middlePoint);
	double fromMiddleToCirclesCenters = std::sqrt(radius * radius - fromMiddleToInputPoints * fromMiddleToInputPoints);

	//4. Da circle!!!111
	geometry2D::Circle circle(middlePoint, fromMiddleToCirclesCenters);

	//5. Cirle centers are intersections of line 2. and circle 4.
	auto circleCenters = circle.IntersectWith(middleLine);

	//
}


int main()
{
	TaskTheOnly();

    return 0;
}