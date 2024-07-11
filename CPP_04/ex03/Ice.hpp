#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
public:
	Ice();
	Ice(std::string const& type);
	Ice(const Ice& other);
	~Ice() {};
	Ice&	operator=(const Ice& other);
	Ice*	clone() const;
	void	use(ICharacter& target);
};


#endif