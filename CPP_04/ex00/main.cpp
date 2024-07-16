#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrong = new WrongCat();
	std::cout << animal->getType() << " " << std::endl;
	animal->makeSound();
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound();
	delete animal;
	delete dog;
	delete cat;
	delete wrong;
	return 0;
}
