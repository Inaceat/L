#pragma once


#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

#include "BusInfo.hpp"




class BusFleet
{
public:
	BusFleet();

	BusFleet(BusInfo* list, size_t size);

	BusFleet(const std::string& fileName);


	BusFleet(const BusFleet& other);

	BusFleet(BusFleet&& other) noexcept;


	BusFleet& operator=(const BusFleet& other);

	BusFleet& operator=(BusFleet&& other) noexcept;


	~BusFleet();

public:
	
	void Show();

	BusFleet Select(const std::function<bool(const BusInfo&)>& selector);

	void Sort(const std::function<int(BusInfo*, BusInfo*)>& comparer);

private:
	BusInfo* _list;
	size_t _size;
};




BusInfo* CreateBusList(const size_t listLength);

void ClearBusList(BusInfo* busList, size_t listLength);


void ShowBusInfo(BusInfo* busInfo);


void ShowBusList(BusInfo* busList, size_t listLength);

void ShowBusList(BusInfo* busList, size_t listLength, std::function<bool(BusInfo*)> selector);


void SortBusList(BusInfo* busList, size_t listLength, std::function<int(BusInfo*, BusInfo*)> comparer);