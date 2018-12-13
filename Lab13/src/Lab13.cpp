#include "stdafx.h"

#include <iostream>
#include <list>

#include "Geometry.hpp"



void TaskTheOnly()
{
	geometry2D::Point a(3.258, 2.983);
	geometry2D::Point b(4.742, 0.017);
	double radius = 2;

	std::cout << "Points:" << std::endl <<  a << std::endl << b << std::endl;
	//std::cin >> a >> b;

	std::cout << "Circle radius:" << radius << std::endl << std::endl;
	//std::cin >> radius;


	//1. Middle between a & b == m
	geometry2D::Point middlePoint = Middle(a, b);

	//2. Line through m, perpend. to ab
	geometry2D::Line middleLine(middlePoint, geometry2D::Vector(a, b).FindPerpendicularVector());

	//3. r^2 - |a-b|^2 == d^2 -- distance to centers of circles
	double fromMiddleToInputPoints = Distance(a, middlePoint);
	double fromMiddleToCirclesCenters = std::sqrt(radius * radius - fromMiddleToInputPoints * fromMiddleToInputPoints);

	//4. Create an auxiliary circle:
	geometry2D::Circle circle(middlePoint, fromMiddleToCirclesCenters);

	//5. Cirle centers are intersections of line 2. and circle 4.
	auto circleCenters = circle.IntersectWith(middleLine);

	//6. Constructing circles:
	std::list<geometry2D::Circle> circles;
	
	for (size_t i = 0; i < circleCenters.size(); i++)
		circles.push_back(geometry2D::Circle(circleCenters[i], radius));

	//7. M'key, show'em
	for (auto& element : circles)
		std::cout << element << std::endl;
}


int main()
{
	TaskTheOnly();

    return 0;
}