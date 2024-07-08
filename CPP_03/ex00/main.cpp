#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	clapTrap1("Clap1");
	ClapTrap	clapTrap2;

	clapTrap1.displayPoints();
	clapTrap2.displayPoints();
	
	
	for (int i = 0; i < 5; i++)
		clapTrap1.attack("*NoName*");
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		clapTrap2.takeDamage(0);
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		clapTrap2.beRepaired(1);
	std::cout << std::endl;

	clapTrap1.displayPoints();
	clapTrap2.displayPoints();
	
	return (0);
}
