#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "A materia of ice type has been created" << std::endl;
	_type = "Ice";
}

Ice::Ice(Ice const& other)
{
	std::cout << "Copy materia of ice type has been created" << std::endl;
	*this = other;
}

Ice::~Ice()
{
	std::cout << "A materia of ice type has been destroyed" << std::endl;
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

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an Ice bolt at " << target.getName() << " *" << std::endl;
}

