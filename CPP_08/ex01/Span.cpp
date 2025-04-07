#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int N) : _size(N) {}

Span::~Span() {}

Span::Span(const Span& other) : _numbers(other._numbers), _size(other._size) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_numbers = other._numbers;
		_size = other._size;
	}
	return *this;
}

void Span::addNumber(int nb) {
	if (_numbers.size() == _size)
		throw Span::full();
	_numbers.push_back(nb);
}

void Span::addNumberRange(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd) {
	if (_numbers.size() == _size)
		throw Span::full();
	if (itBegin > itEnd)
		throw Span::InvalidRange();
	while (itBegin != itEnd) {
		if (_numbers.size() == _size)
			throw Span::full();
		addNumber(*itBegin);
		itBegin++;
	}
}

void Span::printNumbers() const {
	std::cout << "Numbers: ";
	if (_numbers.size() > 10)
	{
		for (size_t i = 0; i < 5; i++)
			std::cout << GREEN << _numbers[i] << ' ';
		std::cout << "... ";
		for (size_t i = _numbers.size() - 5; i < _numbers.size(); i++)
			std::cout << GREEN << _numbers[i] << ' ';
		std::cout << RESET << std::endl;
		return;
	}
	for (size_t i = 0; i < _numbers.size(); i++)
		std::cout << GREEN << _numbers[i] << ' ';
	std::cout << RESET << std::endl;
}

unsigned int Span::shortestSpan() {
	if (_numbers.size() < 2)
		throw Span::notEnoughNumbers();
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	unsigned int shortest = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
	{
		unsigned int current = sorted[i] - sorted[i - 1];
		if (current < shortest)
			shortest = current;
	}
	return shortest;
}

unsigned int Span::longestSpan() {
	if (_numbers.size() < 2)
		throw Span::notEnoughNumbers();
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	return sorted[sorted.size() - 1] - sorted[0];
}

const char* Span::notEnoughNumbers::what() const throw() {
	return RED "Not enough numbers in Span" RESET;
}


const char* Span::onlyOneNumber::what() const throw() {
	return RED "Not enough numbers in Span" RESET;
}

const char* Span::full::what() const throw() {
	return RED "Span is full" RESET;
}

const char* Span::InvalidRange::what() const throw() {
	return RED "Invalid range" RESET;
}