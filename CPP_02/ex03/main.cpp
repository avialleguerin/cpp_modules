#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>




int main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "Error: wrong number of arguments.";
		std::cout << "Format: ./bsp <x> <y>";
		return 1;
	}

	Point	a(1.5, 2.5);
	Point	b(4, 3);
	Point	c(6, 7.2);

	Point	point(stof(av[1]), stof(av[2]));

	if (bsp(a, b, c, point))
	{
		std::cout << "Le point de coordonnees {" << av[1] << ", " << av[2] << "} est dans le triangle." << std::endl;
	}
	else
		std::cout << "Le point de coordonnees {" << av[1] << ", " << av[2] << "} n'est pas dans le triangle." << std::endl;
}
