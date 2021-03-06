#include "stdafx.h"


#include "ArrayUtils.hpp"
#include "2dArrayUtils.hpp"


void Task1()
{
	const size_t arrSize = 10;
	

	double* arr = new double[arrSize];
	FillArrayWithRandoms(arr, arrSize);

	double valueToSearch = arr[9];
	double wrongValue = -10;

	std::cout << "Initial array:" << std::endl;
	ShowArray(arr, arrSize);


	std::cout << "Ascending sorted array:" << std::endl;
	SortArray(arr, arr + arrSize, SortingOrder::Ascending);
	ShowArray(arr, arrSize);


	std::cout << "Value to search: "  << valueToSearch << std::endl;
	std::cout << "Found value, index: " << Search(arr, arr + arrSize, valueToSearch) - arr << std::endl << std::endl;

	std::cout << "Wrong value to search: "  << wrongValue << std::endl;
	std::cout << "Found value: " << 
	(arr + arrSize == Search(arr, arr + arrSize, wrongValue) ? "not found" : "search failed, contact your bla-bla-bla...")
	<< std::endl << std::endl;


	std::cout << "Descending sorted array:" << std::endl;
	SortArray(arr, arr + arrSize, SortingOrder::Descending);
	ShowArray(arr, arrSize);

	delete[] arr;
}

void Task2()
{
	const size_t arrSize = 3;

	auto arr = new int*[arrSize];
	for (auto i = 0; i < arrSize; ++i)
		arr[i] = new int[arrSize];


	FillArrayWithRandoms(arr, arrSize, arrSize, 50);
	ShowArray(arr, arrSize, arrSize);


	std::cout << "Minimum of sums of all diagonals that are parallel to counterdiagonal : "  << MinOfAllCounterDiagonalSums(arr, arrSize, arrSize) << std::endl << std::endl;


	std::cout << "Press any key to rotate array clockwise, or 'x' to exit : " << std::endl << std::endl;
	

	const auto consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	
	GetConsoleScreenBufferInfo(consoleHandle, &consoleInfo);

	const auto arrayBeginningCursorPosition = consoleInfo.dwCursorPosition;




	FillArrayWithNotRandomsAtAll(arr, arrSize, arrSize);
	ShowArray(arr, arrSize, arrSize);

	while (_getwch() != 'x')
	{
		SetConsoleCursorPosition(consoleHandle, arrayBeginningCursorPosition);

		RotateClockwise(arr, arrSize, arrSize);
		ShowArray(arr, arrSize, arrSize);
	}
	

	for (auto i = 0; i < arrSize; ++i)
		delete[] arr[i];
	delete[] arr;
}


int main()
{
	//Task1();

	Task2();
}