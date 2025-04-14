#include "Zombie.hpp"

int	main(void)
{
	std::cout << "Creating a Zombie : " << std::endl;
	Zombie z1;
	z1.announce();

	std::cout << "\n\nCreating a named Zombie : " << std::endl;
	Zombie z2("Robert");
	z2.announce();

	std::cout << "\n\nAllocate a new Zombie : " << std::endl;
	Zombie* z3;
	try {
		z3 = newZombie("R2D2");
	}
	catch (const std::bad_alloc& err)
	{
		std::cout << "Allocation with newZombie failed :" << err.what() << std::endl;
		return (1);
	}
	z3->announce();
	delete z3;
	std::cout << "\n\n";
	return (0);
}
