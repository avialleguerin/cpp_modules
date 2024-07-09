#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
protected:
	std::string	_ideas[100];
public:
	Brain();
	Brain(const Brain& other);
	~Brain();
	Brain&	operator=(const Brain& other);
	void	setBrain( std::string think );
	void	printBrain( void );
};

#endif