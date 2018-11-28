#include "stdafx.h"

#include "BusInfo.hpp"
#include <iomanip>
#include <regex>
#include <sstream>


BusInfo::BusInfo() :
	_identificationNumber(),
	_model(),
	_productionYear(0),
	_seatingSpace(0),
	_standingSpace(0)
{}

BusInfo::BusInfo(std::string const& identificationNumber, std::string const& model, const int productionYear, const int seatingSpace, const int standingSpace) :
	_identificationNumber(identificationNumber),
	_model(model),
	_productionYear(productionYear),
	_seatingSpace(seatingSpace),
	_standingSpace(standingSpace)
{}



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


int ParseInt(const std::string& str)
{
	std::stringstream stream;
	
	stream << str;


	int result;

	stream >> result;

	return result;
}

std::istream& operator>>(std::istream& istream, BusInfo& item)
{
	std::string inputBuffer;


	std::getline(istream, inputBuffer, '\n');


	std::regex pattern(
		"^"							//Correct BusInfo data is
		"(.+?),(.+?),"				//[one or more non-comma symbols followed by comma] twice - id & model
		"([0-9]{4}),"				//4 digits - year
		"([0-9]+?),([0-9]+?)$"		//[one or more digits] twice - seating & standing space
	);

	if(false == std::regex_match(inputBuffer, pattern))
		throw std::exception("Wrong Bus Info format!");


	std::sregex_token_iterator currentMatch(inputBuffer.begin(), inputBuffer.end(), pattern, { 1, 2, 3, 4, 5});


	item._identificationNumber = *currentMatch++;
	item._model = *currentMatch++;
	item._productionYear = ParseInt(*currentMatch++);
	item._seatingSpace = ParseInt(*currentMatch++);
	item._standingSpace = ParseInt(*currentMatch);

	
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