#include "Span.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>

int main(int ac, char** av) {
	(void)ac;
	try
	{
		std::cout << YELLOW << "Test with 5 elements:" << RESET << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.printNumbers();
		std::cout << "Shortest Span: " << GREEN << sp.shortestSpan() << RESET << std::endl;
		std::cout << "Longest Span: " << GREEN << sp.longestSpan() << RESET << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << YELLOW << "\nTest with range of numbers:" << RESET << std::endl;
		Span sp(10);
		std::vector<int> numbers;
		for (int i = 1; i < ac; i++)
			numbers.push_back(std::atoi(av[i]));
		sp.addNumberRange(numbers.begin(), numbers.end());
		sp.printNumbers();
		std::cout << "Shortest Span: " << GREEN << sp.shortestSpan() << RESET << std::endl;
		std::cout << "Longest Span: " << GREEN << sp.longestSpan() << RESET << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << YELLOW << "\nTest with 10000 numbers:" << RESET << std::endl;
		Span sp(10000);
		for (int i = 0; i < 10000; i++) {
			sp.addNumber(i);
		}
		sp.printNumbers();
		std::cout << "Shortest Span: " << GREEN << sp.shortestSpan() << RESET << std::endl;
		std::cout << "Longest Span: " << GREEN << sp.longestSpan() << RESET << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << YELLOW << "\nTest with a single number:" << RESET << std::endl;
		Span sp(1);
		sp.addNumber(42);
		sp.printNumbers();
		try {
			std::cout << BLUE << "Test shortest span:" << RESET << std::endl;
			sp.shortestSpan();
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		try {
			std::cout << BLUE << "Test longest span:" << RESET << std::endl;
			sp.longestSpan();
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << YELLOW << "\nTest with empty Span:" << RESET << std::endl;
		Span sp(0);
		sp.printNumbers();
		try {
			std::cout << BLUE << "Test shortest span:" << RESET << std::endl;
			sp.shortestSpan();
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		try {
			std::cout << BLUE << "Test longest span:" << RESET << std::endl;
			sp.longestSpan();
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << YELLOW << "\nTest with adding beyond capacity:" << RESET << std::endl;
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
			sp.printNumbers();
			try {
				sp.addNumber(3);
			} catch (std::exception& e) {
				std::cout << "Exception caught: " << e.what() << std::endl;
			}
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}