#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class cure
{
protected:

public:
	cure();
	cure(std::string const& type);
	~cure();
	cure&	operator=(const cure& other);
	cure* clone() const;
};


#endif