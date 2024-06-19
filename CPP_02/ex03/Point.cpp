#include "Point.hpp"

Point::Point(): _x(0), _y(0){}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point::~Point() {}

float	Point::crossProduct(Point p1, Point p2, Point point)
{
	return (p2._x.toFloat() - p1._x.toFloat()) * (point._y.toFloat() - p1._y.toFloat()) -
			(p2._y.toFloat() - p1._y.toFloat()) * (point._x.toFloat() - p1._x.toFloat());
}

