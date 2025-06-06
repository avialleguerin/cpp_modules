#include "easyfind.hpp"

int main()
{
	std::cout << YELLOW << "Test vector:" << RESET << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::cout << "Content of the vector: ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << GREEN << vec[i] << ' ';
	std::cout << RESET << std::endl;
	std::cout << "Search 3: ";
	easyfind(vec, 3);
	std::cout << "Search 6: ";
	easyfind(vec, 6);

	std::cout << YELLOW << "\nTest list:" << RESET << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);

	std::cout << "Search 20: ";
	easyfind(lst, 20);
	std::cout << "Search 25: ";
	easyfind(lst, 25);

	return 0;
}