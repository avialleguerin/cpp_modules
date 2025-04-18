#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
#include <map>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"
#define YELLOW	"\033[0;33m"
#define RESET	"\033[0m"

struct tmCompare {
	bool operator()(const std::tm& lhs, const std::tm& rhs) const {
		if (lhs.tm_year != rhs.tm_year)
			return lhs.tm_year < rhs.tm_year;
		if (lhs.tm_mon != rhs.tm_mon)
			return lhs.tm_mon < rhs.tm_mon;
		return lhs.tm_mday < rhs.tm_mday;
	}
};

class BitcoinExchange
{
	private:
		std::string _path;
		std::map<std::tm, float, tmCompare> _bd;
		BitcoinExchange();
	public:
		BitcoinExchange(int argc, char** argv);
		~BitcoinExchange();

		void checkArgs(int argc, char** argv);
		bool checkFormat(std::string line);
		bool checkRate(float rate);
		bool checkDate(const std::tm& date, std::string line);
		std::tm parseDate(const std::string& date);
		void extractFile();
		void storeData();
		std::map<std::tm, float, tmCompare>::iterator findClosestDate(const std::tm& date);
		void run();

	class InvalidFileException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class InvalidArgsException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class InvalidDateException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class InvalidRateException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class InvalidHeaderException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};


#endif