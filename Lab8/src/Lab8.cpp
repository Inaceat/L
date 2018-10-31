#include "stdafx.h"


#include "ArrayUtils.hpp"



void Task1()
{
	const size_t arrSize = 10;
	

	double* arr = new double[arrSize];
	FillArrayWithRandoms(arr, arrSize);

	double valueToSearch = arr[7];
	double absentValue = -1000;

	std::cout << "Initial array:" << std::endl;
	ShowArray(arr, arrSize);


	std::cout << "Ascending sorted array:" << std::endl;
	SortArray(arr, arr + arrSize, SortingOrder::Ascending);
	ShowArray(arr, arrSize);


	std::cout << "Value to search: "  << valueToSearch << std::endl;
	std::cout << "Found value: " << *Search(arr, arr + arrSize, valueToSearch) << std::endl << std::endl;

	std::cout << "Absent value to search: "  << absentValue << std::endl;
	std::cout << "Found value: " << 
	(arr + arrSize == Search(arr, arr + arrSize, absentValue) ? "not found" : "search failed, contact your bla-bla-bla...")
	<< std::endl << std::endl;


	std::cout << "Descending sorted array:" << std::endl;
	SortArray(arr, arr + arrSize, SortingOrder::Descending);
	ShowArray(arr, arrSize);
}


void Task2()
{
	
}

int main()
{
	Task1();

	Task2();
}