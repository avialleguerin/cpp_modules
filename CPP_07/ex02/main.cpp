#include "Array.hpp"

int main(void)
{
	try {
		std::cout << YELLOW"\nEmpty array test:"RESET << std::endl;
		Array<int> empty;
		std::cout << "Empty array size: " << GREEN << empty.size() << RESET << std::endl;

		std::cout << YELLOW"\nParameterized array test:"RESET << std::endl;
		Array<int> numbers(5);
		std::cout << "Array size: " << GREEN << numbers.size() << RESET << std::endl;
		std::cout << "Default values:" << std::endl;
		for (unsigned int i = 0; i < numbers.size(); i++) {
			std::cout << GREEN << numbers[i] << RESET << " ";
		}
		std::cout << std::endl;

		std::cout << YELLOW"\nElement modification test:"RESET << std::endl;
		for (unsigned int i = 0; i < numbers.size(); i++) {
			numbers[i] = i * 2;
		}
		std::cout << "Modified values:" << std::endl;
		for (unsigned int i = 0; i < numbers.size(); i++) {
			std::cout << GREEN << numbers[i] << RESET << " ";
		}
		std::cout << std::endl;

		std::cout << YELLOW"\nCopy construction test:"RESET << std::endl;
		Array<int> copy(numbers);
		std::cout << "Copy values:" << std::endl;
		for (unsigned int i = 0; i < copy.size(); i++) {
			std::cout << GREEN << copy[i] << RESET << " ";
		}
		std::cout << std::endl;

		std::cout << YELLOW"\nIndependence of copies test:"RESET << std::endl;
		numbers[0] = 100;
		std::cout << "Original after modification: " << GREEN << numbers[0] << RESET << std::endl;
		std::cout << "Copy unmodified: " << GREEN << copy[0] << RESET << std::endl;

		std::cout << YELLOW"\nAssignment operator test:"RESET << std::endl;
		Array<int> assigned = numbers;
		std::cout << "Assigned values:" << std::endl;
		for (unsigned int i = 0; i < assigned.size(); i++) {
			std::cout << GREEN << assigned[i] << RESET << " ";
		}
		std::cout << std::endl;

		std::cout << YELLOW"\nOut of bounds exception test:"RESET << std::endl;
		std::cout << "Attempting to access out of bounds index..." << std::endl;
		std::cout << numbers[10] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << YELLOW"\nString array test:"RESET << std::endl;
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "!";
	for (unsigned int i = 0; i < strings.size(); i++) {
		std::cout << GREEN << strings[i] << RESET << " ";
	}
	std::cout << std::endl;

	return 0;
}