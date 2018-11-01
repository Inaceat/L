#pragma once


void ShowArray(int** arr, size_t rows, size_t columns);


//Fills array with elements from -maxValue to maxValue
void FillArrayWithRandoms(int** arr, size_t rows, size_t columns, int maxValue);


//Fills array with elements 'xy', where x is row index and y is column index
//More than 9x9 arrays are not supported
void FillArrayWithNotRandomsAtAll(int** arr, size_t rows, size_t columns);


//Find sums of all diagonals that are parallel to counterdiagonal, then find min of them
int MinOfAllCounterDiagonalSums(int** arr, size_t rows, size_t columns);


void RotateClockwise(int** arr, size_t rows, size_t columns);