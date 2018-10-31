#pragma once


enum SortingOrder
{
	Ascending = 0,
	Descending = 1
};



void ShowArray(double* arr, size_t size);

void FillArrayWithRandoms(double* arr, size_t size);


//Insertion sorting
void SortArray(double* begin, double* end, SortingOrder order);

//BinarySearch
double* Search(double* begin, double* end, double& valueToSearch);