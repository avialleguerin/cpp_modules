#include "Bureaucrat.hpp"

int	main()
{
	try {
		std::cout << "try to construct bureaucrat(name : Nicky Minaj, grade : 151)" << std::endl;
		Bureaucrat a("Nicky Minaj", 151);
	} 
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	} 

	try {
		std::cout << "try to construct bureaucrat(name : David Guetta, grade : 0)" << std::endl;
		Bureaucrat b("David Guetta", 0);
	} 
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat c("Sia", 1);
	} 
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	Bureaucrat d1("Daft Punk", 150);
	Bureaucrat d2("Avicii", 112);
	d2 = d1;

	try {
		std::cout << "Before trying decrement : " << d1 << std::endl;
		d1.decrementGrade();
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: decrement failed :" << e.what() << std::endl;
	}

	d1.setGrade(1);
	try {
		std::cout << "Before trying increment : " << d1  << std::endl;
		d1.incrementGrade();
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: increment failed :" << e.what() << std::endl;
	} 
	std::cout << "After trying increment : " << d1 << std::endl;

	d1.setGrade(100);
	try {
		std::cout << "Before trying decrement : " << d1 << std::endl;
		d1.decrementGrade();
	} 
	catch (const std::exception& e) {
		std::cout << "Exception caught: decrement failed : " << e.what() << std::endl;
	} 
	std::cout << "After trying decrement : " << d1 << std::endl;

	try {
		std::cout << "Before trying increment : " << d1 << std::endl;
		d1.incrementGrade();
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: increment failed : " << e.what() << std::endl;
	} 
	std::cout << "After trying increment : " << d1 << std::endl;

	return 0;
}
