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
	if (_numbers.size() == 2)
		return _numbers[0] - _numbers[1];
	std::sort(_numbers.begin(), _numbers.end());
	unsigned int shortest = _numbers[1] - _numbers[0];
	for (size_t i = 2; i < _numbers.size(); i++)
		shortest = std::min(shortest, _numbers[i] - _numbers[i - 1]);
	return shortest;
}