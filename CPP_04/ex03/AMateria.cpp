#include "AMateria.hpp"

AMateria::AMateria()
{
	_type = NULL;
}

AMateria::AMateria(std::string const& type)
{
	_type = type;
}

AMateria::AMateria(const AMateria& other)
{
	*this = other;
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
