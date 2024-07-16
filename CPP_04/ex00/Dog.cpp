#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "A Dog has been created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	*this = other;
	std::cout << "A copy Dog has been created" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	_type = other._type;
	return(*this);
}

Dog::~Dog()
{
	std::cout << "A Dog has been destroyed" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Wouaf Wouaf" << std::endl;
}
