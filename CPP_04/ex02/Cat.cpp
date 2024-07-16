#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain();
	_brain->setBrain("Eat");
	_brain->setBrain("Drink milk");
	_brain->setBrain("Sleep");
	std::cout << "A Cat has been created" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	*this = other;
	std::cout << "A copy Cat has been created" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	_type = other._type;
	_brain = new Brain(*other._brain);
	return(*this);
}

Cat::~Cat()
{
	std::cout << "A Cat has been destroyed" << std::endl;
	delete _brain;
}

void	Cat::makeSound() const
{
	std::cout << "Miaou Miaou" << std::endl;

}

void	Cat::printBrain( void )
{
	_brain->printBrain();
}
