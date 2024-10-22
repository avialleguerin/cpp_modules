#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>

class ScalarConverter
{
private:
	int	isChar(std::string literal);
	int	isInt(std::string literal);
	int	isFloat(std::string literal);
	int	isDouble(std::string literal);

	static void	convertFromChar(std::string literal);
	static void	convertFromInt(std::string literal);
	static void	convertFromFloat(std::string literal);
	static void	convertFromDouble(std::string literal);

public:
	static void	convert(std::string literal);
};

#endif /* SCALARCONVERTER */