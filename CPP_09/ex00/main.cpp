#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try {
		BitcoinExchange btc(argc, argv);
		btc.run();
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return 0;
}
