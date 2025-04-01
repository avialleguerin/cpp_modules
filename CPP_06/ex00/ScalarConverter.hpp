#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <cmath>
# include <cstdlib>
# include <limits>
# include <iomanip>

class ScalarConverter 
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter(void);
		ScalarConverter& operator=(const ScalarConverter& src);

		static bool isChar(const std::string& literal);
		static bool isNumber(const std::string& literal);
		static bool isPseudoLiteral(const std::string& literal);
		static void convertToChar(std::string literal);
		static void convertToInt(std::string literal);
		static void convertToFloat(std::string literal);
		static void convertToDouble(std::string literal);
	public:
		static void convert(std::string literal);
};

#endif /* SCALARCONVERTER_HPP */