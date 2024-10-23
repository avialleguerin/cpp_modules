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
	bool	isChar(std::string& literal);
	bool	isInt(std::string& literal);
	bool	isFloat(std::string& literal);
	bool	isDouble(std::string& literal);

	static void	convertFromChar(int c);
	static void	convertFromInt(int i);
	static void	convertFromFloat(float f);
	static void	convertFromDouble(double d);

public:
	static void	convert(std::string& literal);
};

#endif /* SCALARCONVERTER */