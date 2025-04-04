#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

# define GREEN	"\033[0;32m"
# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define RESET	"\033[0m"

template <typename T>
class MutantStack : public std::stack<T, std::deque<T>>
{
	public:
		typedef std::stack<T, std::deque<T>> stack_type;
		typedef typename std::deque<T>::iterator iterator;

		MutantStack() {}
		MutantStack(const MutantStack& other) : stack_type(other) {}
		MutantStack& operator=(const MutantStack& other) { stack_type::operator=(other); return *this; }
		~MutantStack() {}

		iterator begin() { return stack_type::c.begin(); }
		iterator end() { return stack_type::c.end(); }
};

#endif /* MUTANTSTACK_HPP */
