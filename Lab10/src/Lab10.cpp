#include "stdafx.h"

#include "BusFleet.hpp"


int main()
{
	std::string id = "Qwerty";
	std::string model = "H1";
	int prodYear = 1993;
	int seats = 30;
	int stands = 80;




	BusFleet list("random");

	std::cout << list;


	BusFleet sel = list.Select([](const BusInfo& item)
	{
		return (item.SeatingSpace() + item.StandingSpace()) > 80;
	});

	/*list.Sort([](const BusInfo& left, const BusInfo& right)
	{
		return left.ProductionYear() - right.ProductionYear();
	});*/

	std::cout << std::endl << std::endl << sel;



	std::cout << "All buses:" << std::endl;

	std::cout << "Buses with passenger capacity more than 80:" << std::endl;

	std::cout << "Sorted by Production Year descending:" << std::endl;
}
