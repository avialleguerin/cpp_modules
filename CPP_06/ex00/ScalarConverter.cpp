#include "ScalarConverter.hpp"

bool	ScalarConverter::isChar(std::string& literal)
{
	int	i = 0;

	while (literal[i])
	{
		if (!isprint(literal[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ScalarConverter::isInt(std::string& literal)
{
	int	i = 0;

	while (literal[i])
	{
		if (!isdigit(literal[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ScalarConverter::isFloat(std::string& literal)
{
	int	i = 0;

	while (literal[i])
	{
		if (!isdigit(literal[i]))
		{
			if (literal[i] == 'f' && !literal[i + 1])
				return (true);
		}
		i++;
	}
	return (false);
}

bool	ScalarConverter::isDouble(std::string& literal)
{
	int	i = 0;

	while (literal[i])
	{
		if (!isdigit(literal[i]))
			return (false);
		i++;
	}
	return (true);
}

void	ScalarConverter::convertFromChar(int c)
{

}

void	ScalarConverter::convertFromInt(int i)
{

}

void	ScalarConverter::convertFromFloat(float f)
{

}

void	ScalarConverter::convertFromDouble(double d)
{

}

void	ScalarConverter::convert(std::string& literal)
{

}
