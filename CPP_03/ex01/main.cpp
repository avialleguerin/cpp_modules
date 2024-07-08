#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	clapTrap("Clap");
	ScavTrap	scavTrap("Scav");

	scavTrap.displayPoints();
	clapTrap.displayPoints();
	
	
	for (int i = 0; i < 5; i++)
		scavTrap.attack("Scav");
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		clapTrap.takeDamage(scavTrap.getAttackDamage());
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		clapTrap.beRepaired(1);

	scavTrap.displayPoints();
	clapTrap.displayPoints();
	scavTrap.guardGate();

	return (0);
}
