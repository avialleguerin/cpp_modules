#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << RED << "Error: Invalid arguments." << RESET << std::endl;
		return 1;
	}
	try {
		RPN rpn;
		rpn.run(argv[1]);
	} catch (const std::exception &e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
	return 0;
}