#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "A default WrongCat has been created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "A copy WrongCat has been created" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	_type = other._type;
	return(*this);
}

WrongCat::~WrongCat()
{
	std::cout << "A WrongCat has been destroy" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "wrongMiaou wrongMiaou" << std::endl;

}
