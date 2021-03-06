#include "stdafx.h"

#include "DumbGeometry.hpp"
#include <iostream>
using namespace dumb_geometry;



int main()
{
	//Test drawings here:
	//https://www.desmos.com/calculator/5yxxygwdtp

	Triangle triangle({ 0, 0 }, { 1, 1 }, { 0, 1.25 });
	Trapeze trapeze({ 0, 0 }, { 0.5, 1 }, { 1.125, 1 }, { 1.25, 0 });

	std::list<IAreaProvider*> shapes = { &triangle, &trapeze};


	size_t i = 0;
	for (auto shape : shapes)
		std::cout << i++ << ":\t area = " << shape->Area() << std::endl;


    return 0;
}