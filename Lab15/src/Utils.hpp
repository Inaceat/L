#pragma once

#include <string>
#include <vector>
#include <sstream>


template<class T>
static T Parse(std::string string)
{
	std::stringstream lineStream(string);

	T result;

	lineStream >> result;

	return result;
}

static std::vector<std::string> ParseCsv(const std::string& string)
{
	std::stringstream lineStream(string);


	std::vector<std::string> result;


	std::string value;

	while (true)
	{
		if (!lineStream.eof())
		{
			std::getline(lineStream, value, ',');

			if (value.size() > 0)
				result.push_back(value);
		}
		else
			break;
	}


	return result;
}