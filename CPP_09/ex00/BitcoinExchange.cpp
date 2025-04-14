#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(int argc, char** argv) { checkArgs(argc, argv); }
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::checkArgs(int argc, char** argv) {
	if (argc != 2) {
		throw BitcoinExchange::InvalidArgsException();
	}
	_path = argv[1];
}

bool BitcoinExchange::checkDate(const std::tm& date) {

	if (date.tm_year < 2009 || date.tm_year > 2023 || date.tm_mday > 31 || date.tm_mon > 11) {
		std::cout << RED << "Error: Bad input => " << std::setw(4) << std::setfill('0') << date.tm_year 
				<< "-" << std::setw(2) << std::setfill('0') << date.tm_mon
				<< "-" << std::setw(2) << std::setfill('0') << date.tm_mday << RESET << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::checkRate(float rate) {
	if (rate < 0) {
		std::cout << RED << "Error: not a positive number." << RESET << std::endl;
		return false;
	}
	if (rate > 1000) {
		std::cout << RED << "Error: too large number." << RESET << std::endl;
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

std::tm BitcoinExchange::parseDate(const std::string& date) {
	std::tm timeStruct = {};
	::memset(&timeStruct, 0, sizeof(std::tm));
	if (sscanf(date.c_str(), "%d-%d-%d", 
		&timeStruct.tm_year, &timeStruct.tm_mon, &timeStruct.tm_mday) != 3) {
		throw BitcoinExchange::InvalidDateException();
	}
	return timeStruct;
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
		if (!checkDate(date) || !checkRate(rate))
			continue;
		else
		{
			std::map<std::tm, float, tmCompare>::iterator closestDate = findClosestDate(date);
			std::cout << std::setw(4) << std::setfill('0') << date.tm_year 
				<< "-" << std::setw(2) << std::setfill('0') << date.tm_mon
				<< "-" << std::setw(2) << std::setfill('0') << date.tm_mday
				<< " => " << rate << " = " << rate * closestDate->second << std::endl;
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
