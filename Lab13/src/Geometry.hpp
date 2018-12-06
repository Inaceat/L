#pragma once

#include <cmath>
#include <utility>
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

		Vector FindNormal() const;
		double XComponent() const;
		double YComponent() const;


	private:
		double _a1;
		double _a2;
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


	private:
		Point _center;
		double _radius;
	};


	




	Point Middle(Point left, Point right);
	double Distance(Point left, Point right);
}
