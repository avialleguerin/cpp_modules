#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

class AMateria
{
protected:

public:
	AMateria();
	AMateria(std::string const& type);
	AMateria(const AMateria& other);
	~AMateria();
	AMateria&	operator=(const AMateria& other);
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif