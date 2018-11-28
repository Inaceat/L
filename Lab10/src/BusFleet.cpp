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


		//std::copy(other._list, other._list + other._size, _list);TODO some f******g magic seems to be here
		memcpy_s(_list, other._size * sizeof(BusInfo), other._list, other._size * sizeof(BusInfo));
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

	memcpy_s(_list, sizeof(BusInfo) * size, list, sizeof(BusInfo) * size);
}

BusFleet::BusFleet(const std::string& fileName)
{
	//TODO


	static auto alphabet = "abcdefghijklmnopqrstuvwxyz0123456789";

	static size_t alphabetLength = 36;
	static size_t lettersLength = 26;


	srand(time(nullptr));

	_size = 10;

	_list = new BusInfo[_size];

	for (size_t i = 0; i < _size; i++)
	{
		////////////////////////////////////////////////////////////IdentificationNumber
		size_t idLength = rand() % 4 + 5;

		auto id = new char[idLength + 1];
		id[idLength] = '\0';

		for (size_t idCounter = 0; idCounter < idLength; idCounter++)
			id[idCounter] = alphabet[rand() % alphabetLength];


		////////////////////////////////////////////////////////////Model
		size_t modelLength = rand() % 4 + 7;

		auto model = new char[modelLength + 1];
		model[modelLength] = '\0';

		for (size_t modelCounter = 0; modelCounter < modelLength; modelCounter++)
			model[modelCounter] = alphabet[rand() % lettersLength];


		////////////////////////////////////////////////////////////ProductionYear
		auto productionYear = rand() % 65 + 1950;


		////////////////////////////////////////////////////////////SeatingSpace
		auto seatingSpace = rand() % 40 + 10;


		////////////////////////////////////////////////////////////StandingSpace
		auto standingSpace = rand() % 101;


		////////////////////////////////////////////////////////////

		std::string idStr(id);
		std::string modelStr(model);

		BusInfo newEntry(idStr, modelStr, productionYear, seatingSpace, standingSpace);

		_list[i] = newEntry;

		delete[] id;
		delete[] model;
	}
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

std::istream& operator>>(std::istream& istream, BusFleet& item)
{
	//TODO

	/*for (size_t i = 0; i < item._size; i++)
		istream >> item._list[i];*/

	return istream;
}



BusFleet BusFleet::Select(const std::function<bool(const BusInfo&)>& selector) const
{
	std::vector<BusInfo> selectedItems;

	for (size_t i = 0; i < _size; i++)
	{
		if (selector(_list[i]))
			selectedItems.push_back(_list[i]);
		
	}

	BusFleet result;

	result._size = selectedItems.size();
	result._list = new BusInfo[result._size];
	
	std::copy(selectedItems.begin(), selectedItems.end(), result._list);


	return result;
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