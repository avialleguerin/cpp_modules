#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class ice
{
protected:

public:
	ice();
	ice(std::string const& type);
	~ice();
	ice&	operator=(const ice& other);
	ice* clone() const;
};


#endif