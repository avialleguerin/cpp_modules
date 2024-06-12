#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error wrong number of arguments" << std::endl;
		std::cerr << "Format expected: ./sed <filename> <old_word> <new_word >" <<std::endl;
		return 1;
	}
	std::ifstream infile(av[1]);
	
	if (!infile.is_open())
	{
		std::cerr << 'Error: ' << av[1] << ": infile can't be opened" << std::endl;
		return 1;
	}

	std::stringstream	buffer;
	buffer << infile.rdbuf();
	infile.close()


}
