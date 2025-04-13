#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	try {
	PmergeMe p;
	p.merge(argc, argv);
	return 0;
	} catch (const std::exception &e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		return 1;
	}
}