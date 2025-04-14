#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &rpn) { *this = rpn; }
RPN &RPN::operator=(const RPN &rpn) { _numbers = rpn._numbers; return *this; }
RPN::~RPN() {}

void RPN::run(std::string argv) {
	std::istringstream ss(argv);
	std::string token;

	while (ss >> token) {
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (_numbers.size() < 2)
				throw std::runtime_error("Too many operators");
			int b = _numbers.top();
			_numbers.pop();
			int a = _numbers.top();
			_numbers.pop();
			if (token == "+")
				_numbers.push(a + b);
			else if (token == "-")
				_numbers.push(a - b);
			else if (token == "*")
				_numbers.push(a * b);
			else {
				if (b == 0)
					throw std::runtime_error("Division by zero");
				_numbers.push(a / b);
			}
		} else {
			if (!isdigit(token[0]))
				throw std::runtime_error("Invalid operand");
			if (token.size() > 1)
				throw std::runtime_error("Number > 9");
			_numbers.push(std::atoi(token.c_str()));
		}
	}
	if (_numbers.size() != 1)
		throw std::runtime_error("Too many numbers");
	std::cout << _numbers.top() << std::endl;
}
