#include "stdafx.h"
#include "Geometry.hpp"
#include <iostream>


void TaskTheOnly()
{
	geometry2D::Point a,b;
	double radius;

	std::cout << "Points:" << std::endl;
	//std::cin >> a >> b;

	std::cout << "Circle radius:" << std::endl;
	//std::cin >> radius;


	//1. Middle between a & b == m
	geometry2D::Point m = Middle(a, b);

	//2. Line through m, _|_ to ab
	geometry2D::Line veryGoodLine(m, geometry2D::Vector(a, b).FindNormal());

	//3. r^2 - |a-b|^2 == d^2 -- distance to centers of circles


	//4. Cirle centers lie on 2. line
}


int main()
{
	TaskTheOnly();

    return 0;
}