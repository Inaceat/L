#include "stdafx.h"

#include "BusInfo.hpp"


BusInfo::BusInfo(const std::string identificationNumber, const std::string model, const int productionYear,
                 const int seatingSpace, const int standingSpace):
	_identificationNumber(identificationNumber),
	_model(model),
	_productionYear(productionYear),
	_seatingSpace(seatingSpace),
	_standingSpace(standingSpace)
{}


