#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "A default Cat has been created" << std::endl;
}

Cat::Cat(const Cat& other)
{
	*this = other;
	std::cout << "A copy Cat has been created" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	_type = other._type;
	return(*this);
}
