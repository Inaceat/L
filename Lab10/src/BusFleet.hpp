#pragma once
#include <functional>


struct BusInfo
{
	char* IdentificationNumber;
	char* Model;
	int ProductionYear;
	int SeatingSpace;
	int StandingSpace;
};



BusInfo* LoadFromFile(char* fileName)
{
	//TODO
	return nullptr;
}



void ShowBusInfo(BusInfo* busInfo)
{
	
}


void ShowBusList(BusInfo* busList, size_t listLength)
{
	//TODO
}

void ShowBusList(BusInfo* busList, size_t listLength, std::function<bool(BusInfo*)> selector)
{
	
}



void SortBusList(BusInfo* busList, size_t listLength, std::function<bool(BusInfo*, BusInfo*)> comparer)
{
	
}