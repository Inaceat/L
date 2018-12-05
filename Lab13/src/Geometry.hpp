#pragma once


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


	class Circle
	{
		public:
		Circle(Point center, double radius);
		
		Point Center() const;
		double Radius() const;


	private:
		Point _center;
		double _radius;
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

		Vector DirectionalVector() const;


	private:
		double _A;
		double _B;
		double _C;
	};




	Point Middle(Point left, Point right);
}