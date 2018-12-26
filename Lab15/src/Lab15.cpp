#include "stdafx.h"


#include "Matrix.hpp"
#include <iostream>


int main()
{
	auto matrixA = Matrix::ReadFrom("data/matrix1.csv");
	auto matrixB = Matrix::ReadFrom("data/matrix2.csv");

	try
	{
		auto matrixWrong = Matrix::ReadFrom("data/notMatrix.csv");
	}
	catch (WrongMatrixFileFormat)
	{
		std::cout << "Failed reading matrix file!" << std::endl;
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



	auto matrixC = Matrix::ReadFrom("data/matrix3.csv");

	std::cout << "Matrix C:" << std::endl;
	std::cout << matrixC << std::endl;


	try
	{
		std::cout << "Matrix A + C:" << std::endl;
		auto tmp = matrixA + matrixC;
	}
	catch (WrongMatrixSize)
	{
		std::cout << "Wrong matrix size !" << std::endl;
	}


    return 0;
}