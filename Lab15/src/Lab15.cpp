#include "stdafx.h"


#include "Matrix.hpp"
#include <iostream>


int main()
{
	Matrix matrixA;
	Matrix matrixB;

	try
	{
		matrixA = Matrix::ReadFrom("data/matrix1.csv");
		matrixB = Matrix::ReadFrom("data/matrix2.csv");
	}
	catch (WrongMatrixFileFormat)
	{
		std::cout << "Failed reading matrix file!" << std::endl;
		return 1;
	}


	auto sum = matrixA + matrixB;
	auto prod = matrixA * matrixB;

	std::cout << "Matrix A:" << std::endl;
	std::cout << matrixA << std::endl;

	std::cout << "Matrix B:" << std::endl;
	std::cout << matrixB << std::endl;


	std::cout << "Matrix A + B:" << std::endl;
	std::cout << sum << std::endl;

	std::cout << "Matrix A * B:" << std::endl;
	std::cout << prod << std::endl;



    return 0;
}