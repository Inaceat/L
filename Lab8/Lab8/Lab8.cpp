#include "stdafx.h"



void ShowArray(double* arr, size_t size)
{
	for (unsigned int i = 0; i < size; i++)
		std::cout /*<<std::fixed << std::setprecision(0)*/ << arr[i] << "; ";

	std::cout << std::endl << std::endl;
}

void FillArrayWithRandoms(double* arr, unsigned int size)
{
	std::random_device randGenerator;

	const std::uniform_real_distribution<double> randDistribution(-50, 50);

	for (unsigned int i = 0; i < size; i++)
		arr[i] = randDistribution(randGenerator);
}


typedef std::function<bool(double, double)> DoubleComparator;

enum SortingOrder
{
	Ascending = 0,
	Descending = 1
};

//Insertion sorting
void SortArray(double* arr, size_t size, SortingOrder order)
{
	//Copmarator should return true, if elements are in right order
	static DoubleComparator comparator[2]{
		[](const double left, const double right) { return left <= right; }, //ascending
		[](const double left, const double right) { return left >= right; }  //descending
	};

	//Each element in the beginning of the iteration is just after sorted part. So we should insert it to its place.
	//Compare element to its left neighbour, and swap element to right place. 

	for (size_t i = 1, currentElementIndex = i; i < size; i++, currentElementIndex = i)
	{		
		while(currentElementIndex != 0 &&
			  comparator[order](arr[currentElementIndex - 1], arr[currentElementIndex]) == false)
			
		{
			std::swap(arr[currentElementIndex - 1], arr[currentElementIndex]);
			currentElementIndex--;
		}
	}
}



void main()
{
	const size_t arrSize = 7;
	double arr[arrSize] = { 12, -23, -3, 0., 54, 31.42, 3.45};


	ShowArray(arr, arrSize);

	SortArray(arr, arrSize, SortingOrder::Ascending);
	ShowArray(arr, arrSize);

	SortArray(arr, arrSize, SortingOrder::Descending);
	ShowArray(arr, arrSize);
}