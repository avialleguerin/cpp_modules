#include "Serializer.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Use: ./serialize <arg>" << std::endl;
		return 1;
	}
	Data data(argv[1]);
	std::cout << "BEFORE SERIALIZE:" << std::endl;
	std::cout << data << std::endl;

	std::cout << "\nSERIALIZATION : " << Serializer::serialize(&data) << std::endl;

	data = *Serializer::deserialize(Serializer::serialize(&data));
	std::cout << "\nDESERIALIZATION: " << std::endl;
	std::cout << data << std::endl;
}
