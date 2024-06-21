#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap scavTrap1;
	ScavTrap scavTrap2(scavTrap1);

	scavTrap1 = ScavTrap("Scav1");
	scavTrap2 = ScavTrap("Scav2");

	while (scavTrap2.getHitPoints())
	{
		scavTrap1.attack(scavTrap2.getName());
		scavTrap2.takeDamage(scavTrap1.getAttackDamage());
		scavTrap2.beRepaired(4);
		std::cout << std::endl;
	}
	scavTrap2.guardGate();

	return 0;
}
