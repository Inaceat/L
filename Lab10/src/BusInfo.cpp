#include "stdafx.h"

#include "BusInfo.hpp"


BusInfo::BusInfo(const std::string identificationNumber, const std::string model, const int productionYear,
                 const int seatingSpace, const int standingSpace):
	_identificationNumber(identificationNumber),
	_model(),
	_productionYear(productionYear),
	_seatingSpace(seatingSpace),
	_standingSpace(standingSpace)
{
	for(size_t i = 0; i < model.size(); i++)
		_model.push_back(model[i]);
}