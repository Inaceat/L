#include "stdafx.h"

#include "BusInfo.hpp"
#include <iomanip>
#include <regex>


BusInfo::BusInfo() :
	_identificationNumber(),
	_model(),
	_productionYear(0),
	_seatingSpace(0),
	_standingSpace(0)
{}

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


std::ostream& operator<<(std::ostream& ostream, const BusInfo& item)
{
	ostream << "ID Number: " << std::setw(10) << item._identificationNumber;
	ostream << "  Model: " << std::setw(10) << item._model;
	ostream << "  Prod. year: " << std::setw(5) << item._productionYear;
	ostream << "  Seats: " << std::setw(4) << item._seatingSpace;
	ostream << "  Standing space: " << std::setw(4) << item._standingSpace;
	
	ostream << std::endl;

	return ostream;
}

std::istream& operator>>(std::istream& istream, BusInfo& item)
{
	std::string inputBuffer = "qwe,ert,12,42,13";


	//std::getline(istream, inputBuffer, '\n');


	std::regex pattern("(.)");
	std::smatch match;


	std::vector<std::string> res;

	while(std::regex_search(inputBuffer, match, pattern))
	{
		res.push_back(match[0]);

		inputBuffer = match.suffix();
	}

	




	item._identificationNumber;
	item._model;
	item._productionYear;
	item._seatingSpace;
	item._standingSpace;

	
	return istream;
}


std::string const& BusInfo::IdentificationNumber() const
{
	return _identificationNumber;
}

std::string const& BusInfo::Model() const
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