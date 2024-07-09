#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
	_brain->setBrain("Eat Bones");
	_brain->setBrain("Drink water");
	_brain->setBrain("Sleep");
	std::cout << "A Dog has been created" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
	*this = other;
	std::cout << "A copy Dog has been created" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	_type = other._type;
	_brain = new Brain(*other._brain);
	return(*this);
}

Dog::~Dog()
{
	std::cout << "A Dog has been destroy" << std::endl;
	delete _brain;
}

void	Dog::makeSound() const
{
	std::cout << "Wouaf Wouaf" << std::endl;
}

void	Dog::printBrain( void ) const
{
	_brain->printBrain();
}
