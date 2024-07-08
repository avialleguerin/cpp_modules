#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "wrongAnimal";
	std::cout << "A default WrongAnimal has been created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	*this = other;
	std::cout << "A copy WrongAnimal has been created" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	_type = other._type;
	return(*this);
}

WrongAnimal::~WrongAnimal() {}


std::string	WrongAnimal::getType() const
{
	return (_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "*WrongAnimal scream*" << std::endl;
}
