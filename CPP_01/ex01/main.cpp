#include "Zombie.hpp"

int main() {
	std::cout << "Time to create a horde of Zombies : " << std::endl;

	int N = 5;
	Zombie* horde = zombieHorde(N, "Hord");

	std::cout << "\n\nZombie Horde Announcements:" << std::endl;
	for (int i = 0; i < N; ++i)
		horde[i].announce();
	std::cout << "\n\nTime to destroy a horde of Zombies : " << std::endl;
	delete[] horde;
	return (0);
}