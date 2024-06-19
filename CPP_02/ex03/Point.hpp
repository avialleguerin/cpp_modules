#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <cmath>

class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	~Point();
	static float	crossProduct(Point p1, Point p2, Point point);
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);
int		ft_abs(int nb);
float	stof(char *point);

#endif