#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "A Wrong Cat has been created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "A copy Wrong Cat has been created" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	_type = other._type;
	return(*this);
}

WrongCat::~WrongCat()
{
	std::cout << "A Wrong Cat has been destroyed" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Miaou Miaou" << std::endl;

}
