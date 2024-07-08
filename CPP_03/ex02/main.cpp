#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap	fragTrap("Frag");
	ScavTrap	scavTrap("Scav");

	fragTrap.displayPoints();
	scavTrap.displayPoints();
	fragTrap.highFivesGuys();
	scavTrap.guardGate();
	return (0);
}
