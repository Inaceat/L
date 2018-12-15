#pragma once


#include <string>


class Matrix
{
public:
	//Matrix 0x0
	Matrix();

	//Matrix with random elements
	Matrix(size_t rows, size_t columns);


	//Copy ctor
	Matrix(const Matrix& other);

	//Move ctor
	Matrix(const Matrix&& other) noexcept;


	//Copy assign
	Matrix& operator=(const Matrix& other);

	//Move assign
	Matrix& operator=(Matrix&& other) noexcept;


	//Destructor
	~Matrix();


	//Read Matrix from file
	Matrix ReadFrom(const std::string& fileName);
	
	//Indexer
	//TODO indexer


	//Operations
	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;

	Matrix operator*(double other) const;
	Matrix operator*(const Matrix& other) const;//Throws on wrong matrices size TODO really throw?


private:
	size_t _rows;
	size_t _columns;

	std::unique_ptr<double> _matrix;
};
