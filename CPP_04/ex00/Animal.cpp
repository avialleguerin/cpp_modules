#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "A default Animal has been created" << std::endl;
}

Animal::Animal(const Animal& other)
{
	*this = other;
	std::cout << "A copy Animal has been created" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	_type = other._type;
	return(*this);
}
