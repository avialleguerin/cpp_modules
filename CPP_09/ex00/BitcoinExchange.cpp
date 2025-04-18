#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(int argc, char** argv) { checkArgs(argc, argv); }
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::checkArgs(int argc, char** argv)
{
	if (argc != 2) {
		throw BitcoinExchange::InvalidArgsException();
	}
	_path = argv[1];
}

bool BitcoinExchange::checkFormat(std::string line) 
{
	if (!isdigit(line[0]) || !isdigit(line[1]) || !isdigit(line[2]) || !isdigit(line[3])
	|| !isdigit(line[5]) || !isdigit(line[6]) || !isdigit(line[8]) || !isdigit(line[9]))
		return false;
	else if (line[4] != '-' || line[7] != '-')
		return false;
	else if (line[10] != ' ' || line[12] != ' ')
		return false;
	else if (line[11] != '|')
		return false;
	for (size_t i = 13; i < line.size(); i++)
	{
		if (!isdigit(line[i]) && line[i] != '.')
			return false;
	}
	return true;
}

bool BitcoinExchange::checkDate(const std::tm& date, std::string line) {
	if ((!checkFormat(line))
	|| (((date.tm_year % 4 == 0 && date.tm_mday > 29) || (date.tm_year % 4 != 0 && date.tm_mday > 28)) && date.tm_mon == 2)
	|| (date.tm_year < 2009 || date.tm_year > 2023 || date.tm_mday > 31 || date.tm_mon > 12)
	|| (((date.tm_mon < 7 && date.tm_mon % 2 == 0 ) || (date.tm_mon > 8 && date.tm_mon % 2 != 0)) && date.tm_mday > 30))
	{
		std::cout << RED << "Error: Bad input => " << line << RESET << std::endl;
		return false;
	}
	return true;
}

std::tm BitcoinExchange::parseDate(const std::string& date) {
	std::tm timeStruct = {};
	memset(&timeStruct, 0, sizeof(std::tm));
	strptime(date.c_str(), "%Y-%m-%d", &timeStruct);
	timeStruct.tm_year += 1900;
	timeStruct.tm_mon += 1;
	return timeStruct;
}

bool BitcoinExchange::checkRate(float rate) {
	if (rate < 0) {
		std::cout << RED << "Error: not a positive number." << RESET << std::endl;
		return false;
	}
	if (rate > 1000) {
		std::cout << RED << "Error: too large a number." << RESET << std::endl;
		return false;
	}
	return true;
}

const char* BitcoinExchange::InvalidDateException::what() const throw() {
	return "Error: invalid date.";
}

const char* BitcoinExchange::InvalidRateException::what() const throw() {
	return "Error: invalid rate.";
}


std::map<std::tm, float, tmCompare>::iterator BitcoinExchange::findClosestDate(const std::tm& date) {
	std::map<std::tm, float, tmCompare>::iterator it1 = _bd.find(date);
	if (it1 != _bd.end())
		return it1;
	std::map<std::tm, float, tmCompare>::iterator it2 = _bd.lower_bound(date);
	if (it2 == _bd.begin())
		return _bd.begin();
	return --it2;
}

void BitcoinExchange::storeData() {
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		throw std::runtime_error("Could not open file");
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string dateStr, rateStr;

		std::getline(ss, dateStr, ',');
		std::getline(ss, rateStr);
		std::tm date = parseDate(dateStr);
		float rate = std::atof(rateStr.c_str());
		_bd[date] = rate;
	}
	file.close();
}

void BitcoinExchange::extractFile()
{
	std::ifstream file(_path.c_str());
	if (!file.is_open())
		throw BitcoinExchange::InvalidFileException();
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		throw BitcoinExchange::InvalidHeaderException();
	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string dateStr, rateStr;
		std::getline(ss, dateStr, '|');
		std::getline(ss, rateStr);
		std::tm date = parseDate(dateStr);
		float rate = std::atof(rateStr.c_str());
		if (!checkRate(rate) || !checkDate(date, line))
		{
			// std::cout << "Error: Bad input => " << dateStr << (rate ? " | " : "") << (rate ? rate : "") << std::endl;
			continue;
		}
		else
		{
			std::map<std::tm, float, tmCompare>::iterator closestDate = findClosestDate(date);
			std::cout << dateStr << "=> " << rate << " = " << rate * closestDate->second << std::endl;
		}
	}
	file.close();
}

const char* BitcoinExchange::InvalidArgsException::what() const throw() {
	return "Format: ./btc <file>";
}

const char* BitcoinExchange::InvalidFileException::what() const throw() {
	return "Error: could not open file.";
}

const char* BitcoinExchange::InvalidHeaderException::what() const throw() {
	return "Error: invalid input file header.";
}

void BitcoinExchange::run() {
	storeData();
	extractFile();
}
