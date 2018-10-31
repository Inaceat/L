#include "stdafx.h"

#include "ArrayUtils.hpp"


void ShowArray(double* arr, size_t size)
{
	for (unsigned int i = 0; i < size; i++)
		std::cout <<std::fixed << std::setprecision(2) << arr[i] << "; ";

	std::cout << std::endl << std::endl;
}


void FillArrayWithRandoms(double* arr, size_t size)
{
	std::random_device randGenerator;

	const std::uniform_real_distribution<double> randDistribution(-50, 50);

	for (size_t i = 0; i < size; i++)
		arr[i] = randDistribution(randGenerator);
}


void SortArray(double * begin, double * end, SortingOrder order)
{
	//Comparer should return:
	// 0, if left is equal to right,
	// < 0, if  left is less than right,
	// > 0, if  left is greater than right
	static std::function<int(double left, double right)> comparer[2]{
		[](const double left, const double right) { return left <= right; }, //ascending
		[](const double left, const double right) { return left >= right; }  //descending
	};


	//Each element in the beginning of the iteration is just after sorted part. So we should insert it to its place.
	//Compare element to its left neighbour, and swap element to right place. 

	for(auto i = begin + 1, current = i; i < end; i++, current = i)
	{
		while (current != begin
			&& comparer[order](*(current - 1), *current) == false)
		{
			std::swap(*(current - 1), *current);
			current--;
		}
	}
}


double* Search(double* begin, double* end, double& valueToSearch)
{
	auto size = end - begin;

	
	if (size <= 0)
		throw std::exception("Search args invalid!");

	if (size == 1)
		return *begin == valueToSearch ? begin : end;
	
	
	auto mid = begin + size / 2;

	if(*mid == valueToSearch)
		return mid;


	auto nextBegin = begin;
	auto nextEnd = end;
	
	//search in next interval
	if(*mid < valueToSearch)
		nextBegin = mid;
	else
		nextEnd = mid;

	auto searchResult = Search(nextBegin, nextEnd, valueToSearch);

	//if not found, return end
	if(searchResult == nextEnd)
		searchResult = end;

	return searchResult;
}