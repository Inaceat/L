#include "stdafx.h"

#include "BusFleet.hpp"


int main()
{
	std::string id = "Qwerty";
	std::string model = "H1";
	int prodYear = 1993;
	int seats = 30;
	int stands = 80;



	


	BusInfo info1;// (id, model, prodYear, seats, stands);


	std::cin >> info1;


	std::cout << info1;



	const size_t listLength = 10;

	//auto list = CreateBusList(listLength);

	std::cout << "All buses:" << std::endl;
	//ShowBusList(list, listLength);


	std::cout << "Buses with passenger capacity more than 80:" << std::endl;
	/*ShowBusList(list, listLength, [](BusInfo* item)
	{
		return (item->SeatingSpace() + item->StandingSpace()) > 80;
	});*/


	std::cout << "Sorted by Production Year descending:" << std::endl;

	/*SortBusList(list, listLength, [](BusInfo* left, BusInfo* right)
	{
		return left->ProductionYear() - right->ProductionYear();
	});*/
	/*
	ShowBusList(list, listLength);


	ClearBusList(list, listLength);*/
}
