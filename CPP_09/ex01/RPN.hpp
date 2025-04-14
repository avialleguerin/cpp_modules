#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <exception>
#include <stdlib.h>
#include <cctype>

#define RED		"\033[0;31m"
#define RESET	"\033[0m"

class RPN
{
	private:
		std::stack<int> _numbers;
	public:
		RPN();
		RPN(const RPN &rpn);
		RPN &operator=(const RPN &rpn);
		~RPN();
		void run(std::string argv);
};

#endif