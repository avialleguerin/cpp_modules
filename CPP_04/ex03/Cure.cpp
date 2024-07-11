#include "Cure.hpp"

Cure::Cure()
{
	_type = "cure";
}

Cure::Cure(std::string const& type)
{
	_type = type;
}
Cure::Cure(Cure const& other)
{
	*this = other;
}

Cure&	Cure::operator=(const Cure& other)
{
	_type = other._type;
	return (*this);
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
