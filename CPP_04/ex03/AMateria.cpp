#include "AMateria.hpp"

AMateria::AMateria(): _type("") {}

AMateria::AMateria(std::string const& type)
{
	std::cout << "materia of " << _type << " type has been created" << std::endl;
	_type = type;
}

AMateria::AMateria(const AMateria& other)
{
	std::cout << "Copy materia has been created" << std::endl;
	*this = other;
}

AMateria::~AMateria()
{
	std::cout << "A materia has been destroyed" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	_type = other._type;
	return (*this);
}

std::string const& AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
