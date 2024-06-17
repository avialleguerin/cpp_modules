#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac > 2)
		return (std::cout << "Error: too many arguments." << std::endl), 1;
	if (av[1])
		harl.complain(av[1]);
	return 0;
}