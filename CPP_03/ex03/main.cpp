#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diamondTrap("Diamond");

	std::cout << std::endl;

	diamondTrap.whoAmI();
	diamondTrap.highFivesGuys();
	diamondTrap.guardGate();

	std::cout << std::endl;

	return (0);
}
