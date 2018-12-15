#pragma once

#include <string>
#include <vector>

class BusInfo
{
public:
	BusInfo();

	BusInfo(std::string const& identificationNumber, std::string const& model, int productionYear, int seatingSpace, int standingSpace);


	friend std::ostream& operator<<(std::ostream& ostream, const BusInfo& item);

	friend std::istream& operator>>(std::istream& istream, BusInfo& item);


	std::string ToCsv() const;

//////////////////////////////////////////////////////////////////////getters
	std::string const& IdentificationNumber() const;

	std::string const& Model() const;

	int const& ProductionYear() const;

	int const& SeatingSpace() const;

	int const& StandingSpace() const;


private:
	std::string _identificationNumber;
	std::string _model;
	int _productionYear;
	int _seatingSpace;
	int _standingSpace;
};