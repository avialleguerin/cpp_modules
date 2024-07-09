#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "A Cat has been created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	*this = other;
	std::cout << "A copy Cat has been created" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	_type = other._type;
	return(*this);
}

Cat::~Cat() {}

void	Cat::makeSound() const
{
	std::cout << "Miaou Miaou" << std::endl;

}
