#include "stdafx.h"

#include "2dArrayUtils.hpp"


void ShowArray(int** arr, size_t rows, size_t columns)
{
	for (size_t i = 0; i < rows; i++)//for each row
	{
		for (size_t j = 0; j < columns; j++)//show each element in row
			std::cout << std::setw(5) << arr[i][j];

		std::cout << std::endl;
	}

	std::cout << std::endl;
}


void FillArrayWithRandoms(int** arr, size_t rows, size_t columns, int maxValue)
{
	std::random_device randGenerator;
	const std::uniform_int_distribution<int> randDistribution(-std::abs(maxValue), std::abs(maxValue));


	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			arr[i][j] = randDistribution(randGenerator);
}


void FillArrayWithNotRandomsAtAll(int** arr, size_t rows, size_t columns)
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			arr[i][j] = i * (10) + j;
}


int MinOfAllCounterDiagonalSums(int** arr, size_t rows, size_t columns)
{
	if(rows != columns)
		throw std::exception("Only square matrices allowed !");


	auto numberOfDiagonals = rows + columns - 1;


	auto minSum = INT_MAX;


	//All elements on each required diagonal have same sum of indices: 0 for the first diagonal ... (numberOfDiagonals - 1) for the last.
	//So iterate diagonals through iterating sum of thir indices.
	for (size_t diagonalIndicesSum = 0; diagonalIndicesSum < numberOfDiagonals; diagonalIndicesSum++)
	{
		auto currentDiagonalSum = 0;


		//To keep indices in correct bounds, which are 0..(rows-1)
		auto maxDiagonalIndex = min(diagonalIndicesSum, rows-1);


		//Elements on diagonal have same sum of indices, so i + j == diagonalIndicesSumm, where i = 0..maxIndex	
		for(size_t i = maxDiagonalIndex, j = diagonalIndicesSum - i; j <= maxDiagonalIndex; i--, j++)
			currentDiagonalSum += arr[i][j];

		minSum = currentDiagonalSum < minSum ? currentDiagonalSum : minSum;
	}

	return minSum;
}


void RotateClockwise(int** arr, size_t rows, size_t columns)
{
	if(rows != columns)
		throw std::exception("Only square matrices allowed !");


	//We should "rotate" some circles (squares to be exact, nice little circle squares):
	auto numberOfCircles = rows / 2;


	//Let's rotate each:
	for (size_t circleNumber = 0; circleNumber < numberOfCircles; circleNumber++)
	{
		//How many elements we have in circle (square!) side: 
		auto circleSideLength = rows - 2 * circleNumber;


		//Max index of element in current circle (arr[circleMaxIndex][circleMaxIndex] is "bottom right" element)
		auto circleMaxIndex = circleNumber + circleSideLength - 1;


		//Indices of "left top" element of current circle:
		size_t i = circleNumber;//row index
		size_t j = circleNumber;//column index


		//now "rolling" left top element, swapping it through:
		//left side, swapping top element to bottom
		for (i = circleNumber; i < circleMaxIndex; i++)
			std::swap(arr[i][j], arr[i + 1][j]);

		//bottom side, swapping left element to right (it was arr[circleNumber][circleNumber] once!)
		for(i = circleMaxIndex; j < circleMaxIndex; j++)
			std::swap(arr[i][j], arr[i][j + 1]);

		//right side, swapping bottom to top
		for(j = circleMaxIndex; i > circleNumber; i--)
			std::swap(arr[i][j], arr[i - 1][j]);
		
		//top side, swapping right to !!second from left!!
		for(i = circleNumber; j > circleNumber + 1; j--)
			std::swap(arr[i][j], arr[i][j - 1]);
	}
}