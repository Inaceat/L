#pragma once


#include <iostream>
#include <vector>


namespace geometry2D
{
	class Point
	{
	public:
		Point();
		Point(double x, double y);

		double X() const;
		double Y() const;


		friend std::istream& operator>>(std::istream& stream, Point& point);
		friend std::ostream& operator<<(std::ostream& stream, Point& point);

	private:
		double _x;
		double _y;
	};
	
	class Vector
	{
	public:
		Vector();
		Vector(double a1, double a2);
		Vector(Point a, Point b);

		double XComponent() const;
		double YComponent() const;

		
		Vector FindPerpendicularVector() const;
		
		Vector operator+(const Vector& right) const;
		
		Vector operator-(const Vector& right) const;
		
		Vector operator*(double scalar) const;
		
		double operator*(const Vector& other) const;
		

	private:
		double _xComponent;
		double _yComponent;
	};
	
	class Line
	{
	public:
		Line();
		Line(Point point, Vector directionVector);

		double A() const;
		double B() const;
		double C() const;

		Point PointOnLine() const;
		Vector DirectionVector() const;

	private:
		double _A;
		double _B;
		double _C;

		Point _pointOnLine;
		Vector _directionVector;
	};
	
	class Circle
	{
	public:
		Circle(Point center, double radius);

		std::vector<Point> IntersectWith(Line line) const;

		Point Center() const;
		double Radius() const;

		friend std::ostream& operator<<(std::ostream& stream, Circle& circle);

	private:
		Point _center;
		double _radius;
	};
	

	Point Middle(Point left, Point right);
	double Distance(Point left, Point right);
}