#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

# define GREEN	"\033[0;32m"
# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define RESET	"\033[0m"

template <typename T>
typename T::iterator easyfind(T container, int val)
{
	typename T::iterator it = std::find(container.begin(), container.end(), val);
	if (it != container.end())
		std::cout << GREEN << "Value found" << RESET << std::endl;
	else
		std::cout << RED << "Value not found" << RESET << std::endl;
	return it;
}

#endif /* EASYFIND_HPP */