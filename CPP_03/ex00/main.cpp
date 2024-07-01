#include "ClapTrap.hpp"

int	main()
{
	ClapTrap claptrap1;
	claptrap1.displayPoints();

	ClapTrap claptrap2("Bob");
	claptrap2.displayPoints();

	ClapTrap claptrap3(claptrap2);
	claptrap3.displayPoints();

	claptrap1.beRepaired(2);
	std::cout << std::endl;

	claptrap1.displayPoints();

	claptrap1.attack("Enemy");
	claptrap1.attack("Enemy");
	claptrap1.attack("Enemy");
	claptrap1.attack("Enemy");
	claptrap1.attack("Enemy");
	std::cout << std::endl;

	claptrap1.displayPoints();

	claptrap1.attack("Enemy");
	claptrap1.attack("Enemy");
	claptrap1.attack("Enemy");
	claptrap1.attack("Enemy");
	claptrap1.beRepaired(2);
	std::cout << std::endl;

	claptrap1.displayPoints();

	claptrap1.takeDamage(5);
	std::cout << std::endl;

	claptrap1.displayPoints();
	claptrap1.takeDamage(9);
	std::cout << std::endl;

	claptrap1.displayPoints();

	claptrap1.attack("Enemy");
	claptrap1.takeDamage(3);
	std::cout << std::endl;

	claptrap1.displayPoints();
	return 0;
}
