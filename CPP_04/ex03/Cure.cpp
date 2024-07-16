#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "A materia of cure type has been created" << std::endl;
	_type = "cure";
}

Cure::Cure(Cure const& other)
{
	std::cout << "Copy materia of cure type has been created" << std::endl;
	*this = other;
}

Cure::~Cure()
{
	std::cout << "A materia of cure type has been destroyed" << std::endl;
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
