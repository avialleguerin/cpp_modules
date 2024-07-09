#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "A Brain has been created" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "A copy Brain has been created" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "A Brain has been destroyed" << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	return (*this);
}

void	Brain::setBrain( std::string think )
{
	int i = 0;
	while (this->_ideas[i][0] && i < 100)
		i++;
	if (i == 99)
		i = 0;
	this->_ideas[i] = think;
}

void	Brain::printBrain( void )
{
	int i = 0;
	while (this->_ideas[i][0] && i < 100)
		std::cout << this->_ideas[i++] << std::endl;
}
