#include "Zombie.hpp"

void	Zombie::announce(void) const
{
	std::cout
	<< name 
	<< ": BraiiiiiiinnnzzzZ..." 
	<< std::endl;
}

Zombie::Zombie(void) : name("*NoName*")
{
	std::cout
	<< "An unnamed Zombie has been created"
	<< std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout
	<< "A Zombie named "
	<< this->name
	<< std::endl;
}

Zombie::~Zombie(void)
{
	std::cout
	<< "A zombie has been killed.\n"
	<< "Rest in Peace "
	<< name
	<< std::endl;
}