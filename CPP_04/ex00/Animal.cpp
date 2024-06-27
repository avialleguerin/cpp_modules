#include "Animal.hpp"

Animal::Animal()
{
	_type = "Animal";
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

Animal::~Animal() {}


std::string	Animal::getType() const
{
	return (_type);
}

void	Animal::makeSound() const
{
	std::cout << "*Animal scream*" << std::endl;
}
