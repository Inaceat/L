#pragma once

#include <string>
#include <vector>

class BusInfo
{
public:
	BusInfo(const std::string identificationNumber, const std::string model, const int productionYear, const int seatingSpace, const int standingSpace);


	std::string IdentificationNumber()
	{
		return _identificationNumber;
	}

	std::vector<char> const & Model()
	{
		return _model;
	}

	int ProductionYear()//consts? references?
	{
		return _productionYear;
	}


	int SeatingSpace()
	{
		return _seatingSpace;
	}


	int StandingSpace()
	{
		return _standingSpace;
	}


private:
	std::string _identificationNumber;
	std::vector<char> _model;
	int _productionYear;
	int _seatingSpace;
	int _standingSpace;
};