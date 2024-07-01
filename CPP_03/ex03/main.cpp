#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap diamondTrap1;
	DiamondTrap diamondTrap2(diamondTrap1);
	ScavTrap scavTrap3;
	ClapTrap clapTrap4(scavTrap3);

	diamondTrap2 = DiamondTrap("Diamond");
	clapTrap4 = FragTrap("Fraggy");

	while (clapTrap4.getHitPoints())
	{
		diamondTrap2.attack(clapTrap4.getName());
		//clapTrap4.takeDamage(diamondTrap2.getAttackDamage());
		//clapTrap4.beRepaired(diamondTrap2.getAttackDamage() / 3);
		std::cout << std::endl;
	}

	diamondTrap2.whoAmI();

	return 0;
}
