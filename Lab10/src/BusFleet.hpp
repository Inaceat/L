#pragma once


#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

#include "BusInfo.hpp"









BusInfo* CreateBusList(const size_t listLength);

void ClearBusList(BusInfo* busList, size_t listLength);


void ShowBusInfo(BusInfo* busInfo);


void ShowBusList(BusInfo* busList, size_t listLength);

void ShowBusList(BusInfo* busList, size_t listLength, std::function<bool(BusInfo*)> selector);


void SortBusList(BusInfo* busList, size_t listLength, std::function<int(BusInfo*, BusInfo*)> comparer);