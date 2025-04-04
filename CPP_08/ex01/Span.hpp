#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

# define GREEN	"\033[0;32m"
# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
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
		void			addNumberRange(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			printNumbers() const;
	
	class notEnoughNumbers : public std::exception {
		public:
			const char * what() const throw();
	};
	class onlyOneNumber : public std::exception {
		public:
			const char * what() const throw();
	};
	class full : public std::exception {
		public:
			const char * what() const throw();
	};
	class InvalidRange: public std::exception {
		public:
			const char * what() const throw();
	};
};

#endif /* SPAN_HPP */