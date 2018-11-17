#include "stdafx.h"

#include "BusInfo.hpp"


BusInfo::BusInfo(std::string const& identificationNumber, std::string const& model, const int productionYear, const int seatingSpace, const int standingSpace) :
	_identificationNumber(identificationNumber),
	_model(),
	_productionYear(productionYear),
	_seatingSpace(seatingSpace),
	_standingSpace(standingSpace)
{
	for(size_t i = 0; i < model.size(); i++)
		_model.push_back(model[i]);
}



std::string const& BusInfo::IdentificationNumber() const
{
	return _identificationNumber;
}

std::vector<char> const& BusInfo::Model() const
{
	return _model;
}

int const& BusInfo::ProductionYear() const
{
	return _productionYear;
}

int const& BusInfo::SeatingSpace() const
{
	return _seatingSpace;
}

int const& BusInfo::StandingSpace() const
{
	return _standingSpace;
}