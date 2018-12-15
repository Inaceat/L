#pragma once


#include <functional>
#include <string>
#include <fstream>


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
	
	friend std::ifstream& operator>>(std::ifstream& ifstream, BusFleet& item);
	

	void Save(const std::string& fileName) const;

	BusFleet Select(const std::function<bool(const BusInfo&)>& selector) const;

	void Sort(const std::function<int(const BusInfo&, const BusInfo&)>& comparer);


private:
	BusInfo* _list;
	size_t _size;
};