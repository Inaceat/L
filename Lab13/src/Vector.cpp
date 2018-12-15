#include "stdafx.h"

#include <string>

#include "Geometry.hpp"


geometry2D::Vector::Vector() :
	_xComponent(0),
	_yComponent(0)
{}

geometry2D::Vector::Vector(const double a1, const double a2) :
	_xComponent(a1),
	_yComponent(a2)
{}

geometry2D::Vector::Vector(Point a, Point b)
{
	_xComponent = b.X() - a.X();
	_yComponent = b.Y() - a.Y();
}


geometry2D::Vector geometry2D::Vector::FindPerpendicularVector() const
{
	Vector result(_yComponent, (-1) * _xComponent);

	return result;
}


double geometry2D::Vector::XComponent() const
{
	return _xComponent;
}

double geometry2D::Vector::YComponent() const
{
	return _yComponent;
}


geometry2D::Vector geometry2D::Vector::operator+(const Vector& right) const
{
	return Vector(_xComponent + right._xComponent, _yComponent + right._yComponent);
}

geometry2D::Vector geometry2D::Vector::operator-(const Vector& right) const
{
	return Vector(_xComponent - right._xComponent, _yComponent - right._yComponent);
}

geometry2D::Vector geometry2D::Vector::operator*(double scalar) const
{
	return Vector(_xComponent * scalar, _yComponent * scalar);
}

double geometry2D::Vector::operator*(const Vector& other) const
{
	return this->_xComponent * other._xComponent + this->_yComponent * other._yComponent;
}


std::istream& geometry2D::operator>>(std::istream& stream, geometry2D::Vector& vector)
{
	stream >> vector._xComponent >> vector._yComponent;
	
	return stream;
}

std::ostream& geometry2D::operator<<(std::ostream& stream, Vector& vector)
{
	stream << "Vector[" << vector._xComponent << ", " << vector._yComponent << "]";

	return stream;
}
