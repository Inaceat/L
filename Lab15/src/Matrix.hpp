#pragma once

#include <exception>
#include <fstream>

#include "Utils.hpp"


class WrongMatrixFileFormat : std::exception {};
class WrongMatrixSize : std::exception {};


template<class T>
class Matrix
{
public:
	//Matrix 0x0
	Matrix() = default;

	//Matrix with same elements
	Matrix(size_t rows, size_t columns, T element) :
		_rows(rows),
		_columns(columns),
		_matrix(new T[rows * columns])
	{
		for (size_t i = 0; i < rows * columns; i++)
			_matrix[i] = element;
	}


	//Copy ctor
	Matrix(const Matrix<T>& other) :
		_rows(other._rows),
		_columns(other._columns),
		_matrix(new T[other._rows * other._columns])
	{
		for (size_t i = 0; i < other._rows * other._columns; i++)
			_matrix[i] = other._matrix[i];
	}

	//Move ctor
	Matrix(Matrix&& other) noexcept :
		Matrix()
	{
		swap(*this, other);
	}


	//Due to copy-swap this is both "copy" and "move" assignment.
	Matrix& operator=(Matrix other)
	{
		swap(*this, other);

		return *this;
	}


	//Destructor
	~Matrix() = default;


	//Read Matrix from file
	static Matrix<T> ReadFrom(const std::string& fileName)
	{
		std::ifstream stream(fileName);

		Matrix<T> result;

		stream >> result;


		return result;
	}
	
	//Indexer
	T operator()(size_t row, size_t column) const
	{
		return _matrix[row * _columns + column];
	}


	//Operations, throwing if matrices have wrong size
	Matrix operator+(const Matrix& other) const
	{
		//If size of matrices differ, operation can't be performed
		if (_rows != other._rows || _columns != other._columns)
			throw WrongMatrixSize();

		//Make copy of "right"
		Matrix result(other);


		//Add to "right" copy elements "left" elements
		for (size_t i = 0; i < other._rows * other._columns; i++)
			result._matrix[i] += _matrix[i];


		return result;
	}

	Matrix operator-(const Matrix& other) const
	{
		//If size of matrices differ, operation can't be performed
		if (_rows != other._rows || _columns != other._columns)
			throw WrongMatrixSize();

		//Make copy of "left"
		Matrix result(*this);


		//Substract from "left" copy elements "right" elements
		for (size_t i = 0; i < other._rows * other._columns; i++)
			result._matrix[i] -= _matrix[i];


		return result;
	}

	
	Matrix operator*(T scalar) const
	{
		//Make copy of matrix
		Matrix result(*this);


		//Multiply each element of the copy by scalar
		for (size_t i = 0; i < _rows * _columns; i++)
			result._matrix[i] *= scalar;


		return result;
	}

	Matrix operator*(const Matrix& other) const
	{
		//Multiplication requires proper matrices size
		if (this->_columns != other._rows)
			throw WrongMatrixSize();


		Matrix result(this->_rows, other._columns, 0);

		//Filling each element of result...
		for (size_t i = 0; i < this->_rows; i++)
			for (size_t j = 0; j < other._columns; j++)
			{
				T newElement {};

				//...with properly calculated by matrices production rules element
				for (size_t k = 0; k < this->_columns; k++)
					newElement += this->operator()(i, k) * other(k, j);


				result._matrix[i * other._columns + j] = newElement;
			}

		return result;
	}


	//Swap
	friend void swap(Matrix<T>& left, Matrix<T>& right) noexcept
	{
		using std::swap;

		swap(left._rows, right._rows);
		swap(left._columns, right._columns);
		swap(left._matrix, right._matrix);
	}


	//Stream I/O : Input only from file!
	friend std::ifstream& operator>>(std::ifstream& stream, Matrix& matrix)
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


		//Create matrix of default T's
		Matrix result(rows, columns, T());

		//Copy result to it
		for (size_t i = 0; i < rows * columns; i++)
			result._matrix[i] = Parse<T>(readMatrixData[i]);

		//Move created matrix to passed
		swap(result, matrix);


		return stream;
	}
	
	friend std::ostream& operator<<(std::ostream& stream, Matrix<T>& matrix)
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


private:
	size_t _rows {};
	size_t _columns {};

	std::unique_ptr<T[]> _matrix {};
};