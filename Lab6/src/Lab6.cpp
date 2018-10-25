#include "stdafx.h"


void ShowArray(double* arr, size_t size)
{
	for (unsigned int i = 0; i < size; i++)
		std::cout /*<<std::fixed << std::setprecision(0)*/ << arr[i] << "; ";

	std::cout << std::endl << std::endl;
}


void FillArrayWithRandoms(double* arr, size_t size)
{
	std::random_device randGenerator;

	const std::uniform_real_distribution<double> randDistribution(-50, 50);

	for (size_t i = 0; i < size; i++)
		arr[i] = randDistribution(randGenerator);
}


//prod. of elements with even indices ("human" array, 1,2,3,...)
void Task1(double* arr, size_t size)
{
	double result = 1;

	for (size_t i = 1; i < size - 1; i += 2)
		result *= arr[i];

	std::cout << "Production of elements with even indices:" << std::endl << std::fixed << std::setprecision(2) << result << std::endl << std::endl;
}

//sum of elements between first and last zeroes
void Task2(double* arr, size_t size)
{
	int firstZeroIndex = -1;
	int lastZeroIndex = -1;

	for (size_t i = 0; i < size ; i++)
	{
		if (firstZeroIndex == -1 && arr[i] == 0)
			firstZeroIndex = i;

		if (lastZeroIndex == -1 && arr[size - 1 - i] == 0)
			lastZeroIndex = size - 1 - i;
	}
	
	firstZeroIndex = firstZeroIndex == -1 ? 0 : firstZeroIndex;
	lastZeroIndex = lastZeroIndex == -1 ? size - 1 : lastZeroIndex;


	double result = 0;

	for (int i = firstZeroIndex; i <= lastZeroIndex; i++)
		result += arr[i];
	
	std::cout << "Summ of elements between first and last zero:" << std::endl << std::fixed << std::setprecision(2) << result << std::endl << std::endl;
}

//remove all negative elements
void Task3(double* arr, size_t size)
{
	size_t sizeWithoutZeroes = size;

	size_t i = 0, j = 0;
	for (; i < size && j < size; i++, j++)
	{
		if (arr[i] < 0)
		{
			//find first not negative element after this negative
			while (j < size && arr[j] < 0)
				j++;

			if (j < size)
				std::swap(arr[i], arr[j]);
		}
	}

	sizeWithoutZeroes = size - j + i;

	std::cout << "Array without negative elements: " << std::endl;
	ShowArray(arr, sizeWithoutZeroes);
}




void main()
{
	const size_t arraySize = 7;

	double arr[arraySize] /*{ 0, 0, 1, -2, 3, 0, 8.3 }*/{ 0, -2, 0, 8, 0, 0, 0 };


	FillArrayWithRandoms(arr, arraySize);
	ShowArray(arr, arraySize);


	Task1(arr, arraySize);
	Task2(arr, arraySize);
	Task3(arr, arraySize);
}