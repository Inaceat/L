#include "stdafx.h"


#include <random>


#include "Matrix.hpp"
#include <iostream>


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


//Due to copy-swap this is both "copy" and "move" assignment. Maybe.
Matrix& Matrix::operator=(Matrix other)
{
	swap(*this, other);

	return *this;
}



Matrix Matrix::ReadFrom(const std::string& fileName)
{
	//TODO
	std::cout << "NOPE" << std::endl;

	return {};
}


double Matrix::operator()(size_t row, size_t column) const
{
	return _matrix[row * _columns + column];
}


Matrix Matrix::operator+(const Matrix& other) const
{
	//If size of matrices differ, operation can't be performed
	if (_rows != other._rows || _columns != other._columns)
		return {};

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
		return {};


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


std::istream& operator>>(std::istream& stream, Matrix& matrix)
{
	//TODO not implementation
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