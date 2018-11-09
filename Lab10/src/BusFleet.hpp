#pragma once


#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <time.h>


struct BusInfo
{
	char* IdentificationNumber;
	char* Model;
	int ProductionYear;
	int SeatingSpace;
	int StandingSpace;
};



BusInfo* CreateBusList(const size_t listLength)
{
	static auto alphabet = "abcdefghijklmnopqrstuvwxyz0123456789";
	
	static size_t alphabetLength = 36;
	static size_t lettersLength = 26;


	srand(time(nullptr));
	
	auto list = new BusInfo[listLength];

	for (size_t i = 0; i < listLength; i++)
	{
		////////////////////////////////////////////////////////////IdentificationNumber
		size_t idLength = rand() % 4 + 5;

		list[i].IdentificationNumber = new char[idLength + 1];
		list[i].IdentificationNumber[idLength] = '\0';
		
		for (size_t idCounter = 0; idCounter < idLength; idCounter++)
			list[i].IdentificationNumber[idCounter] = alphabet[rand() % alphabetLength];


		////////////////////////////////////////////////////////////Model
		size_t modelLength = rand() % 4 + 7;

		list[i].Model = new char[modelLength + 1];
		list[i].Model[modelLength] = '\0';

		for (size_t modelCounter = 0; modelCounter < modelLength; modelCounter++)
			list[i].Model[modelCounter] = alphabet[rand() % lettersLength];


		////////////////////////////////////////////////////////////ProductionYear
		list[i].ProductionYear = rand() % 65 + 1950;


		////////////////////////////////////////////////////////////SeatingSpace
		list[i].SeatingSpace = rand() % 40 + 10;


		////////////////////////////////////////////////////////////StandingSpace
		list[i].StandingSpace = rand() % 101;
	}


	return list;
}

void ClearBusList(BusInfo* busList, size_t listLength)
{
	for (size_t i = 0; i < listLength; i++)
	{
		delete[] busList[i].IdentificationNumber;
		busList[i].IdentificationNumber = nullptr;

		delete[] busList[i].Model;
		busList[i].Model = nullptr;
	}

	delete[] busList;
	busList = nullptr;
}


void ShowBusInfo(BusInfo* busInfo)
{
	std::cout << "ID Number: " << std::setw(10) << busInfo->IdentificationNumber;
	std::cout << "  Model: " << std::setw(10) << busInfo->Model;
	std::cout << "  Prod. year: "<< std::setw(5) << busInfo->ProductionYear;
	std::cout << "  Seats: "<< std::setw(4) << busInfo->SeatingSpace;
	std::cout << "  Standing space: "<< std::setw(4) << busInfo->StandingSpace;

	std::cout << std::endl;
}


void ShowBusList(BusInfo* busList, size_t listLength)
{
	std::cout << "All buses:" << std::endl;


	for (size_t i = 0; i < listLength; i++)
		ShowBusInfo(busList + i);


	std::cout << std::endl << std::endl;
}

void ShowBusList(BusInfo* busList, size_t listLength, std::function<bool(BusInfo*)> selector)
{
	std::cout << "Selected buses:" << std::endl;


	for (size_t i = 0; i < listLength; i++)
		if(selector(busList + i))
			ShowBusInfo(busList + i);


	std::cout << std::endl << std::endl;
}



void SortBusList(BusInfo* busList, size_t listLength, std::function<bool(BusInfo*, BusInfo*)> comparer)
{
	//TODO
}