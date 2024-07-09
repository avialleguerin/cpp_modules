#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	_type = "AAnimal";
	std::cout << "An AAnimal has been created" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
	*this = other;
	std::cout << "A copy AAnimal has been created" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	_type = other._type;
	return(*this);
}

AAnimal::~AAnimal()
{
	std::cout << "An AAnimal has been destroy" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (_type);
}

void	AAnimal::makeSound() const
{
	std::cout << "*AAnimal scream*" << std::endl;
}
