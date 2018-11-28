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

	BusFleet& operator=(const BusFleet& other);


	~BusFleet();


public:

	friend void swap(BusFleet& left, BusFleet& right) noexcept;


	friend std::ostream& operator<<(std::ostream& ostream, const BusFleet& item);

	friend std::istream& operator>>(std::istream& istream, BusFleet& item);


	BusFleet Select(const std::function<bool(const BusInfo&)>& selector) const;

	void Sort(const std::function<int(const BusInfo&, const BusInfo&)>& comparer);


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