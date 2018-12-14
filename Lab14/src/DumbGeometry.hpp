#pragma once

#include <list>


namespace dumb_geometry
{
	class IAreaProvider
	{
	public:
		virtual double Area() = 0;

		virtual ~IAreaProvider() = default;
	};


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


	class Triangle : public IAreaProvider
	{
	public:
		Triangle(Point a, Point b, Point c);


		std::list<Point> GetPoints() const;
		Point A() const;
		Point B() const;
		Point C() const;

		double Area() override;


	private:
		Point _a;
		Point _b;
		Point _c;
	};


	class Trapeze : public IAreaProvider
	{
	public:
		//Trapeze ABCD should have BC and AD sides parallel. If wrong points are passed, degenerate trapeze in Point(0, 0) is created.
		Trapeze(Point a, Point b, Point c, Point d);

		Point A() const;
		Point B() const;
		Point C() const;
		Point D() const;

		double Area() override;


	private:
		Point _a;
		Point _b;
		Point _c;
		Point _d;
	};



	double Distance(Point left, Point right);
}
