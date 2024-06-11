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
		std::cerr << "Allocation with newZombie failed :" << err.what() << std::endl;
		return (1);
	}
	z3->announce();
	delete z3;

	std::cout << "\n\nShow error when allocation didn't work : " << std::endl;
	Zombie* z4;
	try {
		z4 = (Zombie *)new int[1000000000000];
	}
	catch (const std::bad_alloc& err)
	{
		std::cerr << "Allocation with newZombie failed :" << err.what() << std::endl;
	}
	std::cout << "\n\n";
	return (0);
}
