#include "stdafx.h"

#include "BusFleet.hpp"


int main()
{
	const size_t listLength = 10;

	auto list = CreateBusList(listLength);

	ShowBusList(list, listLength);


	ClearBusList(list, listLength);
}