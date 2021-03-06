#include "stdafx.h"

#include "BusFleet.hpp"


int main()
{
	BusFleet list("data/data.txt");


	std::cout << "All buses:" << std::endl;
	std::cout << list << std::endl;


	std::cout << "Buses with passenger capacity more than 80:" << std::endl;
	
	BusFleet selected = list.Select([](const BusInfo& item)
	{
		return (item.SeatingSpace() + item.StandingSpace()) > 80;
	});

	std::cout << selected << std::endl;


	std::cout << "Sorted by Production Year descending:" << std::endl;

	list.Sort([](const BusInfo& left, const BusInfo& right)
	{
		return left.ProductionYear() - right.ProductionYear();
	});

	list.Save("data/sorted.txt");

	std::cout << list;
}
