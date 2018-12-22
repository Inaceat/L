#pragma once


#include <string>


class WrongMatrixFileFormat : std::exception {};


class Matrix
{
public:
	//Matrix 0x0
	Matrix() = default;

	//Matrix with random elements
	Matrix(size_t rows, size_t columns);

	//Matrix with same elements
	Matrix(size_t rows, size_t columns, double element);


	//Copy ctor
	Matrix(const Matrix& other);

	//Move ctor
	Matrix(Matrix&& other) noexcept;


	//Assign
	Matrix& operator=(Matrix other);


	//Destructor
	~Matrix() = default;


	//Read Matrix from file
	static Matrix ReadFrom(const std::string& fileName);
	
	//Indexer
	double operator()(size_t row, size_t column) const;


	//Operations
	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;

	Matrix operator*(double scalar) const;
	Matrix operator*(const Matrix& other) const;//Throws on wrong matrices size TODO really throw?


	//Swap
	friend void swap(Matrix& left, Matrix& right) noexcept;


	//Stream I/O : I only from file!
	friend std::ifstream& operator>>(std::ifstream& stream, Matrix& matrix);
	friend std::ostream& operator<<(std::ostream& stream, Matrix& matrix);

private:
	size_t _rows {};
	size_t _columns {};

	std::unique_ptr<double[]> _matrix {};
};