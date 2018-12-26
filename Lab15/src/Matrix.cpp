#include "stdafx.h"


#include <fstream>
#include <random>
#include <sstream>


#include "Matrix.hpp"






Matrix::Matrix(size_t rows, size_t columns) :
	_rows(rows),
	_columns(columns),
	_matrix(new double[rows * columns])
{
	std::random_device randomDevice;
	std::uniform_real_distribution<double> distr(DBL_MIN, DBL_MAX);


	for (size_t i = 0; i < rows * columns; i++)
		_matrix[i] = distr(randomDevice);
}

Matrix::Matrix(size_t rows, size_t columns, double element) :
	_rows(rows),
	_columns(columns),
	_matrix(new double[rows * columns])
{
	for (size_t i = 0; i < rows * columns; i++)
		_matrix[i] = element;
}


Matrix::Matrix(const Matrix& other) :
	_rows(other._rows),
	_columns(other._columns),
	_matrix(new double[other._rows * other._columns])
{
	for (size_t elementCounter = 0; elementCounter < other._rows * other._columns; elementCounter++)
		_matrix[elementCounter] = other._matrix[elementCounter];
}

Matrix::Matrix(Matrix&& other) noexcept :
	Matrix()
{
	swap(*this, other);
}


//Due to copy-swap this is both "copy" and "move" assignment.
Matrix& Matrix::operator=(Matrix other)
{
	swap(*this, other);

	return *this;
}



Matrix Matrix::ReadFrom(const std::string& fileName)
{
	std::ifstream stream(fileName);

	Matrix result;

	stream >> result;


	return result;
}


double Matrix::operator()(size_t row, size_t column) const
{
	return _matrix[row * _columns + column];
}


Matrix Matrix::operator+(const Matrix& other) const
{
	//If size of matrices differ, operation can't be performed
	if (_rows != other._rows || _columns != other._columns)
		throw WrongMatrixSize();

	//Make copy of "left"
	Matrix result(other);


	//Add to "left" copy elements "right" elements
	for(size_t i = 0; i < other._rows * other._columns; i++)
		result._matrix[i] += _matrix[i];


	return result;
}

Matrix Matrix::operator-(const Matrix& other) const
{
	return *this + other * (-1);
}

Matrix Matrix::operator*(double scalar) const
{
	//Make copy of matrix
	Matrix result(*this);


	//Multiply each element of the copy by scalar
	for(size_t i = 0; i < _rows * _columns; i++)
		result._matrix[i] *= scalar;


	return result;
}

Matrix Matrix::operator*(const Matrix& other) const
{
	//Multiplication requires proper matrices size
	if (this->_columns != other._rows)
		throw WrongMatrixSize();


	Matrix result(this->_rows, other._columns, 0);

	//Filling each element of result...
	for (size_t i = 0; i < this->_rows; i++)
		for (size_t j = 0; j < other._columns; j++)
		{
			double newElement = 0;

			//...with properly calculated by matrices production rules element
			for (size_t k = 0; k < this->_columns; k++)
				newElement += this->operator()(i, k) * other(k, j);


			result._matrix[i * other._columns + j] = newElement;
		}

	return result;
}


void swap(Matrix& left, Matrix& right) noexcept
{
	using std::swap;

	swap(left._rows, right._rows);
	swap(left._columns, right._columns);
	swap(left._matrix, right._matrix);
}



double ParseDouble(std::string string)
{
	std::stringstream lineStream(string);

	double result;

	lineStream >> result;

	return result;
}

std::vector<std::string> ParseCsv(std::string string)
{
	std::stringstream lineStream(string);


	std::vector<std::string> result;


	std::string value;
	
	while (true)
	{
		if (false == lineStream.eof())
		{
			std::getline(lineStream, value, ',');

			if (value.size() > 0)
				result.push_back(value);
		}
		else
			break;
	}


	return result;
}

std::ifstream& operator>>(std::ifstream& stream, Matrix& matrix)
{
	size_t columns = 0;
	size_t rows = 0;

	std::vector<std::string> readMatrixData;


	while (stream.eof() == false)
	{
		//Read line from file
		std::string rowBuffer;
		std::getline(stream, rowBuffer, '\n');


		//Split into elements
		std::vector<std::string> rowReadItems = ParseCsv(rowBuffer);
		size_t rowReadSize = rowReadItems.size();


		if (rowReadSize == 0 ||						 //if no data in row
			(columns != 0 && rowReadSize != columns))//or read more or less items than before (not for first line)
			throw WrongMatrixFileFormat();			 //ERROR it is

		columns = rowReadSize;
		rows++;
		
		//Add row to result
		readMatrixData.insert(readMatrixData.end(), rowReadItems.begin(), rowReadItems.end());
	}


	//Create matrix
	Matrix result(rows, columns, 0);

	//Copy result to it
	for (size_t i = 0; i < rows * columns; i++)
		result._matrix[i] = ParseDouble(readMatrixData[i]);

	//Move created matrix to passed
	swap(result, matrix);


	return stream;
}

std::ostream& operator<<(std::ostream& stream, Matrix& matrix)
{
	const auto oldprecision = stream.precision(5);


	for (size_t i = 0; i < matrix._rows; i++)
	{
		size_t j;
		
		for (j = 0; j < matrix._columns - 1; j++)
			stream << matrix(i, j) << "  ";


		stream << matrix(i, j) << std::endl;
	}


	stream.precision(oldprecision);

	return stream;
}