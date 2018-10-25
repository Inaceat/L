#include "stdafx.h"

//Test moar, but seems to be good
std::string ToString(double object, int precision)
{
	if (precision < 0)
		throw std::exception("Idiot? Idiot. FP precision cannot be negative !");


	std::stringstream stream;

	stream << std::fixed << std::setprecision(precision) << object;

	std::string result = stream.str();

	if (precision == 0)
		return result;


	size_t lastNonZero = result.find_last_not_of('0');
	
	result.erase(lastNonZero + 1);
	

	if (result[lastNonZero] == '.')
		result.erase(lastNonZero);

	return result;
}


typedef double(*Function)(double x, double a, double b);



std::vector<double> CalculateFunction(Function function, std::vector<double> args, double paramA, double paramB)
{
	std::vector<double> result;

	for (size_t i = 0; i < args.size(); i++)
		result.push_back(function(args[i], paramA, paramB));

	return result;
}

//Assuming table is rectangle! 
void PrintBeautifulTable(std::vector<std::vector<double>> table, int maxPrecision)
{
	size_t tableColumnCount = table[0].size();
	size_t tableRowCount = table.size();

	
	//////////////////////////////////////////////////////////////////////////	Fill column names
	std::vector<std::string> tableColumnNames = {"X"};

	for (size_t i = 0; i < tableColumnCount - 1; i++)
		tableColumnNames.push_back("Y" + ToString(i + 1, 0));
		
	
	//////////////////////////////////////////////////////////////////////////	Cast all table values to string, using fixed point and specified *maxPrecision*
	std::vector<std::vector<std::string>> stringTable;
	
	stringTable.push_back(tableColumnNames);


	for (size_t i = 0; i < tableRowCount; i++)
	{
		std::vector<std::string> columnStrings;

		for (size_t j = 0; j < tableColumnCount; j++)
			columnStrings.push_back(ToString(table[i][j], maxPrecision));

		stringTable.push_back(columnStrings);
	}

	//////////////////////////////////////////////////////////////////////////find width of each column
	std::vector<int> tableColumnWidth;

	for (size_t i = 0; i < tableColumnCount; i++)
	{
		//for each column find max length of element
		size_t maxLengthOfColumnElement = 0;
		
		for (size_t j = 0; j < tableRowCount; j++)
		{
			size_t currentElementLength = stringTable[j][i].size();

			if (maxLengthOfColumnElement < currentElementLength)
				maxLengthOfColumnElement = currentElementLength;
		}


		tableColumnWidth.push_back(maxLengthOfColumnElement);
	}

	//////////////////////////////////////////////////////////////////////////add spaces according to column width
	std::vector<std::vector<std::string>> tableToPrint;



	//spaces for values
	for (size_t i = 0; i < tableRowCount; i++)
	{
		std::vector<std::string> columnToPrint;

		for (size_t j = 0; j < tableColumnCount; j++)
		{
			int spacesToInsert = tableColumnWidth[j] - stringTable[i][j].size();

			columnToPrint.push_back(stringTable[i][j].insert(0, spacesToInsert, ' '));
		}

		tableToPrint.push_back(columnToPrint);
	}


	//////////////////////////////////////////////////////////////////////////print with borders
	size_t tableWidth = -1;
	for_each(tableColumnWidth.begin(), tableColumnWidth.end(), [&](int value) mutable
	{
		tableWidth += value + 3;
	});

	//column names
	for (size_t j = 0; j < tableColumnCount; j++)
		std::cout << tableToPrint[0][j] << " | ";

	//delimiter
	std::cout << std::endl << std::string(tableWidth, '-') << std::endl;

	//function values
	for (size_t i = 1; i < tableRowCount; i++)
	{
		for (size_t j = 0; j < tableColumnCount; j++)
			std::cout << tableToPrint[i][j] << " | ";

		std::cout << std::endl;
	}
}


double Foo1(double x, double paramA, double paramB)
{
	if (x <= 0)
		return std::pow(paramA, -x);
	else
		return std::cos(paramB * x);
}

double Foo2(double x, double paramA, double paramB)
{
	if (x <= 1)
		return paramA * std::sqrt(1-x);
	else
		return paramB * (std::log(x)/std::log(3));
}

double Foo3(double x, double paramA, double paramB)
{
	if (x <= 2)
		return std::sqrt((1 - std::cos(x * M_PI)) / 2);
	else
		return paramB * (x - 2)*(x - 2)*(x - 2);
}

void TaskTheOnly()
{
	double paramA = 2;
	double paramB = 5;

	double xBegin = -1;
	double xEnd = 3;

	double xDelta = 0.2;


	int maxPrecision = 5;
#define DEV_MODE
	//////////////////////////////////////////////////////////////////////////input
#ifndef DEV_MODE
	std::cout << "Введите параметры функций :" << std::endl;

	std::cout << "a = ";
	std::cin >> paramA;

	std::cout << "b = ";
	std::cin >> paramB;


	std::cout << "Введите интервал аргумента функции :" << std::endl;
	
	std::cout << "Начало x0 = ";
	std::cin >> xBegin;

	std::cout << "Конец x1 = ";
	std::cin >> xEnd;


	std::cout << "Введите изменение аргумента функции :" << std::endl;

	std::cout << "Дельта x = ";
	std::cin >> xDelta;
#endif

	//////////////////////////////////////////////////////////////////////////calc args
	std::vector<double> functionArgs;

	for (double currentX = xBegin; currentX < xEnd; currentX += xDelta)
		functionArgs.push_back(currentX);

	functionArgs.push_back(xEnd);
	
	
	//////////////////////////////////////////////////////////////////////////calc function values
	
	
	std::vector<Function> functions = { Foo1, Foo2, Foo3 };
	
	//each function result in own row, table[funcNumber][valueNumber]
	std::vector<std::vector<double>> functionsValues;

	for (size_t i = 0; i < functions.size(); i++)
		functionsValues.push_back(CalculateFunction(functions[i], functionArgs, paramA, paramB));

	
	//////////////////////////////////////////////////////////////////////////add args to array
	functionsValues.insert(functionsValues.begin(), functionArgs);


	//////////////////////////////////////////////////////////////////////////flip table
	std::vector<std::vector<double>> valuesTable;
	
	for (size_t i = 0; i < functionsValues[0].size(); i++)//for each argument value//mb indxOutOfBounds, care
	{
		std::vector<double> allFunctionValuesOfArgument;
		
		for (size_t j = 0; j < functionsValues.size(); j++)//take all function values (and arg value first)
			allFunctionValuesOfArgument.push_back(functionsValues[j][i]);

		valuesTable.push_back(allFunctionValuesOfArgument);
	}


	PrintBeautifulTable(valuesTable, maxPrecision);
	
	int x = 3;
}



void main()
{
	setlocale(LC_ALL, "Russian");

	TaskTheOnly();
}