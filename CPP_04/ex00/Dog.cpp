#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "A default Dog has been created" << std::endl;
}

Dog::Dog(const Dog& other)
{
	*this = other;
	std::cout << "A copy Dog has been created" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	_type = other._type;
	return(*this);
}
