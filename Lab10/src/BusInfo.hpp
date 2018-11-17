#pragma once

#include <string>
#include <vector>

class BusInfo
{
public:
	BusInfo(std::string const& identificationNumber, std::string const& model, int productionYear, int seatingSpace, int standingSpace);


//////////////////////////////////////////////////////////////////////getters
	std::string const& IdentificationNumber() const;

	std::vector<char> const& Model() const;

	int const& ProductionYear() const;

	int const& SeatingSpace() const;

	int const& StandingSpace() const;


private:
	std::string _identificationNumber;
	std::vector<char> _model{};
	int _productionYear;
	int _seatingSpace;
	int _standingSpace;
};