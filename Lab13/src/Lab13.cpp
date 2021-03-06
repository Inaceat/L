#include "stdafx.h"

#include <iostream>
#include <list>

#include "Geometry.hpp"
using namespace geometry2D;


void TaskTheOnly()
{
	Point a(3.258, 2.983);
	Point b(4.742, 0.017);
	double radius = 2;

	std::cout << "Points:" << std::endl <<  a << std::endl << b << std::endl;
	//std::cin >> a >> b;

	std::cout << "Circle radius:" << radius << std::endl << std::endl;
	//std::cin >> radius;


	//1. Middle between a & b == m
	auto middlePoint = Middle(a, b);

	//2. Line through m, perpend. to ab
	Line middleLine(middlePoint, Vector(a, b).FindPerpendicularVector());

	//3. r^2 - |a-b|^2 == d^2 -- distance to centers of circles
	double fromMiddleToInputPoints = Distance(a, middlePoint);
	double fromMiddleToCirclesCenters = std::sqrt(radius * radius - fromMiddleToInputPoints * fromMiddleToInputPoints);

	//4. Create an auxiliary circle:
	Circle circle(middlePoint, fromMiddleToCirclesCenters);

	//5. Cirle centers are intersections of line 2. and circle 4.
	auto circleCenters = circle.IntersectWith(middleLine);

	//6. Constructing circles:
	std::list<Circle> circles;
	
	for (size_t i = 0; i < circleCenters.size(); i++)
		circles.push_back(Circle(circleCenters[i], radius));

	//7. M'key, show'em
	for (auto& element : circles)
		std::cout << element << std::endl;



	std::cout << "Vectors demo:" << std::endl;

	Vector vect1;
	std::cin >> vect1;

	Vector vect2;
	std::cin >> vect2;

	Vector vSumm = vect1 + vect2;
	std::cout << vect1 << " + " << vect2 << " == " << vSumm << std::endl << std::endl;

	Vector vDiff = vect1 - vect2;
	std::cout << vect1 << " - " << vect2 << " == " << vDiff << std::endl << std::endl;

	Vector vScalarMulti = vect1 * 4.2;
	std::cout << vect1 << " x " << 4.2 << " == " << vScalarMulti << std::endl << std::endl ;

	double vScalarProduct = vect1 * vect2;
	std::cout << vect1 << " * " << vect2 << " == " << vScalarProduct << std::endl << std::endl;
}


int main()
{
	TaskTheOnly();

    return 0;
}