#include "Point.hpp"
#include "Fixed.hpp"

int	ft_abs(int nb)
{
	return (nb < 0 ? -nb : nb);
}

int	ft_pow(int base, int exponent)
{
	if (exponent == 0)
		return 1;
	int	result = 1.0;
	int	tmp = base;
	int	abs_exponent= ft_abs(exponent);

	while (abs_exponent > 0)
	{
		if (abs_exponent % 2 == 1)
			result *= tmp;
		tmp *= tmp;
		abs_exponent /= 2;
	}
	return (exponent < 0) ? 1 / result : result;

}

float	stof(char *point)
{
	std::string	str(point);
	int	index = str.find('.');
	int	len = str.length();

	float	nb = 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] == '.') continue;
		nb *= 10;
		nb += int(str[i] - 48);
	}

	nb /= ft_pow(10, len - 1 - index);
	return (nb);
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	cross1 = Point::crossProduct(a, b, point);
	float	cross2 = Point::crossProduct(b, c, point);
	float	cross3 = Point::crossProduct(c, a, point);

	bool hasNeg = (cross1 < 0) || (cross2 < 0) || (cross3 < 0);
	bool hasPos = (cross1 > 0) || (cross2 > 0) || (cross3 > 0);

	return !(hasNeg && hasPos) && cross1 != 0 && cross2 != 0 && cross3 != 0;;
}
