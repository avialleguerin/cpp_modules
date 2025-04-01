#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	(void)src;
	return *this;
}

bool ScalarConverter::isChar(const std::string& literal)
{
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		std::cout << "char: '" << literal << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(literal[0]) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(literal[0]) << std::endl;
		return true;
	}
	return false;
}

bool ScalarConverter::isNumber(const std::string& literal)
{
	size_t i = 0;
	int nbPoint = 0;
	if (literal[0] == '-')
		i++;
	while (i < literal.length()) {
		if (literal[i] == '.')
			nbPoint++;
		if (!std::isdigit(literal[i]) && literal[i] != '.' && !(i == literal.length() - 1 && literal[i] == 'f'))
			return false;
		i++;
	}
	if (nbPoint > 1)
		return false;
	return true;
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
		return true;
	}
	if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
		return true;
	}
	return false;
}

void ScalarConverter::convertToChar(std::string literal)
{
	std::cout << "char: ";
	try {
		double d = std::strtod(literal.c_str(), NULL);
		if (d < 0 || d > 127 || std::isnan(d))
			std::cout << "impossible" << std::endl;
		else if (d < 32 || d > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	} catch (...) {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::convertToInt(std::string literal)
{
	std::cout << "int: ";
	try {
		double d = std::strtod(literal.c_str(), NULL);
		if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || std::isnan(d))
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(d) << std::endl;
	} catch (...) {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::convertToFloat(std::string literal)
{
	std::cout << "float: ";
	try {
		double d = std::strtod(literal.c_str(), NULL);
		if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max() || std::isnan(d))
			std::cout << "impossible" << std::endl;
		else
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	} catch (...) {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::convertToDouble(std::string literal)
{
	std::cout << "double: ";
	try {
		double d = std::strtod(literal.c_str(), NULL);
		if (d < -std::numeric_limits<double>::max() || d > std::numeric_limits<double>::max() || std::isnan(d))
			std::cout << "impossible" << std::endl;
		else
			std::cout << d << std::endl;
	} catch (...) {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::convert(std::string literal)
{
	if (isChar(literal) || isPseudoLiteral(literal))
		return;
	if (!isNumber(literal))
	{
		std::cout << "Error: '" << literal << "' does not match to any of the following types: char, int, float, double" << std::endl;
		return;
	}
	convertToChar(literal);
	convertToInt(literal);
	convertToFloat(literal);
	convertToDouble(literal);
}
