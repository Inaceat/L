#include "stdafx.h"

#include "BusFleet.hpp"



BusFleet::BusFleet(): 
	_list(nullptr), 
	_size(0)
{}

BusFleet::BusFleet(const BusFleet& other)
{
	_size = other._size;

	if (other._size > 0)
	{
		_list = new BusInfo[other._size];

		std::copy(other._list, other._list + other._size, _list);
	}
	else
		_list = nullptr;
}

BusFleet& BusFleet::operator=(const BusFleet& other)
{
	BusFleet tmp(other);

	swap(*this, tmp);

	return *this;
}


BusFleet::~BusFleet()
{
	delete[] _list;
	_list = nullptr;

	_size = 0;
}




BusFleet::BusFleet(BusInfo* list, size_t size)
{
	_size = size;
	_list = new BusInfo[size];

	std::copy(list, list + size, _list);
}

BusFleet::BusFleet(const std::string& fileName):
	_size(0),
	_list(nullptr)
{
	std::ifstream stream(fileName);

	stream >> *this;

	stream.close();
}




void swap(BusFleet& left, BusFleet& right) noexcept
{
	using std::swap;

	swap(left._list, right._list);
	swap(left._size, right._size);
}


std::ostream& operator<<(std::ostream& ostream, const BusFleet& item)
{
	for (size_t i = 0; i < item._size; i++)
		ostream << item._list[i];

	return ostream;
}


std::ifstream& operator>>(std::ifstream& ifstream, BusFleet& item)
{
	std::vector<BusInfo> readData;


	BusInfo readInfo;

	while(ifstream.eof() == false)
	{
		ifstream >> readInfo;

		readData.push_back(readInfo);
	}

	item = BusFleet(readData.data(), readData.size());

	return ifstream;
}


void BusFleet::Save(const std::string& fileName) const
{
	std::ofstream stream(fileName, std::fstream::out);

	if (_size > 0)
	{
		for (size_t i = 0; i < _size - 1; i++)
			stream << _list[i].ToCsv() << '\n';

		stream << _list[_size - 1].ToCsv();
	}

	stream.close();
}

BusFleet BusFleet::Select(const std::function<bool(const BusInfo&)>& selector) const
{
	std::vector<BusInfo> selectedItems;

	for (size_t i = 0; i < _size; i++)
		if (selector(_list[i]))
			selectedItems.push_back(_list[i]);

	
	return BusFleet(selectedItems.data(), selectedItems.size());;
}

void BusFleet::Sort(const std::function<int(const BusInfo&, const BusInfo&)>& comparer)
{
	if (_size == 1)
		return;

	//Bubble sort
	for (int i = _size - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			if (comparer(_list[j], _list[j + 1]) < 0)
				std::swap(_list[j], _list[j + 1]);
}