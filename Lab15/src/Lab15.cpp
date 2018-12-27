#include "stdafx.h"

#include <iostream>


#include "Matrix.hpp"


int main()
{
	auto matrixA = Matrix<double>::ReadFrom("data/matrix1.csv");
	auto matrixB = Matrix<double>::ReadFrom("data/matrix2.csv");

	try
	{
		auto matrixWrong = Matrix<double>::ReadFrom("data/notMatrix.csv");
		std::cout << matrixWrong;
	}
	catch (WrongMatrixFileFormat)
	{
		std::cout << "Failed reading matrix file!" << std::endl;
	}


	auto sum = matrixA + matrixB;
	auto diff = matrixA - matrixB;

	std::cout << "Matrix A:" << std::endl;
	std::cout << matrixA << std::endl;

	std::cout << "Matrix B:" << std::endl;
	std::cout << matrixB << std::endl;


	std::cout << "Matrix A + B:" << std::endl;
	std::cout << sum << std::endl;

	std::cout << "Matrix A - B:" << std::endl;
	std::cout << diff << std::endl;



	auto matrixC = Matrix<double>::ReadFrom("data/matrix3.csv");

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