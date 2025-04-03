#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

# define GREEN	"\033[0;32m"
# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define RESET	"\033[0m"

class Span {
	private:
		std::vector<int> _numbers;
		unsigned int _size;
	public:
		Span();
		Span(unsigned int N);
		~Span();
		void			addNumber(int nb);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
	
	class emptyException : public std::exception {
		public:
			const char * what() const throw() { return "Span is empty"; }
	};
	class onlyOneNumberException : public std::exception {
		public:
			const char * what() const throw() { return "Span has only one number"; }
	};
	class fullException : public std::exception {
		public:
			const char * what() const throw() { return "Span is full"; }
	};
};

#endif /* SPAN_HPP */