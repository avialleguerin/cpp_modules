#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
protected:
	std::string	_type;
public:
	Brain();
	Brain(const Brain& other);
	virtual ~Brain();
	Brain&			operator=(const Brain& other);
};

#endif