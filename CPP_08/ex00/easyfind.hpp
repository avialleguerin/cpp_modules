#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>

# define GREEN	"\033[0;32m"
# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define RESET	"\033[0m"

template <typename T>
typename T::iterator easyfind(T container, int val)
{
	typename T::iterator it = container.begin();
	typename T::iterator end = container.end();
	while (it != end)
	{
		if (*it == val)
			return it;
		++it;
	}
	std::cout << RED << "Value not found" << RESET << std::endl;
	return end;
}

#endif /* EASYFIND_HPP */