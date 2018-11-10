#include "stdafx.h"

#include "BusFleet.hpp"


int main()
{
	const size_t listLength = 10;

	auto list = CreateBusList(listLength);

	std::cout << "All buses:" << std::endl;
	ShowBusList(list, listLength);


	std::cout << "Buses with passenger capacity more than 80:" << std::endl;
	ShowBusList(list, listLength, [](BusInfo* item)
	{
		return (item->SeatingSpace + item->StandingSpace) > 80;
	});


	std::cout << "Sorted by Production Year descending:" << std::endl;

	SortBusList(list, listLength, [](BusInfo* left, BusInfo* right)
	{
		return left->ProductionYear - right->ProductionYear;
	});

	ShowBusList(list, listLength);


	ClearBusList(list, listLength);
}