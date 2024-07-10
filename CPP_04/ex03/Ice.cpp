#include "Ice.hpp"

Ice::Ice()
{
	_type = "ice";
}

Ice::Ice(std::string const& type)
{
	_type = type;
}

Ice::Ice(Ice const& other)
{
	*this = other;
}

Ice&	Ice::operator=(const Ice& other)
{
	_type = other._type;
	return (*this);
}

Ice* Ice::clone() const
{
	return (new Ice(*this));
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* shoots an Ice bolt at " << target.getName() << " *" << std::endl;
}

