#include "templates.hpp"

int main() {
	// Test avec un tableau d'entiers
	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << "Table of int: ";
	iter(intArray, 5, print<int>);
	std::cout << std::endl;

	// Test avec un tableau de chaînes
	std::string stringArray[] = {"Hello", "world", "!"};
	std::cout << "Table of string: ";
	iter(stringArray, 3, print<std::string>);
	std::cout << std::endl;

	// Test avec un tableau de doubles
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::cout << "Table of double: ";
	iter(doubleArray, 5, print<double>);
	std::cout << std::endl;

	return 0;
}