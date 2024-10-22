#include "Bureaucrat.hpp"

int	main()
{
	try {
		std::cout << "Test invalid grade (151):" << std::endl;
		Bureaucrat high("High", 151);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "\nTest invalid grade (0):" << std::endl; 
		Bureaucrat low("Low", 0);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "\nTest valid bureaucrat:" << std::endl;
		Bureaucrat normal("Normal", 75);
		std::cout << normal << std::endl;

		std::cout << "\nTest increment:" << std::endl;
		normal.incrementGrade();
		std::cout << normal << std::endl;

		std::cout << "\nTest decrement:" << std::endl;
		normal.decrementGrade();
		std::cout << normal << std::endl;

		std::cout << "\nTest copy constructor:" << std::endl;
		Bureaucrat copy("Copy", 100);
		std::cout << "Before: " << copy << std::endl;
		copy = normal;
		std::cout << "After: " << copy << std::endl;

	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
