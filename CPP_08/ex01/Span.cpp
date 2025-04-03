#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int N) : _size(N) {}

Span::~Span() {}

void Span::addNumber(int nb) {
	if (_numbers.size() == _size)
		throw Span::fullException();
	_numbers.push_back(nb);
}

unsigned int Span::shortestSpan() {
	if (_numbers.size() < 2)
		throw Span::emptyException();
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
		throw Span::emptyException();
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	return sorted[sorted.size() - 1] - sorted[0];
}